#ifndef CLERIC_H
#define CLERIC_H

#include "../baseClasses/Character.h"

//TODO: A cleric should be able to heal
//TODO: A cleric should be able to cast spells
//TODO: A cleric should be able to equip a weapon
//TODO: A cleric's attack should be modified by the weapon they have equipped

// Cleric class, inherits from Character
class Cleric : public Character {
  public:
    Cleric(
      const std::string& name,
      int age,
      int health,
      const std::string &race,
      const std::string &origin,
      const std::string &height,
      const std::string &weight
    );

    void chooseVocation() override;
    void attack() override;
};

#endif
