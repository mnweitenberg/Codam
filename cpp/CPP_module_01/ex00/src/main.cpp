#include "../inc/main.hpp"
#include "../inc/Zombie.hpp"
#include "../inc/newZombie.hpp"
#include "../inc/randomChump.hpp"

int main (void) {
	Zombie *zombie = newZombie("Zombie");
	zombie->announce();
	randomChump("randomChump");
	delete zombie;
	return (0);
}
