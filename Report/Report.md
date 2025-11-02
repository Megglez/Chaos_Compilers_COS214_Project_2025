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

## 3. Assumptions made:  
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


