#include <iostream>
#include <fstream>


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
int main(void) {
	std::fstream file;
	std::string line;

	file.open("vampeta.txt", std::ios::out | std::ios::app);
	if (!file.is_open())
		std::cout << "erro ao abrir arquivo" << std::endl;
	do {
		std::cin >> line;
		if (line != "exit")
			file << line << std::endl;
	} while (line != "exit");
	file.close();

	file.open("vampeta.txt", std::ios::in);
	if (!file.is_open())
		std::cout << "erro ao abrir arquivo" << std::endl;
	while (getline(file, line))
		std::cout << line << std::endl;
	file.close();
	return (0);
}