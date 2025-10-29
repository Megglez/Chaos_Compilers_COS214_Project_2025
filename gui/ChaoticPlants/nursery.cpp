#include "nursary.h"
#include "./ui_nursary.h"

Nursary::Nursary(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Nursary)
{
    ui->setupUi(this);
}

Nursary::~Nursary()
{
    delete ui;
}
