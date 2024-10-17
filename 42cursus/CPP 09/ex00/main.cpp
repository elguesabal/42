#include " BitcoinExchange.hpp"

int main(int argc, char **argv) {
	try {
		BitcoinExchange teste(argc, argv[1]);
	} catch (std::exception &error) {
		std::cout << "Error: " << error.what() << std::endl;
		return (0);
	}
	return (0);
}