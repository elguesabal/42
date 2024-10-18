#ifndef	BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
// #include "Error.hpp" // ACABEI CRIANDO ESSA CLASSE PQ NAO SABIA DA EXISTENCIA DA CLASSE std::runtime_error
#include <stdexcept>
#include <sstream>
#include <iomanip> // USADO PARA PRINTAR NUMERO COM MAIS DE UMA CASA DECIMAL APOS A VIRGULA

class BitcoinExchange {
	public:
		BitcoinExchange(const int argc, const char *argv);
		~BitcoinExchange(void);

		void openFile(const int argc, const char *argv);
		void readData(void); // FAZER AKI A LEITURA E GRAVACAO DO ARQUIVO data.csv
		void readInput(void); // VAI LER O ARQUIVO DE INPUT CALCULAR E PRINTAR NA TELA O RESULTADO


		void print(void); // SO PRA TESTE

	private:
		std::ifstream _datacsv;
		std::ifstream _input;
		std::map<std::string, float> _data;
		bool validLine(const std::string &date) const;
};

#endif