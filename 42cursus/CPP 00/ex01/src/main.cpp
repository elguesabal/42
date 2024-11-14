/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:22:02 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:22:03 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

std::string input(std::string str) {
	std::string response = "";

	std::cout << str;
	std::cin >> response;
	return (response);
}

int main(void) {
	std::string buffer;
	PhoneBook *list = new PhoneBook();

	waitCommand:
	buffer = input("Digite um comando: ");
	if (buffer == "ADD") {
		list->add(input("Secret: "), input("Number: "), input("Nick: "), input("Sobrenome: "), input("Nome: "));
	} if (buffer == "SEARCH") {
		list->search();
	} else if (buffer == "EXIT") {
		delete list;
		return (0);
	}
	goto waitCommand;
}