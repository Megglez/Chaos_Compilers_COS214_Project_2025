#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer> // <-- ADD THIS

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots: // <-- ADD THIS SECTION
    void updateTimer();

private:
    Ui::MainWindow *ui;
    QTimer *timer; // <-- ADD THIS
};
#endif // MAINWINDOW_H