#include <iostream>
#include <list>

int main(void) {
	std::list<int> teste;

	for (int i = 0; i < 10; i++) {
		teste.push_back(i + 1);
	}

	for (std::list<int>::iterator it = teste.begin(); it != teste.end(); ++it) {
		std::cout << *it << std::endl;
	}

	return (0);
}