#include <iostream>
#include <vector>

int main(void) {
	std::vector<int> teste;

	for (int i = 0; i < 10; i++) {
		teste.push_back(i + 1);
	}

	for (int i = 0; i < teste.size(); i++) {
		std::cout << teste[i] << std::endl;
	}

	return (0);
}