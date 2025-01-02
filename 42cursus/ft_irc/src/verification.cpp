#include "header.h"

/// @brief FAZ UMA VERIFICACAO SE OS ARGUMENTOS DE INICIALIZACAO DO PROGRAMA SAO VALIDOS
/// @param argc NUMERO DE ARGUMENTOS PASSADO
/// @param argv ARRAY DE PONTEIRO COM OS ARGUMENTOS
void validation(int argc, char **argv) {
	if (argc != 3) {
		std::cout << "Numero de argumentos invalido" << std::endl;
		exit(1);
	}

	if (strlen(argv[1]) > 5) {
		std::cout << "O segundo argumento deve conter apenas uma porta" << std::endl;
		exit(1);
	}

	for (int i = 0; argv[1][i]; i++) {
		if (argv[1][i] < '0' || argv[1][i] > '9') {
			std::cout << "O segundo argumento deve conter apenas uma porta" << std::endl;
			exit(1);
		}
	}

	if (std::atoi(argv[1]) < 1 || std::atoi(argv[1]) > 65535) {
		std::cout << "Para uma porta ser valida ela deve estar entre 1 e 65535" << std::endl;
		exit(1);
	}

	if (argv[2][0] == '\0') {
		std::cout << "A senha nao deve estar vazia" << std::endl;
		exit(1);
	}
}