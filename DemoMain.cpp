/**
 * @file DemoMain.cpp
 * @brief Interactive text-based demonstration showing all design patterns working together
 * @author Chaos_Compilers
 * @date 2025
 *
 * This demonstration showcases the integration of multiple design patterns:
 * - Facade, State, Factory, Command, Observer, Strategy, Decorator
 */

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <memory>
#include <thread>
#include <chrono>
#include <QCoreApplication>
#include "src/Nursery/Nursery.h"
#include "src/Customer/Customer.h"
#include "src/Customer/Browse.h"
#include "src/Customer/Enquire.h"
#include "src/Customer/Purchasing.h"
#include "src/Greenhouse/Plant.h"
#include "src/Greenhouse/FlowerPlant.h"
#include "src/Greenhouse/HerbPlant.h"
#include "src/Greenhouse/TreePlant.h"
#include "src/Greenhouse/SucculentPlant.h"
#include "src/Greenhouse/Seed.h"
#include "src/Greenhouse/Sapling.h"
#include "src/Greenhouse/Prime.h"
#include "src/Greenhouse/Spring.h"
#include "src/Greenhouse/Summer.h"
#include "src/Greenhouse/Autumn.h"
#include "src/Greenhouse/Winter.h"
#include "src/Greenhouse/GiftWrap.h"
#include "src/Greenhouse/Pot.h"
#include "src/Staff/Staff.h"

using namespace std;

/**
 * @brief Clears the console screen
 */
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/**
 * @brief Pauses execution and waits for user input
 */
