#include "nursery.h"
#include "./ui_nursery.h"

Nursery::Nursery(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Nursery)
{
    ui->setupUi(this);
}

Nursery::~Nursery()
{
    delete ui;
}
