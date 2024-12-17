#ifndef CHARACTERCLASS_H
#define CHARACTERCLASS_H

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
    virtual ~CharacterClass() = default;
};

#endif
