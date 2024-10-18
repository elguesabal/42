#include " BitcoinExchange.hpp"

int main(int argc, char **argv) {
	try {
		BitcoinExchange bitcoin(argc, argv[1]);
		// bitcoin.print();
		bitcoin.readInput();
	} catch (std::exception &error) {
		std::cout << "Error: " << error.what() << std::endl;
		return (0);
	}

	return (0);
}