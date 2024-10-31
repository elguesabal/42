#ifndef	PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <list>
#include <ctime>

class PmergeMe {
	public:
		PmergeMe(void);
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &pmergeMe);
		PmergeMe &operator = (const PmergeMe &pmergeMe);
		~PmergeMe(void);
		void fordJohnson(void);

	private:
		std::vector<int> _vector;
		std::list<int> _list;
		void error(char **argv) const;

						// NAO ESTA MAIS EM USO PQ ADAPTEI A printList() PARA SER USADA COM TEMPLATE E SERVIR PARA OS DOIS CONTAINERS
		// void printVector(const char *str, const std::vector<int> &vector) const;
		// std::vector<int> fordJohnsonVector(std::vector<int> &data) const;
		// std::vector<int> mergeVector(std::vector<int> &left, std::vector<int> &right) const;

		// void printList(const char *str, std::list<int> &list) const;
		// std::list<int> fordJohnsonList(std::list<int> &data) const;
		// std::list<int> mergeList(std::list<int> &left, std::list<int> &right) const;
						// NAO ESTA MAIS EM USO PQ ADAPTEI A printList() PARA SER USADA COM TEMPLATE E SERVIR PARA OS DOIS CONTAINERS

		template <typename T> void printContainer(const char *str, const T &container);
		template <typename Container> Container fordJohnsonContainer(Container &data) const;
		template <typename Container> Container mergeContainer(Container &left, Container &right) const;
};

#endif