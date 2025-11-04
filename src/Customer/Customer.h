/**
 * @file Customer.h
 * @brief Customer entity class for the nursery system
 *
 * This file defines the Customer class which represents a customer in the nursery.
 * Customers have actions (states), shopping baskets, and can be assigned to staff
 * members for assistance. Uses Qt's QObject for signal/slot capabilities.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <vector>
#include <QObject>
#include "Action.h"
#include "Enquire.h"
#include "Browse.h"
#include "Purchasing.h"
#include "../Staff/Staff.h"
#include "../Greenhouse/Plant.h"

class InfoDesk;
class Nursery;
using namespace std;

/**
 * @class Customer
 * @brief Represents a customer in the nursery system
 *
 * The Customer class is the context in the State pattern, maintaining a reference
 * to the current Action (state). Customers can browse plants, ask questions at
 * the info desk, and make purchases. Each customer has a unique ID, a shopping
 * basket, and can be assigned to staff for assistance.
 *
 * Features:
 * - State pattern implementation with Action
 * - Shopping basket management
 * - Staff assignment for personalized service
 * - Unique customer identification
 * - Integration with nursery inventory system
 *
 * @note Inherits from QObject for Qt signal/slot mechanism
 */
class Customer : public QObject
{
	Q_OBJECT

public:
	/**
	 * @brief Construct a new Customer object
	 * @param action Initial action/state for the customer (Browse, Enquire, etc.)
	 * @param nursery Pointer to the nursery the customer is visiting
	 * @param parent Qt parent object for memory management (default: nullptr)
	 *
	 * Creates a customer with a unique ID and initial state.
	 */
	Customer(Action* action, Nursery* nursery, QObject* parent = nullptr);

	/**
	 * @brief Destroy the Customer object
	 *
	 * Cleans up action and any dynamically allocated resources.
	 */
	virtual ~Customer();

	/**
	 * @brief Request service or assistance
	 *
	 * Initiates the customer's current action, such as browsing or enquiring.
	 */
	void request();

	/**
	 * @brief Set a new action/state for the customer
	 * @param newAction Pointer to the new action (takes ownership)
	 *
	 * Transitions the customer to a new state, deleting the old action.
	 */
	void setAction(Action* newAction);

	/**
	 * @brief Process state transition to next action
	 *
	 * Calls getNextAction() on current action and transitions to it.
	 * If next action is nullptr, customer is leaving the nursery.
	 */
	void processNextAction();

	/**
	 * @brief Add plants to the customer's basket
	 * @param plants Pointer to the plant to add
	 * @param quantity Number of this plant to add
	 * @return true if successfully added, false otherwise
	 *
	 * Adds the specified quantity of a plant to the shopping basket.
	 */
	bool addToBasket(Plant* plants, int quantity);

	/**
	 * @brief Clear all items from the basket
	 *
	 * Empties the customer's shopping basket, typically after checkout.
	 */
	void clearBasket();

	/**
	 * @brief Get the customer's basket contents
	 * @return const std::vector<Plant*>& Reference to the basket
	 */
	const vector<Plant*>& getBasket() const { return basket; }

	/**
	 * @brief Get the customer's unique ID
	 * @return int The customer ID
	 */
	int getId() const;

	/**
	 * @brief Get the customer's current action
	 * @return Action* Pointer to the current action
	 */
	Action* getAction() const;

	/**
	 * @brief Get the nursery this customer is visiting
	 * @return Nursery* Pointer to the nursery
	 */
	Nursery* getNursery() const { return nursery; }

	/**
	 * @brief Assign a staff member to assist this customer
	 * @param staff Pointer to the staff member
	 */
	void setAssignedStaff(Staff* staff);

	/**
	 * @brief Get the currently assigned staff member
	 * @return Staff* Pointer to assigned staff, or nullptr if none
	 */
	Staff* getAssignedStaff() const { return assignedStaff; }

private:
	/**
	 * @brief Current action/state of the customer
	 */
	Action* action;

	/**
	 * @brief Unique identifier for this customer
	 */
	int id;

	/**
	 * @brief Customer's shopping basket containing selected plants
	 */
	vector<Plant*> basket;

	/**
	 * @brief Staff member currently assisting this customer (if any)
	 */
	Staff* assignedStaff = nullptr;

	/**
	 * @brief Reference to the nursery this customer is visiting
	 */
	Nursery* nursery;
};

#endif