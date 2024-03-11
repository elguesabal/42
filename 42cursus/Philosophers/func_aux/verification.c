#include "../philosophers.h"

int	verification(int argc, char **argv)
{
	if (argc < 5 || argc > 6) // ./philolosophers n morrer comer dormir [vzs]
		return (error("Error\nnumero de argumentos invalidos\n"));

	if (argv[1][0] == '\0' || argv[1][0] == '0' || is_number(argv[1]))
		return (error("Error\nnumero de filosofos invalido\n"));
	
	if (argv[2][0] == '\0' || argv[2][0] == '0' || is_number(argv[2]))
		return (error("Error\nnumero para morrer em ms invalido\n"));

	if (argv[3][0] == '\0' || argv[3][0] == '0' || is_number(argv[3]))
		return (error("Error\nnumero para comer em ms invalido\n"));

	if (argv[4][0] == '\0' || argv[4][0] == '0' || is_number(argv[4]))
		return (error("Error\nnumero para dormir em ms invalido\n"));

	if (argc == 6 && (argv[5][0] == '\0' || argv[5][0] == '0' || is_number(argv[5])))
		return (error("Error\nnumero de repeticoes invalido\n"));

	return (0);
}
