/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:42:51 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:42:52 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {

}

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
	this->_input.open(argv);
	this->_datacsv.open("data.csv");
	if (!this->_input.is_open() || !this->_datacsv.is_open())
		throw (std::runtime_error("Erro ao abrir arquivos"));
	std::string line;
	getline(this->_input, line);
	if (line != "date | value")
		throw (std::runtime_error("Cabecalho incorreto. Esperado 'date | value', mas foi encontrado outro formato"));
	getline(this->_datacsv, line);
	if (line != "date,exchange_rate")
		throw (std::runtime_error("Cabecalho incorreto. Esperado 'date,exchange_rate', mas foi encontrado outro formato"));
}

void BitcoinExchange::readData(void) {
	std::string line, date, num;
	float price;

	while (getline(this->_datacsv, line)) {
		date = line.substr(0, line.find(','));
		num = line.substr(line.find(',') + 1);
		std::stringstream ss(num);
		ss >> price;
		this->_data[date] = price;
	}
	this->_datacsv.close();
}

void BitcoinExchange::readInput(void) {
	std::string line;

	while (getline(this->_input, line)) {
		if (validDate(line) && line[10] == ' ' && line[11] == '|' && line[12] == ' ' && validValue(line))
			std::cout << line.substr(0, 10) << " => " << line.substr(13) << " = " << value(line) << std::endl;
	}
	this->_input.close();
}

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

std::string BitcoinExchange::value(const std::string &line) const {
	std::string date = line.substr(0, 10);
	int yearLine = std::atoi(line.substr(0, 4).c_str());
	int monthLine = std::atoi(line.substr(5, 2).c_str());
	int dayLine = std::atoi(line.substr(8, 2).c_str());
	std::ostringstream oss;

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
	}
	std::stringstream ss(line.substr(13));
	float nBitcoinFloat;
	ss >> nBitcoinFloat;
	oss << this->_data.at(date.c_str()) * nBitcoinFloat;
	return (oss.str());
}