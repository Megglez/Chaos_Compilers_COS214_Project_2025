/**
 * @file main.cpp
 * @brief Entry point for the nursery simulation application
 * 
 * Initializes the Qt application and launches the main window GUI
 * for the plant nursery simulation system.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#include <QApplication>
#include "mainwindow.h" // Include the actual main window header

/**
 * @brief Main function - application entry point
 * 
 * Creates the QApplication instance, instantiates and displays the
 * MainWindow, and starts the Qt event loop.
 * 
 * @param argc Number of command-line arguments
 * @param argv Array of command-line arguments
 * @return Exit code from the application event loop
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Instantiate and show the MainWindow, which is the window defined by the UI file.
    MainWindow w; 
    w.show();

    return a.exec();
}