#include "nursery.h"
#include "./ui_nursery.h"
#include "../../src/Nursery/Nursery.h"
#include "../../src/Customer/Customer.h"
#include "../../src/Customer/CustomerCreator.h"
#include "../../src/Customer/Browse.h"
#include "../../src/Customer/Enquire.h"
#include "../../src/Customer/Purchasing.h"
#include "../../src/Greenhouse/Plant.h"
#include "../../src/Greenhouse/PlantDecorator.h"
#include "../../src/Greenhouse/GiftWrap.h"
#include "../../src/Greenhouse/Pot.h"
#include "../../src/Greenhouse/SpecialArrangement.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <QGraphicsTextItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsRectItem>
#include <QGraphicsSceneHoverEvent>
#include <QScrollArea>
#include <QGraphicsProxyWidget>
#include <QWidget>
#include <cmath>
#include <random>
#include <map>

// Custom thinking bubble class that expands on hover
class ThinkingBubble : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
private:
    QGraphicsEllipseItem *smallBubble1;
    QGraphicsEllipseItem *smallBubble2;
    QGraphicsEllipseItem *mainBubble;
    QGraphicsRectItem *infoBox;
    QGraphicsTextItem *infoText;
    bool expanded;
    NurseryWindow *window;
    Customer *customer;

public:
    ThinkingBubble(NurseryWindow *win, Customer *cust, QGraphicsItem *parent = nullptr)
        : QGraphicsItemGroup(parent), expanded(false), window(win), customer(cust)
    {
        // Don't accept hover on bubble - we'll handle it on the customer dot
        setAcceptHoverEvents(false);

        // Create small thought bubbles (the "..." effect)
        smallBubble1 = new QGraphicsEllipseItem(0, 0, 4, 4);
        smallBubble1->setBrush(QBrush(Qt::white));
        smallBubble1->setPen(QPen(Qt::black, 1));
        addToGroup(smallBubble1);

        smallBubble2 = new QGraphicsEllipseItem(6, -4, 6, 6);
        smallBubble2->setBrush(QBrush(Qt::white));
        smallBubble2->setPen(QPen(Qt::black, 1));
        addToGroup(smallBubble2);

        // Main thinking bubble
        mainBubble = new QGraphicsEllipseItem(12, -12, 15, 15);
        mainBubble->setBrush(QBrush(Qt::white));
        mainBubble->setPen(QPen(Qt::black, 1.5));
        addToGroup(mainBubble);

        // Info box (initially hidden)
        infoBox = new QGraphicsRectItem(0, 0, 200, 100);
        infoBox->setBrush(QBrush(QColor(255, 255, 220, 230)));
        infoBox->setPen(QPen(Qt::black, 2));
        infoBox->setPos(30, -120);
        infoBox->setVisible(false);
        addToGroup(infoBox);

        // Info text (initially hidden)
        infoText = new QGraphicsTextItem();
        infoText->setDefaultTextColor(Qt::black);
        infoText->setPos(35, -115);
        infoText->setVisible(false);
        infoText->setTextWidth(190);
        addToGroup(infoText);
    }

    void updateInfo(const QString &info)
    {
        infoText->setPlainText(info);

        // Adjust box size based on text
        QRectF textRect = infoText->boundingRect();
        qreal width = qMax(200.0, textRect.width() + 10);
        qreal height = qMax(100.0, textRect.height() + 10);

        infoBox->setRect(0, 0, width, height);
        infoBox->setPos(30, -height - 20);
        infoText->setPos(35, -height - 15);
    }

public:
    void showInfo()
    {
        qDebug() << "ThinkingBubble::showInfo() called";
        qDebug() << "  window:" << window << "isSimulationRunning:" << (window ? window->isSimulationRunning() : -1);

        if (window && !window->isSimulationRunning())
        {
            expanded = true;
            // Always refresh info to show current state
            QString info = window->getCustomerInfo(customer);
            qDebug() << "  Got customer info, length:" << info.length();
            qDebug() << "  Info content:" << info;
            updateInfo(info);
            infoBox->setVisible(true);
            infoText->setVisible(true);
            qDebug() << "  Info box and text set to visible";
        }
        else
        {
            qDebug() << "  Cannot show info - simulation is running or window is null";
        }
    }

    void refreshInfo()
    {
        // Update info if bubble is currently expanded
        if (expanded && window && !window->isSimulationRunning())
        {
            QString info = window->getCustomerInfo(customer);
            updateInfo(info);
        }
    }

    void hideInfo()
    {
        expanded = false;
        infoBox->setVisible(false);
        infoText->setVisible(false);
    }
};

