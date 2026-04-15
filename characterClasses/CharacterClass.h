#ifndef CHARACTERCLASS_H
#define CHARACTERCLASS_H

#include "Stats.h"

class Character;
// CharacterClass is an abstract class
class CharacterClass {
  protected:
    Character* character;

  public:
    void setCharacter(Character* character) {
      this->character = character;
    };

    virtual void vocation() = 0;
    virtual void attack() = 0;
    virtual void defend() = 0;

    // Returns the base stats for this vocation. Applied to the character
    // whenever this class is equipped.
    virtual Stats getBaseStats() {
      return Stats(10, 10, 10, 10, 10, 10);
    }

    // Returns damage dealt by this class. Uses the relevant primary stat.
    // Subclasses override to use the appropriate stat (STR, INT, DEX, etc.)
    virtual int rollAttack(const Stats& stats) {
      return stats.getStrength() / 4 + 1;
    }

    // Returns passive defense value for this class.
    virtual int getDefense(const Stats& stats) {
      return stats.getConstitution() / 4;
    }

    virtual ~CharacterClass() = default;
};

#endif
