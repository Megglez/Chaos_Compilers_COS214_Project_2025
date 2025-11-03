/**
 * @file Cashiers.h
 * @brief Cashier staff class for handling customer transactions
 * 
 * Defines the Cashiers class which manages customer checkout operations
 * and uses the Iterator pattern to process the customer queue.
 * 
 * @author Chaos_Compilers
 * @date 2025
 */

#ifndef CASHIERS_H
#define CASHIERS_H

#include <iostream>
#include <string>
#include "Staff.h"
#include "ConcreteAggregate.h"

class Inventory;
class Customer;

/**
 * @class Cashiers
 * @brief Staff member responsible for processing customer transactions
 * 
 * This class represents cashier staff members who handle customer checkouts.
 * Uses the Iterator pattern to process customers in the queue, making customers
 * with empty baskets leave the nursery.
 */
class Cashiers : public Staff
{
private:
	ConcreteAggregate* customerQueue;  ///< Aggregate managing customer queue
	Customer *currentCustomer;         ///< Currently being served customer

public:
	Inventory *subject;  ///< Inventory subject for observer pattern

	/**
	 * @brief Processes a transaction for the current customer
	 * 
	 * Handles the checkout process for the customer currently being served.
	 */
	void makeTransaction();

	/**
	 * @brief Gets the type of staff member
	 * @return String "Cashier"
	 */
	std::string getStaffType();

	/**
	 * @brief Checks if cashier can handle customer enquiries
	 * @return false - cashiers don't handle enquiries
	 */
	bool canHandleEnquiry();

	/**
	 * @brief Performs the cashier's duty
	 * 
	 * Processes transactions for customers in the queue.
	 */
	void performDuty();

	/**
	 * @brief Empties the current customer's basket
	 * 
	 * Clears all items from the customer's basket after transaction.
	 */
	void emptyBasket();

	/**
	 * @brief Processes the customer queue using iterator pattern
	 * 
	 * Iterates through all customers in the queue and makes customers
	 * with empty baskets leave the nursery. This demonstrates the
	 * Iterator design pattern in action.
	 */
	void processCustomerQueue();

	/**
	 * @brief Adds a customer to the checkout queue
	 * @param customer Pointer to the customer to add
	 */
	void addToQueue(Customer* customer);

	/**
	 * @brief Gets the customer queue aggregate
	 * @return Pointer to the ConcreteAggregate managing the queue
	 */
	ConcreteAggregate* getQueue() { return customerQueue; }

	/**
	 * @brief Constructs a Cashier staff member
	 * @param name The cashier's name
	 * @param id The cashier's ID
	 */
	Cashiers(std::string& name, std::string& id);

	/**
	 * @brief Destroys the Cashier and cleans up resources
	 */
	virtual ~Cashiers();
};

#endif