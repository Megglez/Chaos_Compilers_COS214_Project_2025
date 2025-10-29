#pragma once
#include "Customer.h"

class Stock; // Forward declaration

class CustomerSpawner
{
public:
    // Spawns a customer and assigns a random plant from the given stock
    Customer *spawnCustomer(Stock *stock);
};