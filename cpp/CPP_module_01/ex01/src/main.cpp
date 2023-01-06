#include "../inc/main.hpp"
#include "../inc/Zombie.hpp"
#include "../inc/zombieHorde.hpp"

int main (void) {
	Zombie *Horde1 = zombieHorde(1, "Zombie1");
	Zombie *Horde10 = zombieHorde(10, "Zombie10");

	Horde1->announce();
	for (int i = 0; i < 10; i++) {
		Horde10[i].announce();
	}
	Horde1[0].announce();
	delete [] Horde10;
	delete [] Horde1;
	return (0);
}
