#include "Harl.hpp"

int main(void) {
	Harl log;

	log.complain("debug");
	std::cout << std::endl;
	log.complain("info");
	std::cout << std::endl;
	log.complain("warning");
	std::cout << std::endl;
	log.complain("error");
	std::cout << std::endl;

	return (0);
}
