/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:35:39 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:35:40 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	try {
		Bureaucrat bureaucrat("vampeta", 1);
		// --bureaucrat;
		// std::cout << "name: " << bureaucrat.getName() << "grade: " << bureaucrat.getGrade() << std::endl;
		std::cout << bureaucrat;
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}

	return (0);
}