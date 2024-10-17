#ifndef	BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
// #include "Error.hpp" // ACABEI CRIANDO ESSA CLASSE PQ NAO SABIA DA EXISTENCIA DA CLASSE std::runtime_error
#include <stdexcept>

class BitcoinExchange {
	public:
		BitcoinExchange(const int argc, const char *argv);
		~BitcoinExchange(void);

		void openFile(const int argc, const char *argv);
		void readData(void); // FAZER AKI A LEITURA E GRAVACAO DO ARQUIVO data.csv

	private:
		std::ifstream _data;
		std::ifstream _input;
};

#endif