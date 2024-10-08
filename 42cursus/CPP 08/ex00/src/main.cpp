#include <iostream>
#include <vector>
#include <algorithm>

template <typename T> int easyfind(const T array, int n) {
	if (std::find(array.begin(), array.end(), n) == array.end()) // && n != array.end() (PQ NAO PRECISA VERIFICAR SE A ULTIMA POSICAO NAO E O PRIMEIRO ELEMENTO ENCONTRADO???)
		return (-1);
	return (n);
}

int main(void) {
	std::vector <int> n;

	for (int i = 0; i < 5; i++)
		n.push_back(i + 1);

	std::cout << "tamanho: " << n.size() << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "teste: " << n[i] << std::endl;

	std::cout << "easyfind(): " << easyfind(n, 3) << std::endl;
	std::cout << "easyfind(): " << easyfind(n, 5) << std::endl;
	std::cout << "easyfind(): " << easyfind(n, 10) << std::endl;

	return (0);
}