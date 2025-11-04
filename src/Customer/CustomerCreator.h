/**
 * @file CustomerCreator.h
 * @brief Factory class for creating customers with random attributes
 *
 * This file defines the CustomerCreator class which implements the Factory pattern
 * to create customers with randomized initial states, plant selections, and preferences.
 */

#ifndef CUSTOMERCREATOR_H
#define CUSTOMERCREATOR_H

#include <iostream>
#include "Customer.h"
#include "Browse.h"
#include "Enquire.h"
#include "../Greenhouse/Stock.h"
using namespace std;

class Nursery;

/**
 * @class CustomerCreator
 * @brief Factory for creating customers with random characteristics
 *
 * The CustomerCreator implements the Factory pattern to generate customers
 * with randomized attributes including:
 * - Initial state (Browse or Enquire)
 * - Plant selection (1-2 distinct plant types)
 * - Question types (advice vs. information questions)
 * - Plant decorations (GiftWrap, Pot, SpecialArrangement)
 *
 * This creates realistic customer behavior with variety in the simulation.
 *
 * Randomization features:
 * - Browse customers: Random plant selection, quantities, optional decorations
 * - Enquire customers: Random question type (advice or information)
 * - Ensures distinct plant types (no duplicates for same customer)
 * - Null-safe (handles null nursery pointers)
 */
class CustomerCreator
{
public:
    /**
     * @brief Construct a new CustomerCreator object
     *
     * Initializes the random number generator seed.
     */
    CustomerCreator();

    /**
     * @brief Destroy the CustomerCreator object
     */
    ~CustomerCreator();

    /**
     * @brief Factory method to create a new Customer with random attributes
     * @param nursery Pointer to the nursery (can be nullptr for testing)
     * @param stock Pointer to the available plant stock
     * @return Customer* Pointer to the newly created customer
     *
     * Creates a customer with:
     * - Random initial state (Browse ~50% or Enquire ~50%)
     * - Random plant selection (1-2 distinct types)
     * - Random quantities (1-10 per plant)
     * - Browse: Random decoration chance (50%) with random type (GiftWrap/Pot/SpecialArrangement)
     * - Enquire: Random question type - advice (50%) or information (50%)
     *
     * The customer is ready to interact with the nursery system.
     *
     * @note Takes ownership of the created customer; caller responsible for deletion
     */
    Customer* createNewCustomer(Nursery* nursery, Stock* stock);
};
#endif