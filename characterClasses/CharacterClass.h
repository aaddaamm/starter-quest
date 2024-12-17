#ifndef CHARACTERCLASS_H
#define CHARACTERCLASS_H

// CharacterClass is an abstract class
class CharacterClass {
  public:
    virtual void vocation() = 0;
    virtual void attack() = 0;
    virtual void defend() = 0;
    virtual ~CharacterClass() = default;
};

#endif
