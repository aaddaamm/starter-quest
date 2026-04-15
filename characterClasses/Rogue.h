#ifndef ROGUE_H
#define ROGUE_H

#include "Wanderer.h"
#include "Character.h"

class Rogue : public Wanderer {
  public:
    Rogue();

    void vocation() override;
    void attack() override;
    void defend() override;

    Stats getBaseStats() override;
    int rollAttack(const Stats& stats) override;
    int getDefense(const Stats& stats) override;
};

#endif
