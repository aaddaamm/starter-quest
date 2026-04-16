#ifndef ITEM_H
#define ITEM_H

#include <string>

enum class ItemType { Key, Consumable, Equipment };

class Item {
public:
  Item(const std::string& name, const std::string& description, ItemType type);

  std::string getName() const;
  std::string getDescription() const;
  ItemType getType() const;
  bool isConsumed() const;

  void consume();

private:
  std::string name;
  std::string description;
  ItemType type;
  bool consumed;
};

#endif
