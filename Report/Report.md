<h1 align="center">COS214 Project</h1>
<h1 align="center">Report</h1>
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

## Table of Contents

1. [Research of the day to day operations of a nursery and the environmental factors that affect plants](#1-research-of-the-day-to-day-operations-of-a-nursery-and-the-environmental-factors-that-affect-plants)\
  1.1. [Horticultural Expertise and Plant Care (Staff)](#11-horticultural-expertise-and-plant-care-staff)\
  1.2. [Business Management and Commercial Viability](#12-business-management-and-commercial-viability)\
  1.3. [Community Engagement and Customer Relations (Staff)](#13-community-engagement-and-customer-relations-staff)
2. [Design Influences](#2-design-influences)\
  2.1. [Plant Merchandising and Customer Aesthetics](#21-plant-merchandising-and-customer-aesthetics)\
  2.2. [Horticultural Lifecycle Management](#22-horticultural-lifecycle-management)\
  2.3. [Staff Specialization and Operational Efficiency](#23-staff-specialization-and-operational-efficiency)\
  2.4. [Customer Interaction and System Robustness](#24-customer-interaction-and-system-robustness)
3. [Assumptions made](#3-assumptions-made)
4. [Design Patterns Used and Their Functional Requirements](#4-design-patterns-used-and-their-functional-requirements)\
  4.1. [Prototype](#41-prototype)\
  4.2. [Facade](#42-facade)\
  4.3. [Observer](#43-observer)\
  4.4. [Decorator](#44-decorator)\
  4.5. [Iterator](#45-iterator)\
  4.6. [Chain of Responsibility](#46-chain-of-responsibility)\
  4.7. [State](#47-state)\
  4.8. [Strategy](#48-strategy)\
  4.9. [Mediator](#49-mediator)\
  4.10. [Command](#410-command)\
  4.11. [Factory Method](#411-factory-method)
5. [Non-functional Requirements](#5-non-functional-requirements)
6. [UML Diagrams](#6-uml-diagrams)\
  6.1. [Class Diagram](#61-class-diagram)\
  6.2. [State Diagram](#62-state-diagram)\
  6.3. [Activity Diagram](#63-activity-diagram)\
  6.4. [Sequence Diagram](#64-sequence-diagram)\
  6.5. [Object Diagram](#65-object-diagram)\
  6.6. [Communication Diagram](#66-communication-diagram)
7. [References](#7-references)
8. [Links](#8-links)

</br>
</br>
</br>

## 1. Research of the day to day operations of a nursery and the environmental factors that affect plants
This report focuses specifically on nurseries, plant stock, and biomes relevant to the Pretoria region in South Africa. The successful operation of a commercial nursery is predicated on three integrated components: Plant Care, Business Management and Commercial Viability, and Community Engagement and Customer Relations.

### 1.1. Horticultural Expertise and Plant Care (Staff):
This component relies on specialized staff ("Staff") possessing comprehensive botanical knowledge. Their primary responsibilities include the intricate care of plant inventory to ensure optimal vitality. This includes all phases of the plant lifecycle, from correct planting protocols to sustainable harvesting techniques, tailored to the specific needs of diverse plant species and their microenvironments.

### 1.2. Business Management and Commercial Viability:
Beyond cultivation, commercial success requires robust management. This involves ensuring optimal stock levels, efficient operational management, and the necessary administrative functions to sustain the business. This oversight guarantees the enterprise remains commercially viable and capable of meeting market demand.

### 1.3. Community Engagement and Customer Relations (Staff):
The market viability of the nursery depends on its customer base. Staff serve a critical role in assisting consumers by providing expert advice, handling sales transactions (checkout), and managing customer inquiries. This establishes the essential link between the business and the purchasing community.

</br>

Staff members fulfill essential dual roles, integrating direct plant care with customer service and administrative support. Their duties are critical to both the biological and commercial health of the nursery.

The most efficient strategy for achieving rapid and sustained stock growth in the Pretoria region is to prioritize native plant species, which are naturally adapted to the local environment. 

The core South African flora that thrives here is categorized into three resilient types: succulents (like the Elephant Bush and Aloe Vera), which flourish in dry, warm conditions; drought-resistant flowering plants (such as the indigenous Protea, Agapanthus, and Century Plant); and resilient tree species (including the well-adapted Jacaranda and African Sumac). 

To provide consumers with accessible and hardy options, herbs are also stocked, known for their ability to recover quickly from neglect. However, consumer demand often extends to non-native ornamental plants, such as Roses or Petunias. While planting native stock ensures ecosystem stability and a reliable inventory, cultivating these non-native species requires staff to exert precise control over the microclimate. 

To successfully meet this demand, the nursery must meticulously manage environmental factors, including sunlight distribution, humidity levels, water consumption, soil type, and the manipulation of blooming seasons. This dual approach - leveraging the resilience of native plants while managing the environment for desired non-native species - is key to commercial success.
</br>
</br>
## 2. Design Influences

The core design of our system was directly influenced by three key components: Plant Selection and Customer Customization, Horticultural Lifecycle Management, and Operational Staffing Structure.

### 2.1. Plant Merchandising and Customer Aesthetics
Our approach to plant sales was heavily influenced by the bouquet concept, recognizing that customers desire multiple plant varieties in a single purchase. The most effective solution was the inclusion of a specialized decorator system. This feature allows for the aesthetic combination of different plant types without physically coupling them, offering the visual appeal of a bouquet while maintaining the individual integrity and distinct care requirements of each plant.

### 2.2. Horticultural Lifecycle Management
Environmental factors, particularly weather and lifecycle duration, significantly shaped the design. This led to the integration of perennial plants (such as succulents and slow-growing trees) into the stock system. These plants, which persist across multiple seasons, provide stable inventory and reflect the real-world complexity of plant growth cycles.

### 2.3. Staff Specialization and Operational Efficiency
The diverse requirements of running a commercial enterprise directly influenced our staffing structure. To optimize efficiency and competence across all functions, we implemented a system of job specialization. This ensures that employees are expertly trained for specific roles, improving the quality of both plant care and business management.

### 2.4. Customer Interaction and System Robustness
Integrating the abstract concept of the customer posed a significant design challenge. We resolved this by programming for customer dissatisfaction, where customers who cannot find a desired item will express their disappointment and leave, rather than entering a persistent, unresolvable waiting state (a "soft-lock"). This design choice not only adds realism but also significantly enhances the system's robustness and flow.
</br>
</br>

## 3. Assumptions made  
- We assume that the customers will always have enough money to buy the plants, therefore there will be no refusal of service or requirement of prices for plants.

- We assume that when first starting the game, there is a default plant in stock to sell.

- We assume the customer knows what plants we have stock and that they know they need to go to the help desk if they require help.

- The soil type is given by a number for the three different soil types: 
  1. Loamy soil is the most common used by most plants.
  2. Succulent soil, which is a mix of coarse sand, perlite and normal soil.
  3. Peat soil is used for herbs as well as some trees.
 
- Using water comes in  4 types:
  1.  Drought resistant plants like succulents and some types of flowers such as the century plant require watering every one or one and a half weeks.
  2.  Native species that are used to the climate require only watering every 4 to 6 days such as many of the shrubs, bamboo and herbs.
  3.  Saplings only require watering every 2-3 days with exceptions for drought resistant trees.
  4.  Many flowering plants usually require watering every single day.

- Amount of sunlight is ranked in the same way with 3 possibilities:
  1. Complete sun.
  2. Semi shaded.
  3. No/minimal sunlight.
 
- We made the assumption that if something is perennial, then it will grow and die after one season cycle.

-  Plants bloom mainly in the summer or winter. Spring and autumn are sowing and growing seasons, but still have a change of plants blooming during their season.

-  Plants that will be grown and sold in our nursery:\
   $\color{grey}{(Format: Plant name, Seeds planted season, Blooms season (winter or summer or perennial)).}$

   - Succulents:
     - Elephant bush, autumn, al, winter
     - Candelabra Aloe vera, winter, winter, perennial
     - Jade plant, all, all, perennial
     - red pagoda, winter, spring/summer,autumn
     - Portulaca, summer ,winter, summer

    - Flowering plants:
      - Bush lily, winter, summer, autumn
      - Wild hibiscus ,summer, winter, summer
      - Agapanthus, winter, summer ,autumn
      - King Protea, winter ,al, perennial
      - Roses, winter ,summer ,autumn
      - Daisy, winter ,summer, autumn
      - Poppy, winter ,summer ,autumn
      - Orchid, summer, winter ,spring

    - Trees:
      - Jacaranda, winter, spring ,perennial
      - Acacia tree ,winter, summer, perennial

    - Herbs:
      - Thymn,Oregon,chives parsley,sage, spring ,summer, perennial.
</br>

## 4. Design Patterns Used and Their Functional Requirements
### 4.1. Prototype
The inventory requires many plants to be grown within a set list of plants. The creation of new flowers is very expensive computation wise, hence, cloning allows for the right stock to be added to stock and inventory.

### 4.2. Facade
The system will initialise the initial objects of the nursery so that the application can run. This includes the different seasons, the plant factories, the clock objects, staff members and default plants in stock. Furthermore, this system will manage the changes in seasons, the creation of customers and the plant growth.

### 4.3. Observer
The system needs to be aware of both the current season and the current state of the plants as time passes in order to remove dead plants from inventory, plant seeds, harvest and add to the inventory and notify a gardener when a plant needs a specific care strategy.

The observers wait on signals sent from the subjects (the clocks). The clocks send signals at certain time intervals, when the observers receive these signals they do a process. The SeasonObserver lets the season state know to change seasons, the PlantObserver tells the plant to go to the next state and the CustomerCreator creates a customer.

### 4.4. Decorator
The system requires a way to provide bouquets of different plants and decorative aspects to the plant bundle such as pots and gift wrapping, as customers do not always buy types of plants in isolation.

### 4.5. Iterator
The system will iterate through the customers that are waiting in a queue to purchase their plants. If a customer has a dead plant this will be removed from their cart, if their cart is empty they leave.

### 4.6. Chain of Responsibility
Staff need to be able to assist customers but not all staff have the capacity to take care of customers, ensure the plants are cared for, and be cashiers, but a customer could need all these different types of staff depending on their individual needs

### 4.7. State
The system needs to be able to track the lifecycle of the plants to ensure that there is stock to sell and what plants to remove once out of season (dead) as well as to know when to plant and harvest the plants based on their stage of development.

The system needs to accommodate the different needs of a customer to ensure customer satisfaction. A customer has 3 states in which they can be in, namely browse, enquire or purchasing. 

The system needs staff members to change their state according to whether they are busy or available to show if they are helping a customer or are available to assist a new customer. This is achieved by an info desk that customers can go to as the info desk can appoint an available staff member to a customer who requires help.

### 4.8. Strategy
The system needs to provide a variety of different types of plants to sell all year round. These plant types require a different care strategy in order for them to grow and keep alive.

### 4.9. Mediator
The system requires a way for staff and customers to interact with each other  without allowing direct communication with all staff (staff with many customers or customers to other customers). The info desk acts as a mediator to ensure no coupling has taken place.

### 4.10. Command
The system needs to be able to add and remove stock from the inventory representing the inflow of plants when new stock of plants is added to the inventory and the outflow of plants when plants have been purchased by customers Not sure about this one need to ask blessing and check.

### 4.11. Factory Method
The nursery requires a way to produce plant objects that have many varying factors such as the type of plant, soil type, ect. in order to have stock.
</br>
</br>

## 5. Non-functional Requirements:
1. **Maintainability:** The system shall have a modular design so that new plant types will be able to be added without changing the existing plant classes.

2. **Reliability:** The system will handle invalid user inputs with appropriate error messages to limit system downtime.

3. **Extensibility:** The system will allow the addition of new plant care strategies and plant decorations without having to change the original Strategy and Decorator design patterns.
</br>

## 6. UML Diagrams
### 6.1. Class Diagram

<p align="center">
  
</p>
</br>

### 6.2. State Diagram

<p align="center">
  <img width="681" height="730" alt="State Diagram" src="https://github.com/user-attachments/assets/d5f189a7-03dc-4fa9-998a-0a363a069957" />
</p>
</br>

### 6.3. Activity Diagram

<p align="center">
  <img width="1202" height="734" alt="Activity Diagram" src="https://github.com/user-attachments/assets/8f06c59a-0baf-482b-a8d8-58c24cdee8d5" />
</p>
</br>

### 6.4. Sequence Diagram

<p align="center">
  <img width="800" height="751" alt="Sequence Diagram" src="https://github.com/user-attachments/assets/039f310f-3dea-42da-8e08-9439dc83e34b" />
</p>
</br>

### 6.5. Object Diagram

<p align="center">
  <img width="586" height="398" alt="Object Diagram" src="https://github.com/user-attachments/assets/f5cb6891-02a3-4d07-9346-622038ff29fb" />
</p>
</br>

### 6.6. Communication Diagram

<p align="center">
  <img width="1109" height="455" alt="Communication Diagram" src="https://github.com/user-attachments/assets/4e6819d7-70d8-458a-b308-43659d00335e" />
</p>
</br>

## 7. References
Admin, 2025. Different types of Succulents for Beginners [WWW Document]. Stanler Farms. URL https://www.stanlerfarms.co.za/different-types-of-succulents-for-beginners/ (accessed 10.30.25).

Indigenous Plant Nursery - Muldersdrift [WWW Document], n.d. . Guest House Accommodation. URL http://randomharvest.co.za (accessed 10.30.25).

Petal Faire Nursery in Pretoria Gauteng supplying unusual and exotic plants for the enthusiastic gardener [WWW Document], n.d. URL https://petalfaire.co.za/index.php?content=page&id=18&submenu=32 (accessed 10.30.25).

South Africa Online [WWW Document], n.d. . Discover the Beauty and Wonders of South Africa. URL http://southafrica.co.za (accessed 10.30.25).

Top 20 Most Common Plants in Gauteng [WWW Document], n.d. . PictureThis. URL https://www.picturethisai.com/region/South-Africa-Gauteng.html (accessed 10.30.25).

Tackling Design Patterns [WWW Document], n.d. URL https://www.cs.up.ac.za/cs/lmarshall/TDP/TDP.html (accessed 10.30.25). 
</br>
</br>

## 8. Links
GitHub Repository: https://github.com/Megglez/Chaos_Compilers_COS214_Project_2025

Google Document link: https://docs.google.com/document/d/1pNxXny8WA27NGEMK5c35jEXHrr4iKFu1k3Qw_p5Tn5Q/edit?usp=sharing

