/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:41:21 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:41:22 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T> void iter(const T t[], int len, void func(const T &)) {
	for (int i = 0; i < len; i++) {
		func(t[i]);
	}
}

template <typename T> void test(const T &t) {
	std::cout << t << std::endl;
}

int main(void) {
	int n[] = {1, 2, 3, 4, 5};
	std::string str[] = {"str1", "str2", "str3"};

	iter(n, 5, test);
	std::cout << std::endl;
	iter(str, 3, test);

	return (0);
}