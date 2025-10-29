#ifndef NURSARY_H
#define NURSARY_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Nursary;
}
QT_END_NAMESPACE

class Nursary : public QMainWindow
{
    Q_OBJECT

public:
    Nursary(QWidget *parent = nullptr);
    ~Nursary();

private:
    Ui::Nursary *ui;
};
#endif // NURSARY_H
