#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <typename T> int easyfind(const T array, int n) {
	if (std::find(array.begin(), array.end(), n) == array.end())
		return (-1);
	return (n);
}

int main(void) {
	std::vector <int> n1;

	for (int i = 0; i < 5; i++)
		n1.push_back(i + 1);
	std::cout << "tamanho: " << n1.size() << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "n1: " << n1[i] << std::endl;
	std::cout << "easyfind(n, 3): " << easyfind(n1, 3) << std::endl;
	std::cout << "easyfind(n, 5): " << easyfind(n1, 5) << std::endl;
	std::cout << "easyfind(n, 10): " << easyfind(n1, 10) << std::endl << std::endl;



	std::list <int> n2;

	for (int i = 0; i < 5; i++)
		n2.push_back(i + 1);
	std::cout << "tamanho: " << n2.size() << std::endl;
	for (std::list <int>::iterator it = n2.begin(); it != n2.end(); ++it)
		std::cout << "n2: " << *it << std::endl;
	std::cout << "easyfind(n, 3): " << easyfind(n2, 3) << std::endl;
	std::cout << "easyfind(n, 5): " << easyfind(n2, 5) << std::endl;
	std::cout << "easyfind(n, 10): " << easyfind(n2, 10) << std::endl;

	return (0);
}