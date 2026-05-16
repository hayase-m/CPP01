#include "Zombie.hpp"
#include <iostream>
#include <new>

int main(void) {
  try {
    Zombie *zombie = newZombie("Foo");
    zombie->announce();
    delete zombie;
  } catch (const std::bad_alloc &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  randomChump("Bar");
  return 0;
}