void pauseScreen()
{
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

/**
 * @brief Simulates a delay for dramatic effect
 */
void delay(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

/**
 * @brief Prints text with typing effect
 */
void typeText(const string &text, int delayMs = 30)
{
    for (char c : text)
    {
        cout << c << flush;
        delay(delayMs);
    }
    cout << endl;
}

/**
 * @brief Displays the main menu header
 */
void displayHeader()
{
    cout << "\n";
    cout << "╔══════════════════════════════════════════════════════════════╗\n";
    cout << "║          🌱 CHAOTIC PLANTS NURSERY SIMULATION 🌱            ║\n";
    cout << "║                   Management System Demo                     ║\n";
    cout << "╚══════════════════════════════════════════════════════════════╝\n";
    cout << "\n";
}

/**
 * @brief Displays the main menu options
 */
void displayMainMenu()
{
    cout << "┌──────────────────────────────────────────────────────────────┐\n";
    cout << "│                        MAIN MENU                             │\n";
    cout << "├──────────────────────────────────────────────────────────────┤\n";
    cout << "│  1. 🎬 Complete Integrated Demo (All Patterns)               │\n";
    cout << "│  2. 👥 Customer Journey Demo (State Pattern)                 │\n";
    cout << "│  3. 🌱 Plant Lifecycle Demo (Factory + State)                │\n";
    cout << "│  4. 🌡️  Seasonal Changes Demo (State + Observer)             │\n";
    cout << "│  5. 🎁 Plant Decoration Demo (Decorator Pattern)             │\n";
    cout << "│  6. 📦 Stock Management Demo (Command Pattern)               │\n";
    cout << "│  7. 👨‍💼 Staff Assignment Demo (Observer Pattern)             │\n";
    cout << "│  8. 📊 View Current Nursery Status                           │\n";
    cout << "│  9. 📚 About Design Patterns                                 │\n";
    cout << "│  0. Exit Simulation                                          │\n";
    cout << "└──────────────────────────────────────────────────────────────┘\n";
    cout << "Enter your choice: ";
}

/**
 * @brief Displays customer management submenu
 */
void displayCustomerMenu()
{
    cout << "\n┌──────────────────────────────────────────────────────────────┐\n";
    cout << "│                  CUSTOMER MANAGEMENT                         │\n";
    cout << "├──────────────────────────────────────────────────────────────┤\n";
    cout << "│  1. Add New Customer                                         │\n";
    cout << "│  2. View All Active Customers                                │\n";
    cout << "│  3. Simulate Customer Actions                                │\n";
    cout << "│  4. Process Customer Departure                               │\n";
    cout << "│  0. Back to Main Menu                                        │\n";
    cout << "└──────────────────────────────────────────────────────────────┘\n";
    cout << "Enter your choice: ";
}

/**
 * @brief Displays inventory management submenu
 */
void displayInventoryMenu()
{
    cout << "\n┌──────────────────────────────────────────────────────────────┐\n";
    cout << "│               INVENTORY & STOCK MANAGEMENT                   │\n";
    cout << "├──────────────────────────────────────────────────────────────┤\n";
    cout << "│  1. View Current Inventory                                   │\n";
    cout << "│  2. Add Plants to Stock                                      │\n";
    cout << "│  3. View Stock Catalogue                                     │\n";
    cout << "│  4. View Total Plant Count                                   │\n";
    cout << "│  0. Back to Main Menu                                        │\n";
    cout << "└──────────────────────────────────────────────────────────────┘\n";
    cout << "Enter your choice: ";
}

/**
 * @brief Displays seasonal management submenu
 */
void displaySeasonMenu()
{
    cout << "\n┌──────────────────────────────────────────────────────────────┐\n";
    cout << "│                  SEASONAL MANAGEMENT                         │\n";
    cout << "├──────────────────────────────────────────────────────────────┤\n";
    cout << "│  1. View Current Season                                      │\n";
    cout << "│  2. Change Season to Spring                                  │\n";
    cout << "│  3. Change Season to Summer                                  │\n";
    cout << "│  4. Change Season to Autumn                                  │\n";
    cout << "│  5. Change Season to Winter                                  │\n";
    cout << "│  6. Demonstrate Seasonal Effects                             │\n";
    cout << "│  0. Back to Main Menu                                        │\n";
    cout << "└──────────────────────────────────────────────────────────────┘\n";
    cout << "Enter your choice: ";
}

/**
 * @brief Displays design patterns information
 */
void displayDesignPatterns()
{
    clearScreen();
    displayHeader();
    cout << "╔══════════════════════════════════════════════════════════════╗\n";
    cout << "║              DESIGN PATTERNS IMPLEMENTATION                  ║\n";
    cout << "╚══════════════════════════════════════════════════════════════╝\n\n";

    cout << "This simulation demonstrates various design patterns:\n\n";

    cout << "🔹 FACADE PATTERN\n";
    cout << "   - Nursery class provides simplified interface to complex subsystems\n";
    cout << "   - Coordinates customers, staff, inventory, and seasons\n\n";

    cout << "🔹 STATE PATTERN\n";
    cout << "   - Customer actions (Browse, Enquire, Purchasing)\n";
    cout << "   - Seasonal states (Spring, Summer, Autumn, Winter)\n";
    cout << "   - Plant development stages (Seed, Sapling, Prime, Wilting, Dead)\n\n";

    cout << "🔹 FACTORY METHOD PATTERN\n";
    cout << "   - FlowerPlanter, HerbPlanter, TreePlanter, SucculentPlanter\n";
    cout << "   - CustomerCreator for customer instantiation\n\n";

    cout << "🔹 COMMAND PATTERN\n";
    cout << "   - AddStock and RemoveStock commands\n";
    cout << "   - StateCommand for seasonal transitions\n\n";

    cout << "🔹 OBSERVER PATTERN\n";
    cout << "   - Inventory notifies staff of changes\n";
    cout << "   - Staff members observe inventory updates\n\n";

    cout << "🔹 STRATEGY PATTERN\n";
    cout << "   - CareStrategy for plant care (FlowerStrategy, HerbStrategy, etc.)\n\n";

    cout << "🔹 DECORATOR PATTERN\n";
    cout << "   - PlantDecorator for gift wrapping, pots, special arrangements\n\n";

    pauseScreen();
}

/**
 * @brief Handles customer management operations
 */
void handleCustomerManagement(Nursery *nursery)
{
    int choice;
    bool backToMain = false;

    while (!backToMain)
    {
        clearScreen();
        displayHeader();
        displayCustomerMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\n🌟 Adding new customer to nursery...\n";
            nursery->handleCustomerArrivalSignal();
            cout << "✓ Customer added successfully!\n";
            pauseScreen();
            break;
        }
        case 2:
        {
            cout << "\n📋 Active Customers:\n";
            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
            const auto &customers = nursery->getActiveCustomers();
            if (customers.empty())
            {
                cout << "No active customers in the nursery.\n";
            }
            else
            {
                for (size_t i = 0; i < customers.size(); i++)
                {
                    cout << "Customer #" << customers[i]->getId()
                         << " - Current Action: ";
                    if (customers[i]->getAction())
                    {
                        auto action = customers[i]->getAction();
                        // Identify action type by attempting dynamic_cast
                        if (dynamic_cast<Browse *>(action))
                        {
                            cout << "Browsing";
                        }
                        else if (dynamic_cast<Enquire *>(action))
                        {
                            cout << "Enquiring";
                        }
                        else if (dynamic_cast<Purchasing *>(action))
                        {
                            cout << "Purchasing";
                        }
                        else
                        {
                            cout << "Unknown";
                        }
                    }
                    else
                    {
                        cout << "None";
                    }
                    cout << "\n";
                }
                cout << "\nTotal Active Customers: " << customers.size() << "\n";
            }
            pauseScreen();
            break;
        }
        case 3:
        {
            cout << "\n🎬 Simulating customer actions...\n";
            const auto &customers = nursery->getActiveCustomers();
            if (customers.empty())
            {
                cout << "No customers to simulate.\n";
            }
            else
            {
                for (auto customer : customers)
                {
                    cout << "\nCustomer #" << customer->getId() << " performing action...\n";
                    customer->request();
                    cout << "Transitioning to next action...\n";
                    customer->processNextAction();
                }
                cout << "\n✓ Customer actions simulated!\n";
            }
            pauseScreen();
            break;
        }
        case 4:
        {
            const auto &customers = nursery->getActiveCustomers();
            if (customers.empty())
            {
                cout << "\nNo customers to remove.\n";
            }
            else
            {
                cout << "\nRemoving first customer from nursery...\n";
                Customer *customer = customers[0];
                nursery->handleCustomerDeparture(customer);
                cout << "✓ Customer removed successfully!\n";
            }
            pauseScreen();
            break;
        }
        case 0:
            backToMain = true;
            break;
        default:
            cout << "\n❌ Invalid choice. Please try again.\n";
            pauseScreen();
        }
    }
}

/**
 * @brief Handles inventory and stock management operations
 */
