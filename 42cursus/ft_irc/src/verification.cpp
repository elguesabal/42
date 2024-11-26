#include "header.h"

/// @brief FAZ UMA VERIFICACAO SE OS ARGUMENTOS DE INICIALIZACAO DO PROGRAMA SAO VALIDOS
/// @param argc NUMERO DE ARGUMENTOS PASSADO
/// @param argv ARRAY DE PONTEIRO COM OS ARGUMENTOS
/// @return RETORNA 0 CASO ESTEJA TUDO OK E 1 CASO EXISTA ALGUM ERRO NO ARGUMENTO
int validation(int argc, char **argv) {
	if (argc != 3) {
		std::cout << "Numero de argumentos invalido" << std::endl;
		return (1);
	}

	// if (strlen(argv[1]) > 15) { // O PRIMEIRO ARGUMENTO NAO E O IP
	// 	std::cout << "Primeiro argumento deve conter apenas um ip" << std::endl;
	// 	return (1);
	// }
	// for (int i = 0; argv[1][i]; i++) {
	// 	if (argv[1][i] != '.' && (argv[1][i] < '0' || argv[1][i] > '9')) {
	// 		std::cout << "Primeiro argumento deve conter apenas um ip" << std::endl;
	// 		return (1);
	// 	}
	// }

	if (strlen(argv[1]) > 5) {
		std::cout << "O segundo argumento deve conter apenas uma porta" << std::endl;
		return (1);
	}
	for (int i = 0; argv[1][i]; i++) {
		if (argv[1][i] < '0' || argv[1][i] > '9') {
			std::cout << "O segundo argumento deve conter apenas uma porta" << std::endl;
			return (1);
		}
	}
	if (std::atoi(argv[1]) < 1 || std::atoi(argv[1]) > 65535) {
		std::cout << "Para uma porta ser valida ela deve estar entre 1 e 65535" << std::endl;
		return (1);
	}

	if (!argv[2]) {
		std::cout << "A senha nao deve estar vazia" << std::endl;
		return (1);
	}
	return (0);
}