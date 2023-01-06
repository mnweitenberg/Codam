# include "../inc/Zombie.hpp"

void randomChump(std::string name) {
	Zombie	randomChump = Zombie(name);
	randomChump.announce();
}
