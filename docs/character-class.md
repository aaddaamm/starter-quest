# possible character class approach

**1. Character Base Class:**

- **`Character`:**
  - **Attributes:**
    - `name`: std::string
    - `health`: int
    - `strength`: int
    - `agility`: int
    - `intelligence`: int
    - **`proficiencies`: std::map<std::string, int>`**
  - **Methods:**
    - Constructor to initialize attributes
    - Getters and Setters for attributes
    - `gainProficiency(const std::string& proficiency, int level`: Increases proficiency in a specific skill.

**2. Vocation Classes:**

- **`Warrior`:**

  - **Inherits from `Character`**
  - **Constructor:**
    - Calls the base class constructor (`Character`)
    - Sets initial `proficiencies` (e.g., `{"Swordsmanship", 1}, {"Axe Fighting", 1}`)
  - **Methods:**
    - `attack()` (overridden to use `strength` and `Swordsmanship` proficiency)
    - `defend()` (overridden to use `agility` and `Axe Fighting` proficiency)
    - `train(const std::string& skill)`: Increases proficiency in a specific skill.

- **`Mage`:**
  - **Inherits from `Character`**
  - **Constructor:**
    - Calls the base class constructor (`Character`)
    - Sets initial `proficiencies` (e.g., `{"Fire Magic", 1}, {"Ice Magic", 1}`)
  - **Methods:**
    - `castSpell()` (overridden to use `intelligence` and relevant magic proficiencies)

**3. Character Creation and Development:**

- **Character Creation:**

  1. Allow the player to choose a starting vocation (e.g., Warrior, Mage).
  2. Create an instance of the chosen vocation class.

- **Character Development:**
  - Implement a system where the player can train their character.
  - Call the `train(skill)` method on the character to increase proficiency in a specific skill.
  - Proficiencies can provide bonuses to relevant attributes or skills.

**4. Changing Vocations (Optional - Later Stage):**

- **Retaining Proficiencies:**
  - When changing vocations, allow the character to retain a portion of their existing proficiencies.
    - For example, a Warrior who switches to Mage might retain some proficiency in a combat skill that could be useful in melee combat as a Mage.
  - You could implement a system where some proficiencies are lost or reduced when switching vocations.

**5. Considerations:**

- **Balancing:** Carefully balance the effects of proficiencies to avoid making certain combinations overly powerful.
- **Flexibility:** Determine how much flexibility you want to give players in terms of changing vocations and retraining skills.
- **Game Mechanics:** Design game mechanics that encourage and reward character development and specialization.

**Implementation Notes:**

- Use C++ classes and inheritance to model the character hierarchy.
- Consider using a data-driven approach to define character attributes, proficiencies, and their effects.
- Thoroughly test your implementation to ensure that character development and vocation changes work as intended.

This approach allows for a degree of character customization and progression while still maintaining a degree of specialization based on the initial vocation choice. You can adjust the system based on your game's specific needs and desired complexity.
