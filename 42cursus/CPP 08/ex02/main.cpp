/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:42:22 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:42:23 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}



// int main(void) {
// 	MutantStack<int> stack1;
// 	MutantStack<int> stack2;

// 	for (int i = 0; i < 3; i++)
// 		stack1.push(i + 1);
// 	stack2 = stack1;
// 	for (MutantStack<int>::iterator it = stack2.begin(); it != stack2.end(); it++)
// 		std::cout << *it << std::endl;
// 	return (0);
// }