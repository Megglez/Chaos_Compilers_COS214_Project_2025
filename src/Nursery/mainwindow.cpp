/**
 * @file mainwindow.cpp
 * @brief Implementation of the MainWindow GUI class
 * 
 * Contains the implementation of all MainWindow methods for coordinating
 * the nursery simulation through the Qt GUI framework.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#include "mainwindow.h"
#include "ui_mainwindow.h" // Assuming you fixed the "./ui_mainwindow.h" path

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize the nursery first
    nursery = new Nursery(this);

    // Initialize clocks
    plantClock = new PlantClock(this);
    seasonClock = new SeasonClock(this);
    customerClock = new CustomerClock(this);

    // 2. Connect Signals to Slots
    
    // Plant Clock Connection
    connect(plantClock, &PlantClock::plantUpdate, 
            this,       &MainWindow::handlePlantUpdate);
    
    // Season Clock Connection (Note the enum parameter)
    connect(seasonClock, &SeasonClock::seasonChanged, 
            this,        &MainWindow::handleSeasonChange);
            
    // Customer Clock Connection
    connect(customerClock, &CustomerClock::customerArrived, 
            this,          &MainWindow::handleCustomerArrival);
    
    // 3. Start the timers
    plantClock->startPlantClock();
    seasonClock->startSeasonClock();
    customerClock->startCustomerClock();

    qDebug() << "All Clocks initialized and running.";
}

MainWindow::~MainWindow()
{
    delete ui;
    // Clocks are parented to 'this', so they are deleted automatically.
}

// --- Specialized Event Handlers ---

void MainWindow::handlePlantUpdate()
{
    qDebug() << "ACTION: Update all plant growth/water/health status.";
    if (nursery) {
        nursery->getInventory()->action();
        nursery->getStock()->printStock();
    }
}

void MainWindow::handleSeasonChange(Season newSeason)
{
    QString seasonName;
    switch (newSeason) {
        case SPRING: seasonName = "Spring"; break;
        case SUMMER: seasonName = "Summer"; break;
        case AUTUMN: seasonName = "Autumn"; break;
        case WINTER: seasonName = "Winter"; break;
    }
    qDebug() << "ACTION: SEASON CHANGED to" << seasonName;
    if (nursery) {
        nursery->updateSeason(newSeason);
    }
    if (nursery && nursery->getCurrentSeason()) {
        // Log the season change since we don't have UI labels yet
        qDebug() << "Season changed to:" << seasonName;
    }
}

void MainWindow::handleCustomerArrival()
{
    qDebug() << "ACTION: New customer has ARRIVED!";
    if (nursery) {
        nursery->handleCustomerArrivalSignal();
        // Log customer count since we don't have UI labels yet
        qDebug() << "Active Customers:" << nursery->getActiveCustomers().size();
    }
}