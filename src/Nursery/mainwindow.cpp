#include "mainwindow.h"
#include "ui_mainwindow.h" // Assuming you fixed the "./ui_mainwindow.h" path

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1. Initialize and start the three clocks
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
    // Call functions in your Nursery simulation class here.
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
    // Update UI labels and change conditions for plants/customers in the Nursery.
}

void MainWindow::handleCustomerArrival()
{
    qDebug() << "ACTION: New customer has ARRIVED!";
    // Call your Nursery function to create a new Customer object.
}