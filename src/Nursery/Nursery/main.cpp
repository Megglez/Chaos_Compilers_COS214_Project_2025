#include <QApplication>
#include "mainwindow.h" // Include the actual main window header

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Instantiate and show the MainWindow, which is the window defined by the UI file.
    MainWindow w; 
    w.show();

    return a.exec();
}