void handleInventoryManagement(Nursery *nursery)
{
    int choice;
    bool backToMain = false;

    while (!backToMain)
    {
        clearScreen();
        displayHeader();
        displayInventoryMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\n📦 Current Inventory:\n";
            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
            nursery->getInventory()->getCatalogue();
            pauseScreen();
            break;
        }
        case 2:
        {
            cout << "\n➕ Adding plants to stock...\n";
            cout << "Select plant type:\n";
            cout << "1. Flower\n";
            cout << "2. Herb\n";
            cout << "3. Tree\n";
            cout << "4. Succulent\n";
            cout << "Enter choice: ";
            int plantChoice;
            cin >> plantChoice;

            cout << "Enter quantity to add: ";
            int quantity;
            cin >> quantity;

            unique_ptr<Plant> plant;
            switch (plantChoice)
            {
            case 1:
                plant = nursery->getFlowerFactory()->makePlant();
                cout << "Adding " << quantity << " flowers to stock...\n";
                break;
            case 2:
                plant = nursery->getHerbFactory()->makePlant();
                cout << "Adding " << quantity << " herbs to stock...\n";
                break;
            case 3:
            {
                TreePlanter treePlanter;
                plant = treePlanter.makePlant();
                cout << "Adding " << quantity << " trees to stock...\n";
                break;
            }
            case 4:
            {
                SucculentPlanter succulentPlanter;
                plant = succulentPlanter.makePlant();
                cout << "Adding " << quantity << " succulents to stock...\n";
                break;
            }
            default:
                cout << "Invalid choice.\n";
                pauseScreen();
                continue;
            }

            if (plant)
            {
                nursery->getStock()->Add(std::move(plant), quantity);
                cout << "✓ Plants added successfully!\n";
            }
            pauseScreen();
            break;
        }
        case 3:
        {
            cout << "\n🏪 Stock Catalogue:\n";
            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
            nursery->getStock()->printStock();
            pauseScreen();
            break;
        }
        case 4:
        {
            cout << "\n📊 Total Plant Count: " << nursery->getStock()->getTotalPlants() << "\n";
            pauseScreen();
            break;
        }
        case 0:
            backToMain = true;
            break;
        default:
            cout << "\n❌ Invalid choice. Please try again.\n";
            pauseScreen();
        }
    }
}

/**
 * @brief Handles seasonal management operations
 */
void handleSeasonManagement(Nursery *nursery)
{
    int choice;
    bool backToMain = false;

    while (!backToMain)
    {
        clearScreen();
        displayHeader();
        displaySeasonMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\n🌡️ Current Season: " << nursery->getCurrentSeason()->getSeason() << "\n";
            pauseScreen();
            break;
        }
        case 2:
        {
            cout << "\n🌸 Changing season to Spring...\n";
            Seasons *spring = new Spring(nursery->getInventory());
            nursery->setState(spring);
            cout << "✓ Season changed to Spring!\n";
            cout << "Effects: Plants grow faster, new stock arrives\n";
            pauseScreen();
            break;
        }
        case 3:
        {
            cout << "\n☀️ Changing season to Summer...\n";
            Seasons *summer = new Summer(nursery->getInventory());
            nursery->setState(summer);
            cout << "✓ Season changed to Summer!\n";
            cout << "Effects: Plants need more water, increased care requirements\n";
            pauseScreen();
            break;
        }
        case 4:
        {
            cout << "\n🍂 Changing season to Autumn...\n";
            Seasons *autumn = new Autumn(nursery->getInventory());
            nursery->setState(autumn);
            cout << "✓ Season changed to Autumn!\n";
            cout << "Effects: Harvest time, plants transition stages\n";
            pauseScreen();
            break;
        }
        case 5:
        {
            cout << "\n❄️ Changing season to Winter...\n";
            Seasons *winter = new Winter(nursery->getInventory());
            nursery->setState(winter);
            cout << "✓ Season changed to Winter!\n";
            cout << "Effects: Reduced growth, dormancy period\n";
            pauseScreen();
            break;
        }
        case 6:
        {
            cout << "\n🔄 Demonstrating seasonal transition effects...\n";
            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
            cout << "Current season: " << nursery->getCurrentSeason()->getSeason() << "\n";
            cout << "\nTriggering seasonal change...\n";
            nursery->getCurrentSeason()->handleChange(nursery);
            cout << "\nNew season: " << nursery->getCurrentSeason()->getSeason() << "\n";
            cout << "✓ Seasonal effects applied to inventory!\n";
            pauseScreen();
            break;
        }
        case 0:
            backToMain = true;
            break;
        default:
            cout << "\n❌ Invalid choice. Please try again.\n";
            pauseScreen();
        }
    }
}

/**
 * @brief Displays current nursery status
 */
void displayNurseryStatus(Nursery *nursery)
{
    clearScreen();
    displayHeader();
    cout << "╔══════════════════════════════════════════════════════════════╗\n";
    cout << "║                    NURSERY STATUS REPORT                     ║\n";
    cout << "╚══════════════════════════════════════════════════════════════╝\n\n";

    cout << "📊 Current Statistics:\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "🌡️  Current Season: " << nursery->getCurrentSeason()->getSeason() << "\n";
    cout << "👥 Active Customers: " << nursery->getActiveCustomers().size() << "\n";
    cout << "🌱 Total Plants in Stock: " << nursery->getStock()->getTotalPlants() << "\n";
    cout << "🏪 Stock List Size: " << nursery->getStock()->getStockListSize() << "\n";
    cout << "\n";

    cout << "👨‍💼 Staff Information:\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "Info Desk: Available\n";
    cout << "Cashier: " << (nursery->getCashier() ? "Available" : "Unavailable") << "\n";
    cout << "\n";

    pauseScreen();
}

