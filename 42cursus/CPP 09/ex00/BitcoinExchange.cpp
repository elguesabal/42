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
		// std::cout << "AAAAAAA" << std::endl;
		if (validDate(line) && line[10] == ' ' && line[11] == '|' && line[12] == ' ' && validValue(line)) {
			std::cout << line.substr(0, 10) << " => " << line.substr(13) << " = " << value(line) << std::endl;
		}
	}
	this->_input.close();
}

// bool BitcoinExchange::validLine(const std::string &line) const {
// 	// if (line.size() < 14 || line[4] != '-' || line[7] != '-') {
// 	// 	std::cout << "Error: bad input => " << line << std::endl;
// 	// 	return (0);
// 	// }

// 	// int year = std::atoi(line.substr(0, 4).c_str());
// 	// int month = std::atoi(line.substr(5, 2).c_str());
// 	// int day = std::atoi(line.substr(8, 2).c_str());

// 	// if (month > 12 || month < 1 || day < 1 || day > 31 || (month % 2 == 0 && day > 30) || (month == 2 && day > 29)) {
// 	// 	std::cout << "Error: data invalida => " << line << std::endl;
// 	// 	return (0);
// 	// }

// 	// if (year < 2009 || year > 2022 || (year == 2022 && month > 3)) {
// 	// 	std::cout << "Error: data nao consta do banco de dados => " << line << std::endl;
// 	// 	return (0);
// 	// }
	

// 	return (1);
// }

bool BitcoinExchange::validDate(const std::string &line) const {
	if (line.size() < 14 || !isdigit(line[0]) || !isdigit(line[1]) || !isdigit(line[2]) || !isdigit(line[3]) || line[4] != '-' || !isdigit(line[5]) || !isdigit(line[6]) || line[7] != '-' || !isdigit(line[8])  || !isdigit(line[9])) {
		std::cout << "Error: bad input => " << line << std::endl;
		return (0);
	}
	int year = std::atoi(line.substr(0, 4).c_str());
	int month = std::atoi(line.substr(5, 2).c_str());
	int day = std::atoi(line.substr(8, 2).c_str());
	if (month > 12 || month < 1 || day < 1 || day > 31 || (month % 2 == 0 && day > 30) || (month == 2 && day > 29)) {
		std::cout << "Error: data invalida => " << line << std::endl;
		return (0);
	}
	if (year < 2009 || year > 2022 || (year == 2022 && month > 3)) {
		std::cout << "Error: data nao consta do banco de dados => " << line << std::endl;
		return (0);
	}
	return (1);
}

bool BitcoinExchange::validValue(const std::string &line) const {
	if (line[13] == '.' || line[line.size() - 1] == '.') {
		std::cout << "Error: bad input => " << line << std::endl;
		return (0);
	}
	for (long unsigned int i = 13, dot = 1; i < line.size(); i++) {
		if ((!isdigit(line[i]) && line[i] != '.' && line[13] != '-') || (line[i] == '.' && dot == 0)) {
			std::cout << "Error: bad input => " << line << std::endl;
			return (0);
		}
		if (line[i] == '.')
			--dot;
	}
	std::string num = line.substr(13);
	std::stringstream ss(num);
	float value;
	ss >> value;
	if (value < 0) {
		std::cout << "Error: not a positive number" << std::endl;
		return (0);
	} else if (value > 100) {
		std::cout << "Error: too large a number" << std::endl;
		return (0);
	}
	return (1);
}

std::string BitcoinExchange::value(const std::string &line) const { // ACHO Q TA PRONTO (AINDA NAO TESTADO FORA DO TESTE DADO PELO PDF) MAS AINDA POSSO REFATORAR
	std::string date = line.substr(0, 10);
	// int yearLine, monthLine, dayLine;
	int yearLine = std::atoi(line.substr(0, 4).c_str());
	int monthLine = std::atoi(line.substr(5, 2).c_str());
	int dayLine = std::atoi(line.substr(8, 2).c_str());
	// float valueDataFloat = this->_data[date];
	float valueDataFloat;
	// std::string valueDataStr;
	// int yearData;
	// int monthData;
	// int dayData;
	std::ostringstream oss;

	// oss << std::fixed << std::setprecision(2) << valueDataFloat;
	// std::string valueDataStr = oss.str();

		// std::cout << "cade o erro?" << std::endl;
	while (this->_data.find(date.c_str()) == this->_data.end()) {
		if (dayLine > 1) {
			--dayLine;
		} else if (monthLine > 1) {
			dayLine = 31;
			--monthLine;
		} else {
			dayLine = 31;
			monthLine = 12;
			--yearLine;
		}

		oss << yearLine;
		date = oss.str();
		date += "-";
		oss.str("");
		oss.clear();

		oss << monthLine;
		// std::cout << "teste::: " << oss.str() << oss.str() << oss.str();
		// std::cout << "size: " << oss.str() << "==>" << oss.str().size();
		if (oss.str().size() == 1)
			date += "0";
		date += oss.str();
		date += "-";
		oss.str("");
		oss.clear();

		oss << dayLine;
		if (oss.str().size() == 1)
			date += "0";
		date += oss.str();
		oss.str("");
		oss.clear();

		// std::cout << " ??" << date << "?? ";
	}
	valueDataFloat = this->_data.at(date.c_str());
	std::string nBitcoinStr = line.substr(13);
	std::stringstream ss(nBitcoinStr);
	float nBitcoinFloat;
	ss >> nBitcoinFloat;

	oss << valueDataFloat * nBitcoinFloat;

	// std::cout << "TESTANDO ESSA BAGACA: " << valueDataFloat;
	// std::cout << " TESTANDO ESSA BAGACA: " << date;
	// std::cout << "~~~ " << date << " --- " << value;
	return (oss.str());
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
