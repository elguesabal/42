#include <iostream>
#include <fstream>

bool test(bool n, std::string str) {
	if (n)
		std::cout << str << std::endl;
	return (n);
}

void replaceLine(std::string *line, char *s1, char *s2) {
	std::size_t find;
(void)s2;

	do {
		find = line->find(s1);
		if (find != std::string::npos) {
			// std::cout << "s1 encontrado: " << line[0][1] << std::endl;
			line[0][find] = 'b'; // USAR O TAMANHO DA SUBSTRING PARA ACHAR A STRING RESTANTE A SER COPIADA
			// std::cout << "nova linha: " << line[0] << std::endl;
		}
		// std::cout << "find: " << find << std::endl;
	} while (find != std::string::npos);
}

int main(int argc, char **argv) {
	if (test(argc != 4, "Error: Numero de argumentos invalido"))
		return (1);
	// std::string file = argv[1];
	// std::string s1 = argv[2];
	// std::string s2 = argv[3];

	std::ifstream readFile(argv[1]);
	if (test(!readFile.is_open(), "Error: Arquivo nao existente"))
		return (1);

	std::ofstream writeFile("teste.txt.replace");
	if (test(!readFile.is_open(), "Error: Nao foi possivel criar o arquivo"))
		return (1);

	std::string line;
	while (std::getline(readFile, line)) {
		replaceLine(&line, argv[2], argv[3]);
		writeFile << line << std::endl;
	}

	readFile.close();
	writeFile.close();

	return (0);
}