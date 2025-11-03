#include "nursery.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NurseryWindow w;
    w.show();
    return a.exec();
}
