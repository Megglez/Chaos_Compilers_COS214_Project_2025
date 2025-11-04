/**
 * @file Purchasing.h
 * @brief Purchasing action state for customers ready to checkout
 *
 * This file defines the Purchasing class which represents a customer
 * proceeding to checkout with selected plants. Handles cashier queue
 * and payment processing.
 */

#ifndef PURCHASING_H
#define PURCHASING_H

#include "Action.h"
#include "../Greenhouse/Plant.h"
#include <vector>

class Customer;
class InfoDesk;

/**
 * @class Purchasing
 * @brief Represents a customer purchasing plants at checkout
 *
 * The Purchasing class is a concrete state in the State pattern, representing
 * a customer who has decided to buy plants and is proceeding to the cashier.
 * This state manages the checkout process including:
 * - Maintaining list of plants to purchase
 * - Quantities for each plant
 * - Interaction with cashier queue system
 *
 * Features:
 * - Single or multiple plant purchases
 * - Cashier queue management
 * - Final state before customer leaves
 * - Integration with payment system
 */
class Purchasing : public Action
{
public:
    /**
     * @brief Construct a Purchasing action for a single plant
     * @param plant Pointer to the plant to purchase
     * @param quantity Number of this plant to buy
     *
     * Creates a purchase action for one plant type.
     */
    Purchasing(Plant* plant, int quantity) : Action("Purchasing")
    {
        if (plant)
        {
            plantsToBuy.push_back(plant);
            quantities.push_back(quantity);
        }
    }

    /**
     * @brief Construct a Purchasing action for multiple plants
     * @param plants Vector of plants to purchase
     * @param quants Vector of quantities for each plant
     *
     * Creates a purchase action for multiple plant types.
     * Vectors must be the same size.
     */
    Purchasing(vector<Plant*> plants, vector<int> quants) : Action("Purchasing"), plantsToBuy(plants), quantities(quants) {}

    /**
     * @brief Virtual destructor
     */
    virtual ~Purchasing() {}

    /**
     * @brief Handle the purchasing action
     *
     * Displays what the customer is purchasing and processes the transaction.
     * Implements the Action interface.
     */
    void handle() override;

    /**
     * @brief Handle purchasing with customer context
     * @param customer The customer making the purchase
     *
     * Adds customer to cashier queue and processes checkout.
     */
    void handle(Customer* customer) override;

    /**
     * @brief Get the next action after purchasing
     * @return Action* Pointer to next action (nullptr as customer leaves)
     *
     * After purchasing, the customer leaves the nursery.
     * Returns nullptr to indicate completion.
     */
    Action* getNextAction() override;

    /**
     * @brief Request staff assistance for checkout
     * @param customer The customer requesting checkout assistance
     * @param desk Reference to the InfoDesk for staff coordination
     *
     * Directs customer to available cashier for payment processing.
     */
    void requestStaffAssistance(Customer* customer, InfoDesk& desk) override;

    /**
     * @brief Get the list of plants to purchase
     * @return vector<Plant*> Vector of plant pointers
     */
    vector<Plant*> getPlantsToBuy() const { return plantsToBuy; }

    /**
     * @brief Get the quantities for each plant
     * @return vector<int> Vector of quantities
     */
    vector<int> getQuantities() const { return quantities; }

private:
    /**
     * @brief Plants the customer is purchasing
     */
    vector<Plant *> plantsToBuy;

    /**
     * @brief Quantities for each plant to purchase
     */
    vector<int> quantities;
};
#endif