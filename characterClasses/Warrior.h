
#ifndef WARRIOR_H
#define WARRIOR_H

#include "Wanderer.h"

class Warrior : public Wanderer {
  public:
    Warrior();

    void vocation() override;
    void attack() override;
    void defend() override;
};

#endif
