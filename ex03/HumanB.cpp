#include "HumanB.hpp"
#include <cstddef>
#include <iostream>

HumanB::HumanB(std::string name) : weapon(NULL), name(name) {}

void HumanB::setWeapon(Weapon &weapon) { this->weapon = &weapon; }

void HumanB::attack() {
  if (!weapon) {
    std::cerr << name << " has no weapon" << std::endl;
    return;
  }
  std::cout << name << " attacks with their " << weapon->getType()
            << std::endl;
}
