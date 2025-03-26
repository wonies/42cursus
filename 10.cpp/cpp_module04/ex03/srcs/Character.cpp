#include "Character.hpp"

Character::Character(void) {}

Character::Character(const std::string &name) {
  _name = name;
  for (int i = 0; i < slot; i++) inventory[i] = NULL;
}

Character::Character(Character const &instance) { *this = instance; }

Character &Character::operator=(const Character &rhs) {
  if (this != &rhs) {
    _name = rhs._name;
    for (int i = 0; i < slot; i++) {
      if (inventory[i]) inventory[i] = rhs.inventory[i];
    }
  }
  return *this;
}

Character::~Character(void) {
  for (int i = 0; i < slot; i++)
    if (inventory[i]) delete inventory[i];
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria *m) {
  for (int i = 0; i < slot; i++) {
    if (!inventory[i]) {
      inventory[i] = m;
      break;
    }
  }
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= 4) {
    std::cout << "Invalid Slot INDEX." << std::endl;
    return;
  }
  if (inventory[idx]) {
    std::cout << "PUT HERE : " << inventory[idx]->getType() << std::endl;
    inventory[idx] = NULL;
  } else {
    std::cout << "Slot " << idx << "is already EMPTY" << std::endl;
  }
}

void Character::use(int idx, ICharacter &target) {
  if (idx < 0 || idx > slot) {
    std::cout << "Not Valid Index" << std::endl;
    return;
  } else if (inventory[idx] == NULL) {
    std::cout << "Not Valid Inven" << std::endl;
    return;
  } else
    this->inventory[idx]->use(target);
  // std::cout << "print" << std::endl;
  (void)target;
}

void Character::deleteInven(int idx) {
  if (inventory[idx]) {
    std::cout << "the add inven" << inventory[idx] << std::endl;
    delete inventory[idx];
    std::cout << "after delete the add inven" << &inventory[idx] << std::endl;

  } else {
    std::cout << "NOT VALID" << std::endl;
    return;
  }
  std::cout << "delete\n" << std::endl;
}