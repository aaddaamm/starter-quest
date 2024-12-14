#ifndef CLERIC_H
#define CLERIC_H

#include "../baseClasses/Character.h"

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
