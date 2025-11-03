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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Slots to handle events from each clock
    void handlePlantUpdate();
    void handleSeasonChange(Season newSeason); // Takes the enum as a parameter
    void handleCustomerArrival();

private:
    Ui::MainWindow *ui;
    
    // Member pointers for all three specialized clocks
    PlantClock *plantClock;
    SeasonClock *seasonClock;
    CustomerClock *customerClock;
    Nursery *nursery;
};
#endif // MAINWINDOW_H