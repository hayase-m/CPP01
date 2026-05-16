#include "Zombie.hpp"
#include <iostream>
#include <new>

int main(void) {
  const int N = 5;

  try {
    Zombie *zombies = zombieHorde(N, "Foo");
    if (zombies == NULL) {
      std::cerr << "Invalid horde size" << std::endl;
      return 1;
    }
    for (int i = 0; i < N; i++)
      zombies[i].announce();
    delete[] zombies;
  } catch (const std::bad_alloc &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
