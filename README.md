# Coffee Machine Simulator  (C++ OOP Project)

This is an Object-Oriented Programming (OOP) project written in C++. It simulates a basic coffee vending machine system, with functionality for viewing a coffee menu, making coffee, tracking ingredient stock, and refilling supplies.

---

##  Project Goals

- Practice core OOP principles (encapsulation, composition).
- Build a CLI-based modular project with industry-standard file structure.

---

##  Features

- View available coffee menu.
- Select and make coffee if ingredients are available.
- Automatically checks and updates ingredient stock.
- Refill ingredients to default quantity.
- CLI menu system for user interaction.

---

- **Language**: C++
- **OOP Concepts**: Classes, Encapsulation, Composition......


---


##  How to Run

###  Compile

```bash
 g++ -I./include src/*.cpp -o coffee_machine

 ```bash

 ### Run
 ```bash
 ./coffee_machine



---

###  2. **UML Class Diagram**

Here’s a UML-style class layout for your project. You can convert this into a visual UML using tools like draw.io or PlantUML.

```plaintext
+-----------------+
|   Ingredient     |
+-----------------+
| - name: string   |
| - quantity: int  |
| - unit: string   |
+-----------------+
| +getName()       |
| +getQuantity()   |
| +getUnit()       |
| +setQuantity()   |
| +setUnit()       |
+-----------------+

         ▲
         |
         |
+------------------+
|     Coffee       |
+------------------+
| - name: string    |
| - ingredients: map<string, int> |
+------------------+
| +getName()        |
| +getIngredients() |
+------------------+

         ▲
         |
         |
+----------------------------+
|      CoffeeMachine         |
+----------------------------+
| - stocks: map<string, Ingredient> |
| - coffeeMenu: vector<Coffee>      |
+----------------------------+
| +showMenu()                |
| +makeCoffee(int)           |
| +refill()                  |
| +showStock()               |
| -hasIngredients(coffee)    |
| -useIngredients(coffee)    |
+----------------------------+




