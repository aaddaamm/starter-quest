#ifndef CLERIC_H
#define CLERIC_H

// base class of all starter classes
#include "Wanderer.h"

//TODO: A cleric should be able to heal
//TODO: A cleric should be able to cast spells
//TODO: A cleric should be able to equip a weapon
//TODO: A cleric's attack should be modified by the weapon they have equipped

// Cleric class, inherits from Character
class Cleric : public Wanderer {
  public:
    Cleric();

    void vocation() override;
    void attack() override;
    void defend() override;

    void heal();
    void castSpell();
};

#endif
