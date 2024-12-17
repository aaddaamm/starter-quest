#ifndef WIZARD_H
#define WIZARD_H

#include "Wanderer.h"

class Wizard : public Wanderer {
  public:
    Wizard();

    void vocation() override;
    void attack() override;
    void defend() override;
};

#endif
