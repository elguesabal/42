/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:39:52 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:39:53 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
	Data data1;

	data1.data_string = "vampeta";
	data1.data_int = 42;

	uintptr_t serialized = Serializer::serialize(&data1);
	Data *data2 = Serializer::deserialize(serialized);

	std::cout << "serialized: " << serialized << std::endl;
	std::cout << "string: " << data2->data_string << std::endl;
	std::cout << "int: " << data2->data_int << std::endl;

	return (0);
}