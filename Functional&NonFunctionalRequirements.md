<h1 align="center">COS214 Project</h1>
<h1 align="center">Functional and Non-Functional Requirements</h1>
<h1 align="center">Group: Chaos Compilers</h1>

<p align="center">
  u23608821 - Megan Lai </br>
  u23544563 - Inge Keyser </br>
  u24827313 - Blessing Gibendi </br>
  u24607526 - Divo Köhler </br>
  u23526964 - Langa Vakalisa </br>
</p>

</br>
</br>
</br>

<h2 align="center">Functional Requirements</h2>
</br>
<ol>
  <li>The system will manage different plant states based on the care it has been given over a period of time in order to track the plant’s development and needs so that the correct care strategy can be determined (State).</li>
</br>
  <li>The system will allow a customer to change their state in terms of their current actions in order to simulate the movement of a customer within the nursery (State).</li>
</br>
  <li>The system shall allow a staff member to change their state according to whether they are busy or available so that the info desk can appoint an available staff member to a customer who requires help (State).</li>
</br>
  <li>The system shall be allowed to add and remove stock from the inventory representing the inflow of plants when new stock of plants is added to the inventory and the outflow of plants when plants have been purchased by customers or have died (Command).</li>
</br>
  <li>The system shall create new plant instances by cloning existing plant prototypes so that the nursery’s inventory has more than one plant of each type (Prototype).</li>
</br>
  <li>The system shall be able to create different types of plants so that the customers have a variety of plants that they can browse and purchase (Factory Method).</li>
</br>
  <li>The system will apply different care strategies to plants based on the state of the plant to keep the plants alive and healthy (Strategy).</li>
</br>
  <li>The system will notify the Gardener when plants need assistance so that the   Gardener is able to provide the correct care strategy to the plant in need (Observer).</li>
</br>
  <li>The system shall allow a staff member to assist a customer in adding decorative features to their plant for aesthetic purposes (Decorator).</li>
</br>
  <li>The system will instantiate the initial objects of the nursery so that the application can function. This includes the different seasons, the plant factories, Stock, FindAvailableStaff, the clock objects and staff members. Further this system will manage the changes in seasons, the creation of customers and the plant growth. *Will also be the one component on one side of bridge if get gui to work (Façade).</li>
</br>
  <li>The system will iterate through the customers that are waiting in a queue to purchase their plants. If a customer has a dead plant this will be removed from their cart (Iterator).</li>
</br>
  <li>(Chain of Responsibility).</li>
</ol>

</br>
</br>

<h2 align="center">Non-Functional Requirements</h2>
</br>
<ol>
  <li><strong>Maintainability:</strong> The system shall have a modular design so that new plant types will be able to be added without changing the existing plant classes.</li>
</br>
  <li><strong>Reliability:</strong> The system will handle invalid user inputs with appropriate error messages to limit system downtime.</li>
</br>
  <li><strong>Extensibility:</strong> The system will allow the addition of new plant care strategies and plant decorations without having to change the original Strategy and Decorator design patterns.</li>
</ol>
