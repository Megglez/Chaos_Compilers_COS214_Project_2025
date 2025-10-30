#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug> // <-- ADD THIS for console output

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1. Initialize the QTimer
    timer = new QTimer(this);

    // 2. Connect the timer's 'timeout' signal to your 'updateTimer' slot
    // The '&' syntax is the modern, safe way to connect signals and slots.
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);

    // 3. Start the timer (e.g., every 1000 milliseconds = 1 second)
    timer->start(1000); 

    qDebug() << "MainWindow initialized and QTimer started.";
}

MainWindow::~MainWindow()
{
    delete ui;
    // The 'timer' is parented to 'this', so it will be automatically deleted when 'MainWindow' is.
}

// 4. Implement the slot that runs on every timeout
void MainWindow::updateTimer()
{
    // This code runs every second
    static int counter = 0;
    counter++;
    qDebug() << "Timer Tick:" << counter;

    // You can update a QLabel or other UI element here
    // Example: ui->myLabel->setText(QString::number(counter));
}