#include <iostream>



// int main(void) {
// 	// std::string str = "testando o teste";
// 	// std::string space = " ";

// 	// std::cout << str.find("teste") << std::endl;
// 	// std::cout << std::string::npos << std::endl;

// 	// str += space + &str[str.find("teste")];
// 	// std::cout << str << std::endl;

// 	std::cout << "teste" << std::endl;

// 	return (0);
// }




void teste(void);

int main(void) {
	void (*ptr)(void);

	ptr = teste;

	(*ptr)();

	return (0);
}

void teste(void) {
	std::cout << "teste" << std::endl;
}