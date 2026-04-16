#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Stats.h"

#include "../characterClasses/CharacterClass.h"

// Character class, the base class for all characters
class Character {
protected:
  int health;
  std::string name;
  CharacterClass* characterClass;
  Stats stats;

public:
  Character(const std::string& name, int health);
  void setCharacterClass(CharacterClass* characterClass);
  CharacterClass* getCharacterClass() const;

  std::string getName() const;
  int getHealth() const;
  bool isAlive() const;
  void takeDamage(int amount);

  // Returns damage this character deals on an attack roll
  int rollAttack() const;

  // Returns this character's passive defense value
  int getDefense() const;

  // Delegated class methods
  void vocation();
  void attack();
  void defend();

  // Destructor for the character class
  virtual ~Character();
};

#endif
