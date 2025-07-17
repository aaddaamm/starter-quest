#include "catch_amalgamated.hpp"
#include "../baseClasses/Character.h"
#include "../characterClasses/Warrior.h"
#include "../characterClasses/Wanderer.h"

// Note on memory management:
// The Character class takes ownership of the CharacterClass pointer.
// Its constructor allocates a default Wanderer, and its destructor deletes it.
// To test setCharacterClass, we must pass a heap-allocated object (using new).

TEST_CASE("Character Core Functionality", "[Character]") {

    SECTION("Constructor and Initial State") {
        // The constructor should initialize all values correctly and allocate
        // a default Wanderer class.
        Character character("Test Character", 100);
        REQUIRE(character.getName() == "Test Character");
        REQUIRE(character.getHealth() == 100);
        REQUIRE(character.getExperience() == 0);
        REQUIRE(character.getLevel() == 1);
        REQUIRE(character.getCharacterClass() != nullptr);
    }

    SECTION("Changing Character Class") {
        Character character("Test Character", 100);
        
        // The old Wanderer pointer is managed by the character.
        // We create a new Warrior on the heap for the character to take ownership of.
        CharacterClass* warrior = new Warrior();
        character.setCharacterClass(warrior);

        REQUIRE(character.getCharacterClass() == warrior);
    }


    SECTION("Experience and Leveling Up") {
        Character character("Test Character", 100);

        // Add some experience, but not enough to level up
        character.addExperience(50);
        REQUIRE(character.getExperience() == 50);
        REQUIRE(character.getLevel() == 1);

        // Add more experience to reach level 2 (requires 100 total)
        character.addExperience(50);
        REQUIRE(character.getExperience() == 100);
        REQUIRE(character.getLevel() == 2);
        
        // Add more experience, but not enough to reach level 3 (requires 400 total)
        character.addExperience(200);
        REQUIRE(character.getExperience() == 300);
        REQUIRE(character.getLevel() == 2); // Still level 2
    }
}