// Custom ellipse that shows bubble info on hover
class CustomerDot : public QGraphicsEllipseItem
{
private:
    ThinkingBubble *bubble;

public:
    CustomerDot(qreal x, qreal y, qreal w, qreal h, ThinkingBubble *b)
        : QGraphicsEllipseItem(x, y, w, h), bubble(b)
    {
        setAcceptHoverEvents(true);
    }

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override
    {
        if (bubble)
        {
            bubble->showInfo();
        }
        QGraphicsEllipseItem::hoverEnterEvent(event);
    }

    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override
    {
        if (bubble)
        {
            bubble->hideInfo();
        }
        QGraphicsEllipseItem::hoverLeaveEvent(event);
    }
};

#include "nursery.moc"

NurseryWindow::NurseryWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::NurseryWindow),
      scene(nullptr),
      view(nullptr),
      simulationTimer(nullptr),
      customerSpawnTimer(nullptr),
      nurseryBackend(nullptr),
      isRunning(false),
      rng(std::random_device{}())
{
    qDebug() << "Initializing Nursery Window...";

    ui->setupUi(this);
    setWindowTitle("Chaotic Plants Nursery Simulation");
    resize(1000, 700);

    setupUI();
    setupScene();

    // Initialize backend
    qDebug() << "Creating backend nursery...";
    nurseryBackend = new Nursery(nullptr);
    qDebug() << "Backend nursery created successfully";

    // Setup timers
    simulationTimer = new QTimer(this);
    connect(simulationTimer, &QTimer::timeout, this, &NurseryWindow::updateSimulation);

    customerSpawnTimer = new QTimer(this);
    connect(customerSpawnTimer, &QTimer::timeout, this, &NurseryWindow::addCustomer);

    qDebug() << "Nursery Window initialized successfully!";
}

NurseryWindow::~NurseryWindow()
{
    // Clean up customer visuals
    for (auto &cv : customerVisuals)
    {
        delete cv.dot;
        if (cv.bubble)
        {
            delete cv.bubble;
        }
    }
    customerVisuals.clear();

    delete nurseryBackend;
    delete scene;
    delete ui;
}

void NurseryWindow::setupUI()
{
    // Create central widget and main layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Create control panel
    QHBoxLayout *controlLayout = new QHBoxLayout();

    startBtn = new QPushButton("Start Simulation", this);
    pauseBtn = new QPushButton("Pause", this);
    resetBtn = new QPushButton("Reset", this);
    addCustomerBtn = new QPushButton("Add Customer", this);

    connect(startBtn, &QPushButton::clicked, this, &NurseryWindow::startSimulation);
    connect(pauseBtn, &QPushButton::clicked, this, &NurseryWindow::pauseSimulation);
    connect(resetBtn, &QPushButton::clicked, this, &NurseryWindow::resetSimulation);
    connect(addCustomerBtn, &QPushButton::clicked, this, &NurseryWindow::addCustomer);

    pauseBtn->setEnabled(false);

    controlLayout->addWidget(startBtn);
    controlLayout->addWidget(pauseBtn);
    controlLayout->addWidget(resetBtn);
    controlLayout->addWidget(addCustomerBtn);
    controlLayout->addStretch();

    // Create status panel
    QHBoxLayout *statusLayout = new QHBoxLayout();

    seasonLabel = new QLabel("Season: Spring", this);
    customerCountLabel = new QLabel("Customers: 0", this);
    statusLabel = new QLabel("Status: Ready", this);

    seasonLabel->setStyleSheet("font-weight: bold; font-size: 14pt; color: #2E7D32;");
    customerCountLabel->setStyleSheet("font-weight: bold; font-size: 12pt;");
    statusLabel->setStyleSheet("font-weight: bold; font-size: 12pt;");

    statusLayout->addWidget(customerCountLabel);
    statusLayout->addWidget(statusLabel);
    statusLayout->addStretch();
    statusLayout->addWidget(seasonLabel);

    // Add layouts to main layout
    mainLayout->addLayout(controlLayout);
    mainLayout->addLayout(statusLayout);

    setCentralWidget(centralWidget);
}

