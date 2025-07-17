#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Stats.h"

#include "../characterClasses/CharacterClass.h"

// Character class, the base class for all characters
// TODO: i need to allow all classes to access the character's Name
class Character {
protected:
  std::string name;
  int health;
  int experience;
  int level;

  Stats baseStats;

  CharacterClass* characterClass;
public:
  Character(const std::string& name, int health);

  // Setters and getters
  void setCharacterClass(CharacterClass* characterClass);
  void addExperience(int experience);
  void renameCharacter(const std::string& newName);

  CharacterClass* getCharacterClass() const;
  std::string getName() const;
  int getHealth() const;
  int getExperience() const;
  int getLevel() const;

  // Delegated class methods
  void vocation();
  void attack();
  void defend();

  // Destructor for the character class
  virtual ~Character();
};

#endif