/**
 * @brief Complete integrated demonstration showing all patterns working together
 */
void completeIntegratedDemo(Nursery *nursery)
{
    clearScreen();
    displayHeader();
    cout << "╔══════════════════════════════════════════════════════════════╗\n";
    cout << "║           🎬 COMPLETE INTEGRATED DEMONSTRATION 🎬            ║\n";
    cout << "║         All Design Patterns Working Together                 ║\n";
    cout << "╚══════════════════════════════════════════════════════════════╝\n\n";

    cout << "Welcome to a day in the life of Chaotic Plants Nursery!\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";
    delay(1000);

    // PHASE 1: Setup - Facade Pattern
    cout << "📋 PHASE 1: Nursery Opening (FACADE PATTERN)\n";
    cout << "The Nursery facade coordinates all subsystems:\n";
    cout << "  ✓ Inventory System initialized\n";
    delay(500);
    cout << "  ✓ Stock Management ready\n";
    delay(500);
    cout << "  ✓ Staff (InfoDesk & Cashier) prepared\n";
    delay(500);
    cout << "  ✓ Current Season: " << nursery->getCurrentSeason()->getSeason() << "\n\n";
    delay(1000);

    // PHASE 2: Stock arrival - Factory + Command Patterns
    cout << "📦 PHASE 2: Morning Stock Delivery (FACTORY + COMMAND PATTERNS)\n";
    cout << "Factory Method creates plants, Command Pattern adds to inventory:\n\n";

    cout << "  🌸 FlowerPlanter creating roses...\n";
    auto flower = nursery->getFlowerFactory()->makePlant();
    delay(500);
    cout << "     → Created: " << flower->getName() << " (" << flower->getType() << ")\n";
    nursery->getStock()->Add(std::move(flower), 5);
    delay(500);
    cout << "     → AddStock command executed: 5 units added\n\n";

    cout << "  🌿 HerbPlanter creating herbs...\n";
    auto herb = nursery->getHerbFactory()->makePlant();
    delay(500);
    cout << "     → Created: " << herb->getName() << " (" << herb->getType() << ")\n";
    nursery->getStock()->Add(std::move(herb), 8);
    delay(500);
    cout << "     → AddStock command executed: 8 units added\n\n";

    cout << "  🌳 TreePlanter creating saplings...\n";
    TreePlanter treePlanter;
    auto tree = treePlanter.makePlant();
    delay(500);
    cout << "     → Created: " << tree->getName() << " (" << tree->getType() << ")\n";
    nursery->getStock()->Add(std::move(tree), 3);
    delay(500);
    cout << "     → AddStock command executed: 3 units added\n\n";
    delay(1000);

    // PHASE 3: Customer arrival - State Pattern
    cout << "👥 PHASE 3: Customer Arrival (STATE PATTERN)\n";
    cout << "Customer states: Browse → Enquire → Purchasing → Departure\n\n";

    cout << "  Customer #1 arrives at the nursery...\n";
    delay(500);
    nursery->handleCustomerArrivalSignal();
    delay(500);

    const auto &customers = nursery->getActiveCustomers();
    if (!customers.empty())
    {
        Customer *customer = customers[0];
        cout << "  State: BROWSING - Customer exploring the nursery\n";
        delay(800);
        customer->request();
        delay(500);

        cout << "\n  Customer transitions to ENQUIRE state...\n";
        customer->processNextAction();
        delay(800);
        customer->request();
        delay(500);

        cout << "\n  Customer transitions to PURCHASING state...\n";
        customer->processNextAction();
        delay(800);
        customer->request();
        delay(500);

        cout << "  ✓ State transitions complete!\n\n";
    }
    delay(1000);

    // PHASE 4: Plant decoration - Decorator Pattern
    cout << "🎁 PHASE 4: Plant Preparation (DECORATOR PATTERN)\n";
    cout << "Decorating plants for customer purchase:\n\n";

    auto baseFlower = nursery->getFlowerFactory()->makePlant();
    cout << "  Base plant: " << baseFlower->getName() << "\n";
    delay(500);

    Plant *decoratedPlant = new Pot(baseFlower.release());
    cout << "  + Adding decorative pot\n";
    delay(500);

    decoratedPlant = new GiftWrap(decoratedPlant);
    cout << "  + Adding gift wrapping\n";
    delay(500);
    cout << "  ✓ Fully decorated plant ready for sale!\n\n";
    delete decoratedPlant;
    delay(1000);

    // PHASE 5: Seasonal change - State + Observer Patterns
    cout << "🌡️  PHASE 5: Seasonal Transition (STATE + OBSERVER PATTERNS)\n";
    cout << "Season changes from " << nursery->getCurrentSeason()->getSeason();

    Seasons *newSeason = new Summer(nursery->getInventory());
    nursery->setState(newSeason);
    delay(800);

    cout << " to " << nursery->getCurrentSeason()->getSeason() << "\n";
    cout << "  → Inventory notifies all staff (Observer Pattern)\n";
    delay(500);
    cout << "  → Stock levels adjusted for new season\n";
    delay(500);
    cout << "  → Plant care requirements updated\n";
    delay(500);
    cout << "  ✓ Seasonal transition complete!\n\n";
    delay(1000);

    // PHASE 6: Staff coordination - Observer Pattern
    cout << "👨‍💼 PHASE 6: Staff Coordination (OBSERVER PATTERN)\n";
    cout << "InfoDesk assigns staff to customers:\n";
    delay(500);
    cout << "  → InfoDesk observes customer queue\n";
    delay(500);
    cout << "  → Available staff assigned to customers\n";
    delay(500);
    cout << "  → Cashier notified of pending purchases\n";
    delay(500);
    cout << "  ✓ Staff coordination complete!\n\n";
    delay(1000);

    // PHASE 7: End of day summary
    cout << "📊 END OF DAY SUMMARY\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "Patterns Demonstrated:\n";
    cout << "  ✓ FACADE - Nursery coordinating all subsystems\n";
    cout << "  ✓ FACTORY METHOD - Creating various plant types\n";
    cout << "  ✓ COMMAND - Stock management operations\n";
    cout << "  ✓ STATE - Customer actions & seasonal changes\n";
    cout << "  ✓ DECORATOR - Plant packaging & decoration\n";
    cout << "  ✓ OBSERVER - Inventory notifications to staff\n";
    cout << "  ✓ STRATEGY - Plant care strategies\n\n";

    cout << "Active Customers: " << nursery->getActiveCustomers().size() << "\n";
    cout << "Total Plants: " << nursery->getStock()->getTotalPlants() << "\n";
    cout << "Current Season: " << nursery->getCurrentSeason()->getSeason() << "\n\n";

    pauseScreen();
}

