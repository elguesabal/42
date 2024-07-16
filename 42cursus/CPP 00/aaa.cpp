#include <iostream>

// CIN
// GOTO
// OR
// int main(void) {
// 	char letra;

// 	inicio:
// 	std::cout << "repetir? [s/n] ";
// 	std::cin >> letra;

// 	if (letra == 's' or letra == 'y')
// 		goto inicio;

// 	return (0);
// }


int main(int argc, char **argv) {

	std::cout << argv[1] << std::endl;

	argc++;

	if (argc < 10)
		main(argc, argv);

	return (0);
}