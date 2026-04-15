#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "baseClasses/Character.h"
#include "baseClasses/Creature.h"
#include "characterClasses/Wanderer.h"
#include "characterClasses/Cleric.h"
#include "characterClasses/Rogue.h"
#include "characterClasses/Warrior.h"
#include "characterClasses/Wizard.h"

// Prompts the player to pick a vocation and returns the chosen CharacterClass.
CharacterClass* pickVocation() {
  std::cout << "\nChoose your vocation:\n";
  std::cout << "  1. Warrior  (STR 16 / CON 14 — tough melee fighter)\n";
  std::cout << "  2. Wizard   (INT 16 / WIS 14 — powerful spells, fragile)\n";
  std::cout << "  3. Rogue    (DEX 16 / CHA 14 — fast and precise)\n";
  std::cout << "  4. Cleric   (WIS 16 / CON 12 — holy strikes, durable)\n";
  std::cout << "  5. Wanderer (balanced — all stats 10)\n";
  std::cout << "> ";

  int choice = 5;
  if (!(std::cin >> choice)) {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
  }

  switch (choice) {
    case 1: return new Warrior();
    case 2: return new Wizard();
    case 3: return new Rogue();
    case 4: return new Cleric();
    default: return new Wanderer();
  }
}

// Runs one round of combat between character and creature.
// Returns true if the character is still alive after the round.
bool combatRound(Character* character, Creature* creature) {
  // Character attacks
  int attackRoll = character->rollAttack();
  int creatureHpBefore = creature->getHealth();
  character->attack();
  creature->takeDamage(attackRoll);
  int actualDamage = creatureHpBefore - creature->getHealth();
  std::cout << "  -> Deals " << actualDamage << " damage. "
            << creature->getName() << " HP: " << creature->getHealth() << "\n";

  if (!creature->isAlive()) return true;

  // Creature attacks back
  int creatureDamage = creature->rollAttack();
  int blocked = character->getDefense();
  int netDamage = creatureDamage - blocked;
  if (netDamage < 0) netDamage = 0;

  character->defend();
  character->takeDamage(netDamage);
  std::cout << "  -> " << creature->getName() << " deals " << creatureDamage
            << " (blocked " << blocked << "). "
            << character->getName() << " HP: " << character->getHealth() << "\n";

  return character->isAlive();
}

int main() {
  srand(static_cast<unsigned>(time(nullptr)));

  std::string heroName;
  std::cout << "Enter your hero's name: ";
  std::cin >> heroName;

  Character* hero = new Character(heroName, 100);
  hero->setCharacterClass(pickVocation());
  hero->vocation();

  // Create a goblin encounter
  Creature* goblin = new Creature("Goblin", 30, 4, 1);

  std::cout << "\n--- A wild " << goblin->getName() << " appears! ---\n";
  std::cout << goblin->getName() << " HP: " << goblin->getHealth() << "\n\n";

  int round = 1;
  while (hero->isAlive() && goblin->isAlive()) {
    std::cout << "Round " << round++ << ":\n";
    bool heroSurvived = combatRound(hero, goblin);
    std::cout << "\n";
    if (!heroSurvived) break;
  }

  if (hero->isAlive()) {
    std::cout << hero->getName() << " defeated the " << goblin->getName() << "!\n";
  } else {
    std::cout << hero->getName() << " was defeated by the " << goblin->getName() << "...\n";
  }

  delete goblin;
  delete hero;

  return 0;
}
