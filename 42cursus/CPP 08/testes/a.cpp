#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <exception>

// ofstream
// int main(void) {
// 	std::ofstream file;

// 	file.open("vampeta.txt", std::ios::app);
// 	file << "vampeta" << std::endl;
// 	file.close();
// 	return (0);
// }



// ifstream
// int main(void) {
// 	std::ifstream file;
// 	std::string line;

// 	file.open("vampeta.txt");
// 	if (!file.is_open()) {
// 		std::cout << "erro ao abrir arquivo" << std::endl;
// 		return (0);
// 	}
// 	while (getline(file, line))
// 		std::cout << line << std::endl;
// 	file.close();
// 	return (0);
// }



// fstream
// int main(void) {
// 	std::fstream file;
// 	std::string line;

// 	file.open("vampeta.txt", std::ios::out | std::ios::app);
// 	if (!file.is_open())
// 		std::cout << "erro ao abrir arquivo" << std::endl;
// 	do {
// 		std::cin >> line;
// 		if (line != "exit")
// 			file << line << std::endl;
// 	} while (line != "exit");
// 	file.close();

// 	file.open("vampeta.txt", std::ios::in);
// 	if (!file.is_open())
// 		std::cout << "erro ao abrir arquivo" << std::endl;
// 	while (getline(file, line))
// 		std::cout << line << std::endl;
// 	file.close();
// 	return (0);
// }



// iteretor
// advance
// next
// prev
// int main(void) {
// 	std::vector <std::string> produtos = {"mouse", "teclado", "monitor", "gabinete", "caixa de som"};
// 	std::vector <std::string>::iterator it = produtos.begin();

// 	// advance(it, 2);
// 	// std::cout << *it << std::endl;

// 	// std::cout << *next(it, 2) << std::endl;

// 	// it = produtos.end() - 1;
// 	// std::cout << *prev(it, 4) << std::endl;

// 	return (0);
// }



// try catch
double divide(double n1, double n2) {
	if (n2 == 0)
		throw ("Erro de divisao por zero");
	return (n1 / n2);
}

int main(void) {
	double n1, n2;

	std::cin >> n1 >> n2;
	try {
		std::cout << divide(n1, n2) << std::endl;
	} catch (const char *error) {
		std::cout << "ERRO: " << error << std::endl;
	}
	return (0);
}