/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:43:33 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:43:34 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {

}

PmergeMe::PmergeMe(char **argv) {
	error(argv);
	for (int i = 0; argv[i]; i++) {
		this->_vector.push_back(std::atoi(argv[i]));
		this->_list.push_back(std::atoi(argv[i]));
	}
}

PmergeMe::PmergeMe(const PmergeMe &pmergeMe) : _vector(pmergeMe._vector), _list(pmergeMe._list) {

}

PmergeMe &PmergeMe::operator = (const PmergeMe &pmergeMe) {
	if (this != &pmergeMe) {
		this->_vector = pmergeMe._vector;
		this->_list = pmergeMe._list;
	}
	return (*this);
}

PmergeMe::~PmergeMe(void) {

}

void PmergeMe::fordJohnson(void) {
	printContainer("Before vector:", this->_vector);
	printContainer("Before list:", this->_list);

	std::clock_t beginVector = std::clock();
	std::vector<int> vector = fordJohnsonContainer(this->_vector);
	std::clock_t endVector = std::clock();

	std::clock_t beginList = std::clock();
	std::list<int> list = fordJohnsonContainer(this->_list);
	std::clock_t endList = std::clock();

	printContainer("After vector:", vector);
	printContainer("After list:", list);
	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::[..] : " << 1000.0 * (endVector - beginVector) / CLOCKS_PER_SEC << std::endl;
	std::cout << "Time to process a range of " << this->_list.size() << " elements with std::[..] : " << 1000.0 * (endList - beginList) / CLOCKS_PER_SEC << std::endl;
}

void PmergeMe::error(char **argv) const {
	for (int i = 0; argv[i]; i++) {
		if (argv[i][0] == '-')
			throw (std::runtime_error("Error: numero negativo nao aceito"));
		for (int j = 0; argv[i][j]; j++) {
			if (argv[i][j] < '0' || argv[i][j] > '9')
				throw (std::runtime_error("Error: argumentos devem ser apenas numeros"));
		}
	}
}

// void PmergeMe::printVector(const char *str, const std::vector<int> &vector) const {
// 	std::cout << str;
// 	for (unsigned int i = 0; i < vector.size(); i++)
// 		std::cout << " " << vector[i];
// 	std::cout << std::endl;
// }

// std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int> &data) const {
// 	if (data.size() <= 1)
// 		return (data);

// 	std::vector<int> left(data.begin(), data.begin() + data.size() / 2);
// 	std::vector<int> right(data.begin() + data.size() / 2, data.end());

// 	left = fordJohnsonVector(left);
// 	right = fordJohnsonVector(right);

// 	return (mergeVector(left, right));
// }

// std::vector<int> PmergeMe::mergeVector(std::vector<int> &left, std::vector<int> &right) const {
// 	std::vector<int> result;
// 	std::vector<int>::iterator itLeft = left.begin();
// 	std::vector<int>::iterator itRight = right.begin();

// 	while (itLeft != left.end() && itRight != right.end()) {
// 		if (*itLeft < *itRight) {
// 			result.push_back(*itLeft);
// 			++itLeft;
// 		} else {
// 			result.push_back(*itRight);
// 			++itRight;
// 		}
// 	}

// 	while (itLeft != left.end()) {
// 		result.push_back(*itLeft);
// 		++itLeft;
// 	}

// 	while (itRight != right.end()) {
// 		result.push_back(*itRight);
// 		++itRight;
// 	}

// 	return (result);
// }



// void PmergeMe::printList(const char *str, std::list<int> &list) const {
// 	std::cout << str;
// 	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
// 		std::cout << " " << *it;
// 	std::cout << std::endl;
// }

// std::list<int> PmergeMe::fordJohnsonList(std::list<int> &data) const {
// 	if (data.size() <= 1)
// 		return (data);

// 	std::list<int>::iterator middle = data.begin();
// 	for (std::size_t i = 0; i < data.size() / 2; ++i)
// 		++middle;

// 	std::list<int> left(data.begin(), middle);
// 	std::list<int> right(middle, data.end());

// 	left = fordJohnsonList(left);
// 	right = fordJohnsonList(right);

// 	return (mergeList(left, right));
// }

// std::list<int> PmergeMe::mergeList(std::list<int> &left, std::list<int> &right) const {
// 	std::list<int> result;
// 	std::list<int>::iterator itLeft = left.begin();
// 	std::list<int>::iterator itRight = right.begin();

// 	while (itLeft != left.end() && itRight != right.end()) {
// 		if (*itLeft < *itRight) {
// 			result.push_back(*itLeft);
// 			++itLeft;
// 		} else {
// 			result.push_back(*itRight);
// 			++itRight;
// 		}
// 	}

// 	while (itLeft != left.end()) {
// 		result.push_back(*itLeft);
// 		++itLeft;
// 	}

// 	while (itRight != right.end()) {
// 		result.push_back(*itRight);
// 		++itRight;
// 	}

// 	return (result);
// }



template <typename T> void PmergeMe::printContainer(const char *str, const T &container) {
	std::cout << str;
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

template <typename Container> Container PmergeMe::fordJohnsonContainer(Container &data) const {
	if (data.size() <= 1)
		return (data);
	typename Container::iterator middle = data.begin();
	for (std::size_t i = 0; i < data.size() / 2; ++i)
		++middle;
	Container left(data.begin(), middle);
	Container right(middle, data.end());
	left = fordJohnsonContainer(left);
	right = fordJohnsonContainer(right);
	return mergeContainer(left, right);
}

template <typename Container> Container PmergeMe::mergeContainer(Container &left, Container &right) const {
	Container result;
	typename Container::const_iterator itLeft = left.begin();
	typename Container::const_iterator itRight = right.begin();
	while (itLeft != left.end() && itRight != right.end()) {
		if (*itLeft < *itRight) {
			result.push_back(*itLeft);
			++itLeft;
		} else {
			result.push_back(*itRight);
			++itRight;
		}
	}
	while (itLeft != left.end()) {
		result.push_back(*itLeft);
		++itLeft;
	}
	while (itRight != right.end()) {
		result.push_back(*itRight);
		++itRight;
	}
	return (result);
}