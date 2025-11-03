/**
 * @file mainwindow.h
 * @brief Main window class for the nursery simulation GUI
 * 
 * This class provides the main user interface for the nursery simulation,
 * coordinating all clock events and nursery operations through Qt's GUI framework.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "PlantClock.h"
#include "SeasonClock.h"
#include "CustomerClock.h"
#include "Nursery.h"
#include "../Greenhouse/Seasons.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief Main application window for the nursery simulation
 * 
 * This class serves as the primary GUI controller, managing the three
 * specialized clocks (plant, season, customer) and coordinating with
 * the Nursery facade to run the simulation. It connects all clock signals
 * to appropriate handler slots for processing simulation events.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs the MainWindow
     * 
     * Initializes the UI, creates all clocks and the nursery facade,
     * and connects signals to slots for event handling.
     * 
     * @param parent Optional parent widget
     */
    MainWindow(QWidget *parent = nullptr);
    
    /**
     * @brief Destroys the MainWindow
     * 
     * Cleans up UI and all dynamically allocated resources.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Handles plant update events from PlantClock
     * 
     * Processes plant state changes, growth, and maintenance updates.
     */
    void handlePlantUpdate();
    
    /**
     * @brief Handles season change events from SeasonClock
     * 
     * Updates the nursery to the new season and adjusts plant stock accordingly.
     * 
     * @param newSeason The new season to transition to
     */
    void handleSeasonChange(Season newSeason); // Takes the enum as a parameter
    
    /**
     * @brief Handles customer arrival events from CustomerClock
     * 
     * Creates and adds new customers to the nursery simulation.
     */
    void handleCustomerArrival();

private:
    Ui::MainWindow *ui;             ///< Qt Designer generated UI
    
    PlantClock *plantClock;         ///< Clock for plant update events
    SeasonClock *seasonClock;       ///< Clock for season transitions
    CustomerClock *customerClock;   ///< Clock for customer arrivals
    Nursery *nursery;               ///< Main nursery facade managing simulation
};
#endif // MAINWINDOW_H