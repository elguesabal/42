#include <iostream>
#include <map>

int main(void) {
	std::map<int, int> teste;

	teste[3] = 3;
	teste[5] = 5;
	teste[1] = 1;

	std::cout << teste[3] << std::endl;
	std::cout << teste[2] << std::endl;
	std::cout << teste[1] << std::endl;

	return (0);
}