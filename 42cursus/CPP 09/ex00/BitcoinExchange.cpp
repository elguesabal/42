#include " BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const int argc, const char *argv) {
	openFile(argc, argv);
	readData();
}

BitcoinExchange::~BitcoinExchange(void) {
	if (_input.is_open())
		_input.close();
	if (_datacsv.is_open())
		_datacsv.close();
}

void BitcoinExchange::openFile(const int argc, const char *argv) {
	if (argc != 2)
		throw (std::runtime_error("Numero de argumentos invalidos"));
		// throw (Error("Numero de argumentos invalidos")); // ACABEI CRIANDO ESSA CLASSE PQ NAO SABIA DA EXISTENCIA DA CLASSE std::runtime_error
	this->_input.open(argv);
	this->_datacsv.open("data.csv");
	if (!this->_input.is_open() || !this->_datacsv.is_open()) // AKI TALVEZ UM ABRA E O OUTRO NAO AI NESSE CASO DEVERIA DAR CLOSE NO ABERTO // SE EU CONFIGURAR O CONSTRUTOR PARA FECHAR OS ARQUIVOS NAO DEVO ME PREOCUPAR COM ISSO
		throw (std::runtime_error("Erro ao abrir arquivos"));
		// throw (Error("Erro ao abrir arquivos")); // ACABEI CRIANDO ESSA CLASSE PQ NAO SABIA DA EXISTENCIA DA CLASSE std::runtime_error
	std::string line;
	getline(this->_input, line);
	if (line != "date | value")
		throw (std::runtime_error("Cabecalho incorreto. Esperado 'date | value', mas foi encontrado outro formato"));
	getline(this->_datacsv, line);
	if (line != "date,exchange_rate")
		throw (std::runtime_error("Cabecalho incorreto. Esperado 'date,exchange_rate', mas foi encontrado outro formato"));
}

void BitcoinExchange::readData(void) { // FAZER AKI A LEITURA E GRAVACAO DO ARQUIVO data.csv
	std::string line, date, num;
	float price;
	// std::ostringstream oss;

	// std::cout << "fazendo leitura" << std::endl;
	while (getline(this->_datacsv, line)) {
		// std::cout << line << std::endl; // TA SO LENDO E IMPRIMINDO

		date = line.substr(0, line.find(','));
		// std::cout << date << std::endl;

		num = line.substr(line.find(',') + 1);
		// std::cout << num << std::endl;

		// this->_data[date] = 1.5;
		std::stringstream ss(num);
		ss >> price;
		this->_data[date] = price;
		// std::cout << std::fixed << std::setprecision(2) << this->_data[date] << std::endl; // AKI EU USO UM TIPO STRING
		// oss << this->_data[date];
		// std::cout << oss.str() << std::endl;
	}
	// std::cout << this->_data[date] << std::endl; // AKI EU USO UM TIPO STRING
	// std::cout << "teste: " << this->_data["2022-03-22"] << std::endl; // AKI EU USO UM TIPO char* ???

	_datacsv.close();
}

void BitcoinExchange::readInput(void) {
	std::string line;

	while (getline(this->_input, line)) {
		// std::cout << line << std::endl;
		validLine(line); // AKI EU DEVO USAR UM IF Q CASO RETORNE VERDADEIRO ENTRE NO IF
	}
	this->_input.close();
}

bool BitcoinExchange::validLine(const std::string &line) const {
	// std::cout << "teste function: " << line << std::endl;
	if (line.size() < 14) {
		std::cout << "Error: " << "bad input => " << line << std::endl;
		return (0);
	}
	
	// ACHO MELHOR AKI EU TER UMA VARIAVEL PRA ANO MES E DIA E AI COMPARAR COMO UM int
	if (line[0] != '2' || line[1] != '0' || (line[2] < '0' && line[2] > '2')) { // ACHO MELHOR AKI EU TER UMA VARIAVEL PRA ANO MES E DIA E AI COMPARAR COMO UM int
		std::cout << "Error: " << "data invalida." << std::endl;
		return (0);
	}





	return (1);
}




void BitcoinExchange::print(void) {
	// std::ostringstream oss; // POR ENQUANTO VOU FAZER SEM ISSO PQ NAO ACHEI SOLUCAO PARA O ZERO A DIREITA
	// float teste[] = {10.50, 20.33, 30.00};

	// oss << teste[0];
	// std::cout << "teste[0]: " << oss.str() << std::endl;

	// oss.str("");
	// oss.clear();
	// oss << teste[1];
	// std::cout << "teste[1]: " << oss.str() << std::endl;

	// oss.str("");
	// oss.clear();
	// oss << teste[2];
	// std::cout << "teste[2]: " << oss.str() << std::endl;

	std::cout << std::fixed << std::setprecision(2);
	for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++) {
		// std::cout << "chave: " << it->first;
		// std::cout << " valor: " << it->second;

		// oss << it->second;
		// std::cout << " valor: " << oss.str();

		// std::cout << std::endl;
		// oss.str("");
		// oss.clear();

		std::cout << "chave: " << it->first << " valor: " << it->second << std::endl;
	}

	// oss << std::fixed << std::setprecision(2);
	// oss << this->_data["2022-03-29"];
	// oss << std::fixed << std::setprecision(2) << 4711500.93;
	// std::cout << "teste: " << oss.str() << std::endl;
	// std::cout << "teste: " << std::fixed << std::setprecision(2) << 47115.93 << std::endl;

	// std::cout << "teste: " << std::fixed << std::setprecision(2) << this->_data["2022-03-29"] << std::endl;
}