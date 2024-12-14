#ifndef ROGUE_H
#define ROGUE_H

#include "../baseClasses/Character.h"

class Rogue : public Character {
  public:
    Rogue(
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
