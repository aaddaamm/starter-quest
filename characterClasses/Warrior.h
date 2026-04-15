
#ifndef WARRIOR_H
#define WARRIOR_H

#include "Wanderer.h"
#include "Character.h"

class Warrior : public Wanderer {
  public:
    Warrior();

    void vocation() override;
    void attack() override;
    void defend() override;

    Stats getBaseStats() override;
    int rollAttack(const Stats& stats) override;
    int getDefense(const Stats& stats) override;
};

#endif