/**
 * @brief Demonstrates customer journey through state transitions
 */
void customerJourneyDemo(Nursery *nursery)
{
    clearScreen();
    displayHeader();
    cout << "╔══════════════════════════════════════════════════════════════╗\n";
    cout << "║           👥 CUSTOMER JOURNEY DEMONSTRATION 👥               ║\n";
    cout << "║              State Pattern in Action                         ║\n";
    cout << "╚══════════════════════════════════════════════════════════════╝\n\n";

    cout << "The Customer class implements the State pattern where each\n";
    cout << "action (Browse, Enquire, Purchasing) represents a state.\n\n";
    delay(1000);

    cout << "Creating a new customer...\n";
    nursery->handleCustomerArrivalSignal();
    delay(800);

    const auto &customers = nursery->getActiveCustomers();
    if (!customers.empty())
    {
        Customer *customer = customers[0];

        cout << "\n┌─ STATE 1: BROWSE ────────────────────────────────────┐\n";
        cout << "│ Customer #" << customer->getId() << " enters the nursery\n";
        cout << "│ Looking at available plants...\n";
        delay(1000);
        customer->request();
        delay(1000);
        cout << "└──────────────────────────────────────────────────────┘\n\n";

        cout << "Transitioning to next state...\n";
        customer->processNextAction();
        delay(1000);

        cout << "\n┌─ STATE 2: ENQUIRE ───────────────────────────────────┐\n";
        cout << "│ Customer asks questions at InfoDesk\n";
        cout << "│ Staff provides care instructions...\n";
        delay(1000);
        customer->request();
        delay(1000);
        cout << "└──────────────────────────────────────────────────────┘\n\n";

        cout << "Transitioning to next state...\n";
        customer->processNextAction();
        delay(1000);

        cout << "\n┌─ STATE 3: PURCHASING ────────────────────────────────┐\n";
        cout << "│ Customer proceeds to checkout\n";
        cout << "│ Processing payment...\n";
        delay(1000);
        customer->request();
        delay(1000);
        cout << "└──────────────────────────────────────────────────────┘\n\n";

        cout << "✓ Customer journey complete!\n";
        cout << "  States traversed: Browse → Enquire → Purchasing\n\n";
    }

    pauseScreen();
}

/**
 * @brief Demonstrates plant lifecycle with factory and state patterns
 */
