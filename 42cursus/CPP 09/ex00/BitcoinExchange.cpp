#include " BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const int argc, const char *argv) {
	openFile(argc, argv);
	readData();
}

void BitcoinExchange::openFile(const int argc, const char *argv) {
	if (argc != 2)
		throw (std::runtime_error("Numero de argumentos invalidos"));
		// throw (Error("Numero de argumentos invalidos")); // ACABEI CRIANDO ESSA CLASSE PQ NAO SABIA DA EXISTENCIA DA CLASSE std::runtime_error
	this->_input.open(argv);
	this->_data.open("data.csv");
	if (!this->_input.is_open() || !this->_data.is_open()) // AKI TALVEZ UM ABRA E O OUTRO NAO AI NESSE CASO DEVERIA DAR CLOSE NO ABERTO
		throw (std::runtime_error("Erro ao abrir arquivos"));
		// throw (Error("Erro ao abrir arquivos")); // ACABEI CRIANDO ESSA CLASSE PQ NAO SABIA DA EXISTENCIA DA CLASSE std::runtime_error
}

void BitcoinExchange::readData(void) { // FAZER AKI A LEITURA E GRAVACAO DO ARQUIVO data.csv
	std::string line;

	std::cout << "fazendo leitura" << std::endl;
	while (getline(_data, line)) {
		std::cout << line << std::endl; // TA SO LENDO E IMPRIMINDO
	}
	_data.close();
}

BitcoinExchange::~BitcoinExchange(void) {

}
