#ifndef NURSERYWINDOW_H
#define NURSERYWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QVector>
#include <QPushButton>
#include <QLabel>
#include <QScrollArea>
#include <QWidget>
#include <QGraphicsProxyWidget>
#include <random>

// Forward declare backend classes
class Nursery;
class Customer;

QT_BEGIN_NAMESPACE
namespace Ui
{
    class NurseryWindow;
}
QT_END_NAMESPACE

// Forward declare custom bubble class
class ThinkingBubble;

// Structure to hold customer visual representation
struct CustomerVisual
{
    QGraphicsEllipseItem *dot;
    Customer *customer;
    ThinkingBubble *bubble;
    qreal velocityX;
    qreal velocityY;
    qreal targetX;
    qreal targetY;
};

class NurseryWindow : public QMainWindow
{
    Q_OBJECT

public:
    NurseryWindow(QWidget *parent = nullptr);
    ~NurseryWindow();

private slots:
    void updateSimulation();
    void addCustomer();
    void startSimulation();
    void pauseSimulation();
    void resetSimulation();

private:
    void setupUI();
    void setupScene();
    void updateCustomerMovement(CustomerVisual &cv);
    void removeCustomerVisual(Customer *customer);
    void updateThinkingBubbles();

    // Inventory display
    QGraphicsRectItem *inventoryBox = nullptr;
    QScrollArea *inventoryScrollArea = nullptr;
    QLabel *inventoryContentLabel = nullptr;
    QGraphicsProxyWidget *inventoryProxy = nullptr;
    void updateInventoryDisplay();

    Ui::NurseryWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *simulationTimer;
    QTimer *customerSpawnTimer;

    // Control buttons
    QPushButton *startBtn;
    QPushButton *pauseBtn;
    QPushButton *resetBtn;
    QPushButton *addCustomerBtn;

    // Status labels
    QLabel *customerCountLabel;
    QLabel *statusLabel;
    QLabel *seasonLabel;

    // Backend simulation
    Nursery *nurseryBackend;

    // Visual representations
    QVector<CustomerVisual> customerVisuals;

    // Simulation parameters
    const qreal CUSTOMER_SIZE = 20.0;
    const qreal MOVEMENT_SPEED = 2.0;
    const int SCENE_WIDTH = 800;
    const int SCENE_HEIGHT = 600;

    // Random number generator
    std::mt19937 rng;

    bool isRunning;

public:
    bool isSimulationRunning() const { return isRunning; }
    QString getCustomerInfo(Customer *customer);
};
#endif // NURSERYWINDOW_H
