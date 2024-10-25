#ifndef	BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <stdexcept>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {
	public:
		BitcoinExchange(void);
		BitcoinExchange(const int argc, const char *argv);
		~BitcoinExchange(void);

		void openFile(const int argc, const char *argv);
		void readData(void);
		void readInput(void);

	private:
		std::ifstream _datacsv;
		std::ifstream _input;
		std::map<std::string, float> _data;
		bool validDate(const std::string &line) const;
		bool validValue(const std::string &line) const;
		std::string value(const std::string &line) const;
};

#endif