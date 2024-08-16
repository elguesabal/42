#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl log;

	if (argc == 2)
		log.complain(argv[1]);
	else
		std::cout << "Wrong number of arguments!" << std::endl;

	return (0);
}
