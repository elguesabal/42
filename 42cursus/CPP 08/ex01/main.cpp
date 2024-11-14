/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:41:55 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:41:56 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Span.tpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}



// int main(void) {
// 	Span span(10);
// 	std::vector <int> n;

// 	for (int i = 0; i < 10; i++)
// 		n.push_back(i);
// 	try {
// 		// span.addNumber(1);
// 		// span.addNumber(6);
// 		// span.addNumber(3);
// 		// span.addNumber(5);
// 		// std::cout << span.shortestSpan() << std::endl;
// 		// std::cout << span.longestSpan() << std::endl;
// 		span.fillSpan<std::vector <int> >(n.begin(), n.end());
// 		for (int i = 0; i < 10; i++)
// 			std::cout << n[i] << std::endl;
// 	} catch (std::exception &error) {
// 		std::cout << error.what() << std::endl;
// 	}
// 	return (0);
// }
