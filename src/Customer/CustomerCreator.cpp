#include "CustomerCreator.h"
#include <QDebug>

Customer* CustomerCreator::createNewCustomer(QObject* parent)
{
    Customer* newCustomer = new Customer(parent);
    qDebug() << "CustomerCreator: 🏭 A new customer has been successfully spawned.";
    
    // In a full implementation, you would set random customer traits here.
    
    return newCustomer;
}