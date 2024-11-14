/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:41:38 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:41:39 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include "Array.tpp"

int main(void) {
	Array<int> numbers(3);
	for (int i = 0; i < 3; i++)
		numbers[i] = i + 1;
	for (int i = 0; i < 3; i++)
		std::cout << "numbers[" << i << "]: " << numbers[i] << std::endl;

	Array<std::string> strs(3);
	for (int i = 0; i < 3; i++)
		strs[i] = "vampeta";
	for (int i = 0; i < 3; i++)
		std::cout << "strs[" << i << "]: " << strs[i] << std::endl;
	return (0);
}