void plantLifecycleDemo(Nursery *nursery)
{
    clearScreen();
    displayHeader();
    cout << "╔══════════════════════════════════════════════════════════════╗\n";
    cout << "║          🌱 PLANT LIFECYCLE DEMONSTRATION 🌱                 ║\n";
    cout << "║         Factory Method + State Pattern                       ║\n";
    cout << "╚══════════════════════════════════════════════════════════════╝\n\n";

    cout << "Plants progress through development stages using State Pattern:\n";
    cout << "Seed → Sapling → Prime → Wilting → Dead\n\n";
    delay(1000);

    cout << "FACTORY METHOD: Creating different plant types...\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";

    // Flower
    cout << "🌸 FlowerPlanter::makePlant()\n";
    auto flower = nursery->getFlowerFactory()->makePlant();
    delay(500);
    cout << "   Created: " << flower->getName() << " (" << flower->getType() << ")\n";
    cout << "   Water: " << flower->getWater() << " | Soil: " << flower->getSoil()
         << " | Sunlight: " << flower->getSunlight() << "\n";
    delay(800);

    cout << "\n   STATE TRANSITIONS:\n";
    cout << "   Stage 1: Initial state\n";
    delay(600);
    cout << "   Stage 2: Growing...\n";
    flower->grow();
    delay(600);
    cout << "   Stage 3: Mature plant\n";
    flower->grow();
    delay(600);
    cout << "   ✓ Plant lifecycle demonstrated\n\n";
    delay(1000);

    // Herb
    cout << "🌿 HerbPlanter::makePlant()\n";
    auto herb = nursery->getHerbFactory()->makePlant();
    delay(500);
    cout << "   Created: " << herb->getName() << " (" << herb->getType() << ")\n";
    cout << "   Care Strategy: Different from flowers\n";
    delay(800);
    cout << "   Providing care instructions...\n";
    herb->helpPlant();
    delay(600);
    cout << "   ✓ Strategy pattern applied for care\n\n";
    delay(1000);

    // Tree
    cout << "🌳 TreePlanter::makePlant()\n";
    TreePlanter treePlanter;
    auto tree = treePlanter.makePlant();
    delay(500);
    cout << "   Created: " << tree->getName() << " (" << tree->getType() << ")\n";
    cout << "   Long-term growth requirements\n";
    delay(800);
    cout << "   ✓ Factory creates tree with specific attributes\n\n";
    delay(1000);

    // Succulent
    cout << "🌵 SucculentPlanter::makePlant()\n";
    SucculentPlanter succulentPlanter;
    auto succulent = succulentPlanter.makePlant();
    delay(500);
    cout << "   Created: " << succulent->getName() << " (" << succulent->getType() << ")\n";
    cout << "   Low water requirements\n";
    delay(800);
    cout << "   ✓ Each factory encapsulates creation logic\n\n";

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "PATTERNS DEMONSTRATED:\n";
    cout << "• Factory Method: Different planters create specific plant types\n";
    cout << "• State Pattern: Plants transition through development stages\n";
    cout << "• Strategy Pattern: Each plant type has unique care requirements\n\n";

    pauseScreen();
}

/**
 * @brief Demonstrates seasonal changes with state and observer patterns
 */
void seasonalChangesDemo(Nursery *nursery)
{
    clearScreen();
    displayHeader();
    cout << "╔══════════════════════════════════════════════════════════════╗\n";
    cout << "║         🌡️  SEASONAL CHANGES DEMONSTRATION 🌡️               ║\n";
    cout << "║          State Pattern + Observer Pattern                    ║\n";
    cout << "╚══════════════════════════════════════════════════════════════╝\n\n";

    cout << "The nursery uses State Pattern for seasonal transitions.\n";
    cout << "Observer Pattern notifies staff when seasons change.\n\n";
    delay(1000);

    cout << "Current Season: " << nursery->getCurrentSeason()->getSeason() << "\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";
    delay(1000);

    // Spring
    cout << "🌸 Transitioning to SPRING...\n";
    Seasons *spring = new Spring(nursery->getInventory());
    nursery->setState(spring);
    delay(800);
    cout << "   Effects:\n";
    cout << "   • Plants grow rapidly\n";
    delay(400);
    cout << "   • New stock arrives\n";
    delay(400);
    cout << "   • Staff notified of season change (Observer)\n";
    delay(400);
    cout << "   • Inventory adjusts stock levels\n";
    delay(1000);
    cout << "   ✓ Spring state active\n\n";
    delay(1000);

    // Summer
    cout << "☀️ Transitioning to SUMMER...\n";
    Seasons *summer = new Summer(nursery->getInventory());
    nursery->setState(summer);
    delay(800);
    cout << "   Effects:\n";
    cout << "   • Increased watering requirements\n";
    delay(400);
    cout << "   • Higher care needs\n";
    delay(400);
    cout << "   • Staff alerted to new care protocols\n";
    delay(400);
    cout << "   • Inventory observers updated\n";
    delay(1000);
    cout << "   ✓ Summer state active\n\n";
    delay(1000);

    // Autumn
    cout << "🍂 Transitioning to AUTUMN...\n";
    Seasons *autumn = new Autumn(nursery->getInventory());
    nursery->setState(autumn);
    delay(800);
    cout << "   Effects:\n";
    cout << "   • Harvest season begins\n";
    delay(400);
    cout << "   • Plants transition stages\n";
    delay(400);
    cout << "   • Staff prepared for seasonal clearance\n";
    delay(400);
    cout << "   • Stock reduction initiated\n";
    delay(1000);
    cout << "   ✓ Autumn state active\n\n";
    delay(1000);

    // Winter
    cout << "❄️ Transitioning to WINTER...\n";
    Seasons *winter = new Winter(nursery->getInventory());
    nursery->setState(winter);
    delay(800);
    cout << "   Effects:\n";
    cout << "   • Dormancy period for many plants\n";
    delay(400);
    cout << "   • Reduced growth\n";
    delay(400);
    cout << "   • Staff informed of winter protocols\n";
    delay(400);
    cout << "   • Inventory adjusted for cold weather\n";
    delay(1000);
    cout << "   ✓ Winter state active\n\n";

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "PATTERNS DEMONSTRATED:\n";
    cout << "• State Pattern: Each season is a different state with unique behavior\n";
    cout << "• Observer Pattern: Staff and inventory react to seasonal changes\n";
    cout << "• Command Pattern: StateCommand executes season-specific operations\n\n";

    cout << "Final Season: " << nursery->getCurrentSeason()->getSeason() << "\n\n";

    pauseScreen();
}

