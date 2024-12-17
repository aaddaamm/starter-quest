#ifndef WANDERER_H
#define WANDERER_H

#include "CharacterClass.h"

// while a wanderer is a starting class
// it can retain its own stats and abilites
class Wanderer : public CharacterClass {
  public:
    Wanderer();
    void vocation() override;
    void attack() override;
    void defend() override;
};

#endif
