#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Stats.h"

#include "../characterClasses/CharacterClass.h"

// Character class, the base class for all characters
// TODO: i need to allow all classes to access the character's Name
class Character {
protected:
  int health;
  std::string name;
  CharacterClass* characterClass;

public:
  Character(const std::string& name, int health);
  void setCharacterClass(CharacterClass* characterClass);
  CharacterClass* getCharacterClass() const;

  std::string getName() const;
  int getHealth() const;

  // Delegated class methods
  void vocation();
  void attack();
  void defend();

  // Destructor for the character class
  virtual ~Character();
};

#endif
