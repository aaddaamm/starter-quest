#ifndef WIZARD_H
#define WIZARD_H

#include "../baseClasses/Character.h"

class Wizard : public Character {
  public:
    Wizard(
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