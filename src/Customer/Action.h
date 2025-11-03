/**
 * @file Action.h
 * @brief Abstract base class for customer actions in the nursery system
 *
 * This file defines the Action abstract class which implements the State pattern
 * for managing customer behavior. Actions represent different states a customer
 * can be in, such as Browsing, Enquiring, or Purchasing.
 */

#ifndef ACTION_H
#define ACTION_H
#include <iostream>

// Forward declarations to break circular dependencies
class Customer;
class InfoDesk;
using namespace std;

/**
 * @class Action
 * @brief Abstract base class representing customer actions/states
 *
 * The Action class is part of the State pattern implementation where each
 * concrete action (Browse, Enquire, Purchasing) represents a different state
 * of customer behavior in the nursery. Actions define how customers interact
 * with the system and what transitions are possible.
 *
 * @note This is an abstract class and cannot be instantiated directly
 */
class Action
{
protected:
	/**
	 * @brief Name identifier for this action
	 */
	string name;

public:
	/**
	 * @brief Construct a new Action object
	 * @param actionName The name identifying this action (e.g., "Browsing", "Enquiring")
	 */
	Action(const string &actionName) : name(actionName) {}

	/**
	 * @brief Virtual destructor for proper cleanup of derived classes
	 */
	virtual ~Action() {}

	/**
	 * @brief Handle the action execution
	 *
	 * Pure virtual method that must be implemented by concrete action classes
	 * to define the behavior when this action is performed.
	 */
	virtual void handle() = 0;

	/**
	 * @brief Handle the action with customer context
	 * @param customer Pointer to the customer performing this action
	 *
	 * Default implementation calls the parameterless handle() method.
	 * Derived classes can override for customer-specific behavior.
	 */
	virtual void handle(Customer *customer) { handle(); }

	/**
	 * @brief Get the next action state for the customer
	 * @return Action* Pointer to the next action, or nullptr if customer is leaving
	 *
	 * Pure virtual method that defines state transitions. Each action determines
	 * what the next valid action(s) can be.
	 */
	virtual Action *getNextAction() = 0;

	/**
	 * @brief Request assistance from nursery staff
	 * @param customer The customer requesting assistance
	 * @param desk Reference to the InfoDesk for staff coordination
	 *
	 * Pure virtual method for handling staff assistance requests.
	 * Different actions may require different types of staff support.
	 */
	virtual void requestStaffAssistance(Customer *customer, InfoDesk &desk) = 0;

	/**
	 * @brief Get the name of this action
	 * @return string The action name
	 */
	string getActionName() const { return name; }

	/**
	 * @brief Check if this action matches a given name
	 * @param other_name The name to compare against
	 * @return true if names match, false otherwise
	 */
	bool matches(const string &other_name) const { return name == other_name; }
};

#endif