void NurseryWindow::setupScene()
{
    // Create graphics scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, SCENE_WIDTH, SCENE_HEIGHT);
    scene->setBackgroundBrush(QBrush(QColor(240, 255, 240))); // Light green background

    // Create graphics view
    view = new QGraphicsView(scene, this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setMinimumSize(SCENE_WIDTH + 20, SCENE_HEIGHT + 20);

    // Add view to central widget layout
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(centralWidget()->layout());
    if (layout)
    {
        layout->addWidget(view);
    }

    // Add some visual elements to represent the nursery layout
    // Draw entrance area
    QGraphicsRectItem *entrance = scene->addRect(10, SCENE_HEIGHT - 60, 100, 50,
                                                 QPen(Qt::darkGreen, 2),
                                                 QBrush(QColor(144, 238, 144)));
    QGraphicsTextItem *entranceLabel = scene->addText("Entrance");
    entranceLabel->setPos(25, SCENE_HEIGHT - 50);

    // Draw info desk area (400 pixels above entrance)
    QGraphicsRectItem *infoDesk = scene->addRect(10, SCENE_HEIGHT - 460, 100, 60,
                                                 QPen(Qt::darkBlue, 2),
                                                 QBrush(QColor(173, 216, 230)));
    QGraphicsTextItem *infoDeskLabel = scene->addText("Info Desk");
    infoDeskLabel->setPos(25, SCENE_HEIGHT - 445);

    // Draw checkout area
    QGraphicsRectItem *checkout = scene->addRect(SCENE_WIDTH - 150, SCENE_HEIGHT - 80, 130, 70,
                                                 QPen(Qt::darkRed, 2),
                                                 QBrush(QColor(255, 218, 185)));
    QGraphicsTextItem *checkoutLabel = scene->addText("Cashier");
    checkoutLabel->setPos(SCENE_WIDTH - 130, SCENE_HEIGHT - 60);

    // Draw Inventory box under season label (right side, main white area)
    int invBoxWidth = 220;
    int invBoxHeight = 300;                       // Increased height for more content
    int invBoxX = SCENE_WIDTH - invBoxWidth + 60; // Moved 60px to the right
    int invBoxY = 40;                             // Moved 20px up from 60

    // Create background box
    inventoryBox = scene->addRect(invBoxX, invBoxY, invBoxWidth, invBoxHeight,
                                  QPen(Qt::darkGray, 2), QBrush(Qt::white));

    // Create scrollable content area
    inventoryScrollArea = new QScrollArea();
    inventoryScrollArea->setFixedSize(invBoxWidth - 4, invBoxHeight - 4);
    inventoryScrollArea->setStyleSheet("QScrollArea { background-color: white; border: none; }");

    // Create content label for inventory text
    inventoryContentLabel = new QLabel();
    inventoryContentLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    inventoryContentLabel->setMargin(5);
    inventoryContentLabel->setWordWrap(true);
    inventoryContentLabel->setStyleSheet("QLabel { background-color: white; color: black; font-size: 15px; }");

    // Set up scroll area with content
    inventoryScrollArea->setWidget(inventoryContentLabel);
    inventoryScrollArea->setWidgetResizable(true);
    inventoryScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    inventoryScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Add scroll area to scene via proxy widget
    inventoryProxy = scene->addWidget(inventoryScrollArea);
    inventoryProxy->setPos(invBoxX + 2, invBoxY + 2);

    // Add title
    QGraphicsTextItem *invTitle = scene->addText("Inventory");
    invTitle->setDefaultTextColor(Qt::darkBlue);
    invTitle->setFont(QFont("Arial", 12, QFont::Bold));
    invTitle->setPos(invBoxX + 10, invBoxY - 25);

    updateInventoryDisplay();
}

void NurseryWindow::updateInventoryDisplay()
{
    if (!nurseryBackend || !inventoryContentLabel)
        return;
    Inventory *inv = nurseryBackend->getInventory();
    if (!inv)
        return;
    auto &map = inv->getInventory();
    QString text;

    // Group plants by type for better organization
    QStringList flowers, herbs, trees, succulents;

    for (const auto &pair : map)
    {
        const std::string &name = pair.first;
        int qty = pair.second.second;
        QString plantLine = QString::fromStdString(name) + ": " + QString::number(qty);

        // Categorize plants based on their names
        if (name == "Rose" || name == "Tulip" || name == "Lily" || name == "Sunflower" || name == "Daisy")
        {
            flowers << plantLine;
        }
        else if (name == "Basil" || name == "Mint" || name == "Rosemary" || name == "Thyme" || name == "Oregano")
        {
            herbs << plantLine;
        }
        else if (name == "Oak" || name == "Maple" || name == "Pine" || name == "Apple")
        {
            trees << plantLine;
        }
        else if (name == "Aloe" || name == "Cactus" || name == "Jade" || name == "Echeveria")
        {
            succulents << plantLine;
        }
    }

    // Build organized display text
    if (!flowers.isEmpty())
    {
        text += "<b>🌸 Flowers:</b><br>";
        text += flowers.join("<br>") + "<br><br>";
    }
    if (!herbs.isEmpty())
    {
        text += "<b>🌿 Herbs:</b><br>";
        text += herbs.join("<br>") + "<br><br>";
    }
    if (!trees.isEmpty())
    {
        text += "<b>🌳 Trees:</b><br>";
        text += trees.join("<br>") + "<br><br>";
    }
    if (!succulents.isEmpty())
    {
        text += "<b>🌵 Succulents:</b><br>";
        text += succulents.join("<br>");
    }

    inventoryContentLabel->setText(text.trimmed());
}

void NurseryWindow::startSimulation()
{
    isRunning = true;
    simulationTimer->start(50);      // Update every 50ms
    customerSpawnTimer->start(3000); // Add customer every 3 seconds

    startBtn->setEnabled(false);
    pauseBtn->setEnabled(true);
    statusLabel->setText("Status: Running");
}

void NurseryWindow::pauseSimulation()
{
    isRunning = false;
    simulationTimer->stop();
    customerSpawnTimer->stop();

    startBtn->setEnabled(true);
    pauseBtn->setEnabled(false);
    statusLabel->setText("Status: Paused");
}

void NurseryWindow::resetSimulation()
{
    pauseSimulation();

    // Remove all customer visuals
    for (auto &cv : customerVisuals)
    {
        scene->removeItem(cv.dot);
        delete cv.dot;
        if (cv.bubble)
        {
            scene->removeItem(cv.bubble);
            delete cv.bubble;
        }
    }
    customerVisuals.clear();

    // Reset backend (recreate it)
    delete nurseryBackend;
    nurseryBackend = new Nursery(nullptr);

    customerCountLabel->setText("Customers: 0");
    statusLabel->setText("Status: Ready");
}

void NurseryWindow::addCustomer()
{
    if (!nurseryBackend)
    {
        qDebug() << "Warning: Backend nursery not initialized";
        return;
    }

    qDebug() << "Creating new customer...";

    // Create customer in backend
    CustomerCreator *creator = new CustomerCreator();
    Customer *newCustomer = nurseryBackend->getStock() ? creator->createNewCustomer(nurseryBackend, nurseryBackend->getStock()) : nullptr;
    delete creator;

    if (newCustomer)
    {
        nurseryBackend->addCustomer(newCustomer);
        qDebug() << "Customer" << newCustomer->getId() << "created";

        // Check customer's initial action
        Action *action = newCustomer->getAction();
        if (action)
        {
            qDebug() << "=== New Customer" << newCustomer->getId() << "===";
            qDebug() << "Action:" << QString::fromStdString(action->getActionName());

            Browse *browseAction = dynamic_cast<Browse *>(action);
            if (browseAction)
            {
                std::vector<Plant *> plants = browseAction->getPlantsToBuy();
                std::vector<int> quantities = browseAction->getQuantities();
                qDebug() << "IMMEDIATELY after creation: Browse has" << plants.size() << "plants";
                for (size_t i = 0; i < plants.size(); ++i)
                {
                    if (plants[i])
                    {
                        qDebug() << "  -" << quantities[i] << "x" << QString::fromStdString(plants[i]->getName());
                    }
                }

                // Start the browsing timer
                action->handle(newCustomer);
                qDebug() << "Browse timer started";
            }
            else
            {
                // For non-browse actions, just handle normally
                action->handle(newCustomer);
            }
        }

        // Create visual representation
        CustomerVisual cv;
        cv.customer = newCustomer;

        // Create thinking bubble first (so we can pass it to CustomerDot)
        cv.bubble = new ThinkingBubble(this, newCustomer);
        scene->addItem(cv.bubble);
        cv.bubble->setPos(60, SCENE_HEIGHT - 35 - 30); // Position above the dot

        // Create blue dot for customer with hover capability
        cv.dot = new CustomerDot(0, 0, CUSTOMER_SIZE, CUSTOMER_SIZE, cv.bubble);
        cv.dot->setPen(QPen(Qt::darkBlue, 2));
        cv.dot->setBrush(QBrush(QColor(0, 120, 255)));
        cv.dot->setOpacity(0.9);
        scene->addItem(cv.dot);

        // Start at entrance (bottom left)
        cv.dot->setPos(60, SCENE_HEIGHT - 35);

        // Set random initial target
        std::uniform_real_distribution<qreal> distX(100, SCENE_WIDTH - 100);
        std::uniform_real_distribution<qreal> distY(150, SCENE_HEIGHT - 100);

        cv.targetX = distX(rng);
        cv.targetY = distY(rng);
        cv.velocityX = 0;
        cv.velocityY = 0;

        customerVisuals.append(cv);
        customerCountLabel->setText(QString("Customers: %1").arg(customerVisuals.size()));
        qDebug() << "Customer visual added. Total customers:" << customerVisuals.size();
    }
    else
    {
        qDebug() << "Failed to create customer";
    }
}

void NurseryWindow::updateSimulation()
{
    if (!isRunning)
        return;

    // Update season display
    if (nurseryBackend && nurseryBackend->getCurrentSeason())
    {
        QString seasonName = QString::fromStdString(nurseryBackend->getCurrentSeason()->getSeason());
        seasonLabel->setText(QString("Season: %1").arg(seasonName));
    }

    // Update each customer's movement
    for (int i = customerVisuals.size() - 1; i >= 0; --i)
    {
        updateCustomerMovement(customerVisuals[i]);
    }

    // Update thinking bubble information if any are displayed
    updateThinkingBubbles();

    // Update inventory display every tick
    updateInventoryDisplay();
}
void NurseryWindow::updateCustomerMovement(CustomerVisual &cv)
{
    if (!cv.dot)
        return;

    QPointF currentPos = cv.dot->pos();

    // Calculate distance to target
    qreal dx = cv.targetX - currentPos.x();
    qreal dy = cv.targetY - currentPos.y();
    qreal distance = std::sqrt(dx * dx + dy * dy);

    // If close to target, pick a new random target
    if (distance < 30)
    {
        std::uniform_real_distribution<qreal> distX(100, SCENE_WIDTH - 100);
        std::uniform_real_distribution<qreal> distY(150, SCENE_HEIGHT - 100);

        cv.targetX = distX(rng);
        cv.targetY = distY(rng);

        dx = cv.targetX - currentPos.x();
        dy = cv.targetY - currentPos.y();
        distance = std::sqrt(dx * dx + dy * dy);
    }

    // Move towards target
    if (distance > 0)
    {
        cv.velocityX = (dx / distance) * MOVEMENT_SPEED;
        cv.velocityY = (dy / distance) * MOVEMENT_SPEED;

        qreal newX = currentPos.x() + cv.velocityX;
        qreal newY = currentPos.y() + cv.velocityY;

        // Keep within bounds
        newX = qMax(0.0, qMin(newX, SCENE_WIDTH - CUSTOMER_SIZE));
        newY = qMax(0.0, qMin(newY, SCENE_HEIGHT - CUSTOMER_SIZE));

        cv.dot->setPos(newX, newY);

        // Move thinking bubble with customer
        if (cv.bubble)
        {
            cv.bubble->setPos(newX, newY - 30);
        }
    }
}

void NurseryWindow::removeCustomerVisual(Customer *customer)
{
    for (int i = 0; i < customerVisuals.size(); ++i)
    {
        if (customerVisuals[i].customer == customer)
        {
            scene->removeItem(customerVisuals[i].dot);
            delete customerVisuals[i].dot;
            if (customerVisuals[i].bubble)
            {
                scene->removeItem(customerVisuals[i].bubble);
                delete customerVisuals[i].bubble;
            }
            customerVisuals.removeAt(i);
            customerCountLabel->setText(QString("Customers: %1").arg(customerVisuals.size()));
            break;
        }
    }
}

void NurseryWindow::updateThinkingBubbles()
{
    // Refresh info in any expanded thinking bubbles to reflect state changes
    for (auto &cv : customerVisuals)
    {
        if (cv.bubble)
        {
            cv.bubble->refreshInfo();
        }
    }
}

QString NurseryWindow::getCustomerInfo(Customer *customer)
{
    if (!customer)
        return "No customer data";

    QString info;
    info += QString("Customer #%1\n\n").arg(customer->getId());

    // Get current state/action
    Action *action = customer->getAction();
    if (action)
    {
        info += QString("State: %1\n\n").arg(QString::fromStdString(action->getActionName()));

        // Check if browsing and extract plant info
        Browse *browseAction = dynamic_cast<Browse *>(action);
        if (browseAction)
        {
            std::vector<Plant *> plants = browseAction->getPlantsToBuy();
            std::vector<int> quantities = browseAction->getQuantities();

            qDebug() << "=== getCustomerInfo: Browse customer detected ===";
            qDebug() << "Plants vector size:" << plants.size();
            qDebug() << "Quantities vector size:" << quantities.size();

            if (plants.size() > 0)
            {
                info += "Looking for:\n";
                for (size_t i = 0; i < plants.size() && i < quantities.size(); ++i)
                {
                    if (plants[i])
                    {
                        QString plantName = QString::fromStdString(plants[i]->getName());
                        info += QString("  • %1 x %2\n").arg(quantities[i]).arg(plantName);
                        qDebug() << "  Display:" << quantities[i] << "x" << plantName;

                        // Check if plant has decorations
                        PlantDecorator *decorator = dynamic_cast<PlantDecorator *>(plants[i]);
                        if (decorator)
                        {
                            // Check specific decoration types
                            if (dynamic_cast<GiftWrap *>(decorator))
                            {
                                info += "    → Wants: Gift Wrap\n";
                            }
                            else if (dynamic_cast<Pot *>(decorator))
                            {
                                info += "    → Wants: Pot\n";
                            }
                            else if (dynamic_cast<SpecialArrangement *>(decorator))
                            {
                                info += "    → Wants: Special Arrangement\n";
                            }
                            else
                            {
                                info += "    → Wants: Decoration\n";
                            }
                        }
                    }
                }
            }
            else
            {
                info += "Looking for: (Just started browsing...)\n";
                qDebug() << "  ERROR: Browse action has 0 plants!";
            }
        }
        else
        {
            qDebug() << "  Not a Browse action";
        }

        // Check if enquiring
        Enquire *enquireAction = dynamic_cast<Enquire *>(action);
        if (enquireAction)
        {
            std::vector<Plant *> plants = enquireAction->getPlantsOfInterest();

            if (enquireAction->getQuestionType() == 0)
            {
                info += "Type: Advice Question\n\n";
                QString question = QString::fromStdString(enquireAction->getAdviceQuestion());
                if (!question.isEmpty())
                {
                    info += QString("Question: %1\n").arg(question);
                }
            }
            else
            {
                info += "Type: Information Question\n\n";
                // For information questions, display the specific question about stock
                if (plants.size() > 0 && plants[0])
                {
                    QString plantName = QString::fromStdString(plants[0]->getName());
                    info += QString("Question: How many %1 do you have in stock?\n").arg(plantName);
                }
                else
                {
                    info += "Question: General stock inquiry\n";
                }
            }
        }

        // Check if purchasing
        Purchasing *purchaseAction = dynamic_cast<Purchasing *>(action);
        if (purchaseAction)
        {
            std::vector<Plant *> plants = purchaseAction->getPlantsToBuy();
            std::vector<int> quantities = purchaseAction->getQuantities();

            if (plants.size() > 0)
            {
                info += "Acquired:\n";
                for (size_t i = 0; i < plants.size() && i < quantities.size(); ++i)
                {
                    if (plants[i])
                    {
                        QString plantName = QString::fromStdString(plants[i]->getName());
                        info += QString("  • %1 x %2 (Acquired)\n").arg(quantities[i]).arg(plantName);

                        // Check if plant has decorations
                        PlantDecorator *decorator = dynamic_cast<PlantDecorator *>(plants[i]);
                        if (decorator)
                        {
                            if (dynamic_cast<GiftWrap *>(decorator))
                            {
                                info += "    → With: Gift Wrap\n";
                            }
                            else if (dynamic_cast<Pot *>(decorator))
                            {
                                info += "    → With: Pot\n";
                            }
                            else if (dynamic_cast<SpecialArrangement *>(decorator))
                            {
                                info += "    → With: Special Arrangement\n";
                            }
                            else
                            {
                                info += "    → With: Decoration\n";
                            }
                        }
                    }
                }
                info += "\n";
            }
        }
    }
    else
    {
        info += "State: Unknown\n";
    }

    // Show basket contents
    const std::vector<Plant *> &basket = customer->getBasket();
    if (!basket.empty())
    {
        info += QString("Basket: %1 items\n").arg(basket.size());

        // Count unique plants
        std::map<std::string, int> plantCounts;
        for (Plant *plant : basket)
        {
            if (plant)
            {
                plantCounts[plant->getName()]++;
            }
        }

        for (const auto &pair : plantCounts)
        {
            info += QString("  • %1 x %2\n").arg(pair.second).arg(QString::fromStdString(pair.first));
        }
    }

    return info;
}
