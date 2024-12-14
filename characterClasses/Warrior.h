
#ifndef WARRIOR_H
#define WARRIOR_H

#include "../baseClasses/Character.h"

class Warrior : public Character {
  public:
    Warrior(
      const std::string& name,
      int age,
      int health,
      const std::string& race,
      const std::string& origin,
      const std::string& height,
      const std::string& weight
    );

    void chooseVocation() override;
    void attack() override;
};

#endif
