/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:25:00 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:25:01 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

bool test(bool n, std::string str) {
	if (n)
		std::cout << str << std::endl;
	return (n);
}

std::string replaceLine(std::string line, std::string s1, std::string s2) {
	std::size_t find = 0;

	do {
		find = line.find(s1, find + s2.length());
		if (find != std::string::npos) {
			line.erase(find, s1.length());
			line.insert(find, s2);
		}
	} while (find != std::string::npos);
	return (line);
}

int main(int argc, char **argv) {
	if (test(argc != 4, "Error: Numero de argumentos invalido"))
		return (1);

	std::string file = argv[1];
	std::string fileReplace = file + ".replace";
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream readFile(file.c_str());
	if (test(!readFile.is_open(), "Error: Arquivo nao existente"))
		return (1);

	std::ofstream writeFile(fileReplace.c_str());
	if (test(!readFile.is_open(), "Error: Nao foi possivel criar o arquivo"))
		return (1);

	std::string line;
	while (std::getline(readFile, line)) {
		if (s1 != s2)
			line = replaceLine(line, s1, s2);
		writeFile << line << std::endl;
	}

	readFile.close();
	writeFile.close();

	return (0);
}