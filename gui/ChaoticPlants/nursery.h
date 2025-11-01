#ifndef NURSERY_H
#define NURSERY_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Nursery;
}
QT_END_NAMESPACE

class Nursery : public QMainWindow
{
    Q_OBJECT

public:
    Nursery(QWidget *parent = nullptr);
    ~Nursery();

private:
    Ui::Nursery *ui;
};
#endif // NURSERY_H