/**
 * @brief Demonstrates decorator pattern for plant decoration
 */
void plantDecorationDemo(Nursery *nursery)
{
    clearScreen();
    displayHeader();
    cout << "╔══════════════════════════════════════════════════════════════╗\n";
    cout << "║         🎁 PLANT DECORATION DEMONSTRATION 🎁                 ║\n";
    cout << "║              Decorator Pattern in Action                     ║\n";
    cout << "╚══════════════════════════════════════════════════════════════╝\n\n";

    cout << "The Decorator Pattern allows dynamic addition of features\n";
    cout << "to plants without modifying their base classes.\n\n";
    delay(1000);

    // Base plant
    cout << "Step 1: Creating base plant\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    auto basePlant = nursery->getFlowerFactory()->makePlant();
    delay(500);
    cout << "🌸 Base Plant: " << basePlant->getName() << "\n";
    cout << "   Type: " << basePlant->getType() << "\n\n";
    delay(1000);

    // First decoration - Pot
    cout << "Step 2: Adding decorative pot (First Decorator)\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    Plant *decoratedPlant = new Pot(basePlant.release());
    delay(500);
    cout << "🪴 Plant + Pot\n";
    cout << "   Enhanced presentation\n";
    cout << "   Better root protection\n\n";
    delay(1000);

    // Second decoration - Gift Wrap
    cout << "Step 3: Adding gift wrap (Second Decorator)\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    decoratedPlant = new GiftWrap(decoratedPlant);
    delay(500);
    cout << "🎁 Plant + Pot + Gift Wrap\n";
    cout << "   Beautiful presentation\n";
    cout << "   Ready for gifting\n\n";
    delay(1000);

    cout << "Step 4: Final product packaging\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    delay(500);
    cout << "Calling package() on decorated plant...\n";
    decoratedPlant->package();
    delay(800);
    cout << "\n✓ Fully decorated plant ready for sale!\n\n";

    cout << "DECORATOR CHAIN:\n";
    cout << "  Base Plant (Flower)\n";
    cout << "      ↓\n";
    cout << "  + Pot Decorator\n";
    cout << "      ↓\n";
    cout << "  + GiftWrap Decorator\n";
    cout << "      ↓\n";
    cout << "  Final Product\n\n";

    cout << "Each decorator adds functionality while maintaining\n";
    cout << "the same Plant interface. Decorators can be combined\n";
    cout << "in any order and quantity!\n\n";

    delete decoratedPlant;

    pauseScreen();
}

/**
 * @brief Demonstrates command pattern for stock management
 */
void stockManagementDemo(Nursery *nursery)
{
    clearScreen();
    displayHeader();
    cout << "╔══════════════════════════════════════════════════════════════╗\n";
    cout << "║        📦 STOCK MANAGEMENT DEMONSTRATION 📦                  ║\n";
    cout << "║              Command Pattern in Action                       ║\n";
    cout << "╚══════════════════════════════════════════════════════════════╝\n\n";

    cout << "The Command Pattern encapsulates stock operations as objects.\n";
    cout << "This allows operations to be queued, logged, and undone.\n\n";
    delay(1000);

    cout << "Initial Stock Status:\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "Total plants in stock: " << nursery->getStock()->getTotalPlants() << "\n\n";
    delay(1000);

    // AddStock Command
    cout << "COMMAND 1: AddStock\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "Creating AddStock command for Roses...\n";
    delay(500);
    auto roses = nursery->getFlowerFactory()->makePlant();
    cout << "Plant created: " << roses->getName() << "\n";
    delay(500);
    cout << "Executing AddStock command with quantity: 10\n";
    nursery->getStock()->Add(std::move(roses), 10);
    delay(800);
    cout << "✓ AddStock command executed successfully\n";
    cout << "  10 roses added to inventory\n";
    cout << "  Staff notified via Observer pattern\n\n";
    delay(1000);

    cout << "COMMAND 2: AddStock (Different plant type)\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "Creating AddStock command for Herbs...\n";
    delay(500);
    auto herbs = nursery->getHerbFactory()->makePlant();
    cout << "Plant created: " << herbs->getName() << "\n";
    delay(500);
    cout << "Executing AddStock command with quantity: 15\n";
    nursery->getStock()->Add(std::move(herbs), 15);
    delay(800);
    cout << "✓ AddStock command executed successfully\n";
    cout << "  15 herbs added to inventory\n\n";
    delay(1000);

    cout << "Updated Stock Status:\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "Total plants in stock: " << nursery->getStock()->getTotalPlants() << "\n\n";
    delay(1000);

    cout << "COMMAND PATTERN BENEFITS:\n";
    cout << "• Encapsulation: Each operation is a self-contained command\n";
    cout << "• Decoupling: Invoker doesn't need to know operation details\n";
    cout << "• Flexibility: Commands can be queued, logged, or undone\n";
    cout << "• Extensibility: New commands can be added easily\n\n";

    pauseScreen();
}

/**
 * @brief Demonstrates observer pattern with staff notifications
 */
