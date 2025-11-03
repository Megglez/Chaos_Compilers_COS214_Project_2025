#include "src/Greenhouse/Planter.h"
#include "src/Greenhouse/HerbPlanter.h"
#include "src/Greenhouse/SucculentPlanter.h"
#include "src/Greenhouse/TreePlanter.h"
#include "src/Greenhouse/FlowerPlanter.h"
#include "src/Greenhouse/Plant.h"
#include "src/Greenhouse/TreePlant.h"
#include "src/Greenhouse/SucculentPlant.h"
#include "src/Greenhouse/FlowerPlant.h"
#include "src/Greenhouse/HerbPlant.h"
#include "src/Greenhouse/Stock.h"
#include "src/Greenhouse/Inventory.h"
#include "src/Greenhouse/Seasons.h"
#include "src/Greenhouse/AutumnCommand.h"
#include "src/Greenhouse/SummerCommand.h"
#include "src/Greenhouse/WinterCommand.h"
#include "src/Greenhouse/SpringCommand.h"
#include "src/Greenhouse/StateCommand.h"
#include "src/Greenhouse/PlantDecorator.h"
#include "src/Greenhouse/GiftWrap.h"
#include "src/Greenhouse/Pot.h"
#include "src/Greenhouse/SpecialArrangement.h"
#include "src/Nursery/Nursery.h"
#include <map>
#include <limits>
#include <string>
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    //creating the initial inventory
    //20 difference plants
    std::map<string,int>succulents= {{"Elephant Bush",10},{"Candelabra Aloe Vera",4},{"Jade",1},{"Red Pagoda",2},{"Portulaca",1}};

    std::map<string,std::pair<int,bool>>flowers= {{"Bush Lily",make_pair(12,false)},{"Hibiscus",make_pair(20,true)},{"Agapanthus",make_pair(13,false)},{"King Protea",make_pair(7,true)},{"Rose",make_pair(0,true)},{"Daisy",make_pair(2,false)},{"Poppy",make_pair(4,false)},{"Orchid",make_pair(0,true)}};

    std::map<string,int>trees= {{"Jacaranda",6},{"Acacia",4}};

    std::map<string,int>herbs= {{"Oregon",20},{"chives",24},{"parsley",22},{"sage",19}};
    
    SucculentPlanter* succulentP = new SucculentPlanter();
    FlowerPlanter* flowerP = new FlowerPlanter(false);
    FlowerPlanter* winterFlowerP = new FlowerPlanter(true);
    TreePlanter* treeP = new TreePlanter();
    HerbPlanter* herbP = new HerbPlanter();

    for(const auto& p : succulents)
    {
        std::unique_ptr<Plant> SuccP(succulentP->planterMethod(p.first));
        //Nursery->setStock(std::move(SuccP), pair.second);
    }

    for(const auto& p : flowers)
    {
        if(p.second.second) // is winter flower
        {
            std::unique_ptr<Plant> FlowP(winterFlowerP->planterMethod(p.first));
            
            continue;
        }
        std::unique_ptr<Plant> FlowP(flowerP->planterMethod(p.first));
        //Nursery->setStock(std::move(FlowP), pair.second.first);
    }
    
    for(const auto& pair : trees)
    {
        std::unique_ptr<Plant> treesP(treeP->planterMethod(pair.first));
        //Nursery->setStock(std::move(SuccP), pair.second);
    }

    for(const auto& pair : herbs)
    {
        std::unique_ptr<Plant> herbsP(herbP->planterMethod(pair.first));
        //Nursery->setStock(std::move(SuccP), pair.second);
    }

    //creating the different staff members idk how to unclude this in manageStaff function
    Cashiers* cashier1 = new Cashiers("Kyle","C001");
    Cashiers* cashier2 = new Cashiers("Sandra","C002");
    Cashiers* cashier3 = new Cashiers("Jenice","C003");

    Gardener* gardener1 = new Gardener("Micheal","G001");
    Gardener* gardener2 = new Gardener("Cindy","G002"); 
    Gardener* gardener3 = new Gardener("Eve","G003");

    SalesStaff* sales1 = new SalesStaff("Christene","S001");
    SalesStaff* sales2 = new SalesStaff("David","S002");
    SalesStaff* sales3 = new SalesStaff("Frank","S003");

    Manager* manager1 = new Manager("Susan","M001");
    Manager* manager2 = new Manager("George","M002");
    Manager* manager3 = new Manager("Hannah","M003");
    return 0;

    InfoDesk* infoDesk = new InfoDesk();
}

    void clearBuffer()
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int displayMenu()
    {
        int choice;
        cout<<"\n===============================\n";
        cout << "=== Nursery Management System ===" << endl;
        cout << "1. View Inventory" << endl;
        cout << "2. Manage Staff" << endl;
        cout << "3. Process Customer Orders" << endl;
        cout << "4. Process Garden Maintenance"<<endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if(cin.fail())
        {
            clearBuffer();
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            return -1;
        }
        return choice;
    }

    void displayInventory()
    {
        int choice;
        cout << "\nInventory Management Selected." << endl;
        //getInventory();
        cout << "1. Return To Menu" << endl;
        cout << "2. Exit" << endl;
        cin >> choice;
        if(cin.fail())
        {   
            clearBuffer();
            cout << "Invalid input. Please enter a number between 1 and 2." << endl;
            return;
        }
        switch(choice)
        {
            case 1:
                displayMenu();
            case 2:
                exit(0);
            default:
                cout << "Invalid choice. Returning to main menu." << endl;
        }
    }

    void handleStaff()
    {
        int choice;
        int managerChoice;
        cout << "\nStaff Management Select Staff Type." << endl;
        cout << "1. Sales Staff" << endl;
        cout << "2. Gardener Staff" << endl;
        cout << "3. Cashier Staff" << endl;
        cin>> managerChoice;
        switch(managerChoice)
        {
            case 1:
                int staffchoice;
                std::vector<Staff*> staffList = infoDesk->getStaffByType("Sales");
                cout<< "\nSales Staff Management." << endl;
                cout<< "1. Add a Sales Staff"<<endl;
                cout<< "2. Remove a Sales Staff"<<endl;
                cin>> staffchoice;
                switch(staffchoice)
                {
                    case 1:
                        //addSalesStaff();
                        break;
                    case 2:
                        //removeSalesStaff();
                        break;
                    default:
                        cout << "Invalid choice. Returning to main menu." << endl;
                }
                break;
            case 2:
             int staffchoice;
                std::vector<Staff*> staffList = infoDesk->getStaffByType("Gardener");
                cout<< "\nGardener Staff Management." << endl;
                cout<< "1. Add a Gardener Staff"<<endl;
                cout<< "2. Remove a Gardener Staff"<<endl;
                cin>> staffchoice;
                switch(staffchoice)
                {
                    case 1:
                        //addGardenerStaff();
                        break;
                    case 2:
                        //removeGardenerStaff();
                        break;
                    default:
                        cout << "Invalid choice. Returning to main menu." << endl;
                }
                break;
            case 3:
                int staffchoice;
                std::vector<Staff*> staffList = infoDesk->getStaffByType("Cashier");
                cout<< "\nCashier Staff Management." << endl;
                cout<< "1. Add a Cashier Staff"<<endl;
                cout<< "2. Remove a Cashier Staff"<<endl;
                cin>> staffchoice;
                switch(staffchoice)
                {
                    case 1:
                        //addCashierStaff();
                        break;
                    case 2:
                        //removeCashierStaff();
                        break;
                    default:
                        cout << "Invalid choice. Returning to main menu." << endl;
                }   
                break;
            default:
                cout << "Invalid choice. Returning to main menu." << endl;
        }

        cout << "1. Return To Menu" << endl;
        cout << "2. Exit" << endl;
        cin >> choice;
        if(cin.fail())
        {   
            clearBuffer();
            cout << "Invalid input. Please enter a number between 1 and 2." << endl;
            return;
        }
        switch(choice)
        {
            case 1:
                displayMenu();
            case 2:
                exit(0);
            default:
                cout << "Invalid choice. Returning to main menu." << endl;
        }
    }   

    void processCustomerOrders()
    {
        int choice;
        cout << "\nProcess Customer Orders Selected." << endl;
        //processOrders();
        cout << "1. Return To Menu" << endl;
        cout << "2. Exit" << endl;
        cin >> choice;
        if(cin.fail())
        {   
            clearBuffer();
            cout << "Invalid input. Please enter a number between 1 and 2." << endl;
            return;
        }
        switch(choice)
        {
            case 1:
                displayMenu();
            case 2:
                exit(0);
            default:
                cout << "Invalid choice. Returning to main menu." << endl;
        }
    }

    void processGardenMaintenance()
    {
        int choice;
        cout << "\nProcess Garden Maintenance Selected." << endl;
        //processMaintenance();
        cout << "1. Return To Menu" << endl;
        cout << "2. Exit" << endl;
        cin >> choice;
        if(cin.fail())
        {   
            clearBuffer();
            cout << "Invalid input. Please enter a number between 1 and 2." << endl;
            return;
        }
        switch(choice)
        {
            case 1:
                displayMenu();
            case 2:
                exit(0);
            default:
                cout << "Invalid choice. Returning to main menu." << endl;
        }
    }