void staffAssignmentDemo(Nursery *nursery)
{
    clearScreen();
    displayHeader();
    cout << "╔══════════════════════════════════════════════════════════════╗\n";
    cout << "║        👨‍💼 STAFF ASSIGNMENT DEMONSTRATION 👨‍💼                ║\n";
    cout << "║              Observer Pattern in Action                      ║\n";
    cout << "╚══════════════════════════════════════════════════════════════╝\n\n";

    cout << "The Observer Pattern allows staff members to react to\n";
    cout << "inventory changes and customer events automatically.\n\n";
    delay(1000);

    cout << "SCENARIO: New customers arrive and inventory changes\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";
    delay(1000);

    // Customer 1 arrives
    cout << "Event 1: Customer #1 arrives\n";
    delay(500);
    nursery->handleCustomerArrivalSignal();
    cout << "  → InfoDesk (Observer) notified\n";
    delay(400);
    cout << "  → Available staff assigned\n";
    delay(400);
    cout << "  → Customer added to active list\n";
    delay(800);
    cout << "  ✓ Staff assignment complete\n\n";
    delay(1000);

    // Inventory change
    cout << "Event 2: New stock arrives\n";
    delay(500);
    auto newPlant = nursery->getFlowerFactory()->makePlant();
    cout << "  → Adding " << newPlant->getName() << " to inventory\n";
    delay(400);
    nursery->getStock()->Add(std::move(newPlant), 20);
    cout << "  → Inventory notifies all observers\n";
    delay(400);
    cout << "  → Cashier (Observer) receives notification\n";
    delay(400);
    cout << "  → InfoDesk (Observer) updates availability\n";
    delay(400);
    cout << "  → Staff members alerted to new stock\n";
    delay(800);
    cout << "  ✓ All observers notified successfully\n\n";
    delay(1000);

    // Customer 2 arrives
    cout << "Event 3: Customer #2 arrives\n";
    delay(500);
    nursery->handleCustomerArrivalSignal();
    cout << "  → InfoDesk handles new customer\n";
    delay(400);
    cout << "  → Checking staff availability\n";
    delay(400);
    cout << "  → Assigning next available staff\n";
    delay(800);
    cout << "  ✓ Second customer serviced\n\n";
    delay(1000);

    cout << "Current Nursery State:\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    cout << "Active Customers: " << nursery->getActiveCustomers().size() << "\n";
    cout << "Total Stock: " << nursery->getStock()->getTotalPlants() << " plants\n";
    cout << "InfoDesk Status: Active\n";
    cout << "Cashier Status: " << (nursery->getCashier() ? "Available" : "Busy") << "\n\n";
    delay(1000);

    cout << "OBSERVER PATTERN FLOW:\n";
    cout << "  Subject (Inventory/InfoDesk)\n";
    cout << "      ↓ notifies\n";
    cout << "  Observers (Staff Members)\n";
    cout << "      ↓ react\n";
    cout << "  Update their state/behavior\n\n";

    cout << "This loose coupling allows the system to scale:\n";
    cout << "• New staff can be added as observers easily\n";
    cout << "• Subject doesn't need to know about observer details\n";
    cout << "• Dynamic subscription/unsubscription supported\n\n";

    pauseScreen();
}

/**
 * @brief Main entry point for the demo application
 */
int main(int argc, char *argv[])
{
    // Initialize Qt application for QObject functionality
    QCoreApplication app(argc, argv);

    // Create nursery instance (Facade Pattern)
    Nursery *nursery = new Nursery();

    bool running = true;

    // Welcome message
    clearScreen();
    displayHeader();
    cout << "Welcome to the Chaotic Plants Nursery Management System!\n";
    cout << "This demonstration showcases multiple design patterns working together.\n\n";
    cout << "Press Enter to begin...";
    cin.get();

    while (running)
    {
        clearScreen();
        displayHeader();
        displayMainMenu();

        int choice;
        cin >> choice;

        // Clear input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            completeIntegratedDemo(nursery);
            break;
        case 2:
            customerJourneyDemo(nursery);
            break;
        case 3:
            plantLifecycleDemo(nursery);
            break;
        case 4:
            seasonalChangesDemo(nursery);
            break;
        case 5:
            plantDecorationDemo(nursery);
            break;
        case 6:
            stockManagementDemo(nursery);
            break;
        case 7:
            staffAssignmentDemo(nursery);
            break;
        case 8:
            displayNurseryStatus(nursery);
            break;
        case 9:
            displayDesignPatterns();
            break;
        case 0:
            cout << "\n╔══════════════════════════════════════════════════════════════╗\n";
            cout << "║                    THANK YOU! 🌱                             ║\n";
            cout << "╚══════════════════════════════════════════════════════════════╝\n\n";
            cout << "Thank you for exploring Chaotic Plants Nursery Simulation!\n\n";
            cout << "Design Patterns Demonstrated:\n";
            cout << "  ✓ Facade Pattern - Simplified system interface\n";
            cout << "  ✓ State Pattern - Dynamic behavior changes\n";
            cout << "  ✓ Factory Method - Object creation abstraction\n";
            cout << "  ✓ Command Pattern - Encapsulated operations\n";
            cout << "  ✓ Observer Pattern - Event notification system\n";
            cout << "  ✓ Strategy Pattern - Interchangeable algorithms\n";
            cout << "  ✓ Decorator Pattern - Dynamic feature addition\n\n";
            cout << "Exiting...\n";
            running = false;
            break;
        default:
            cout << "\n❌ Invalid choice. Please enter a number from 0-9.\n";
            pauseScreen();
        }
    }

    // Cleanup
    delete nursery;

    return 0;
}
