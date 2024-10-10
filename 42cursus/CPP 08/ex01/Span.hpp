#ifndef	SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
# include <algorithm>
# include <numeric>

class Span {
	public:
		Span(unsigned int N);
		Span(const Span &span);
		Span &operator = (const Span &span);
		~Span(void);

		void addNumber(const int n);
		long int shortestSpan(void);
		long int longestSpan(void);

		// FALTA O ITERATOR PARA PREENCHER MUITOS NUMEROS DE UMA VEZ

		class noSpace: public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class noNumbers : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		void print(void); // TESTE

	private:
		unsigned int _size;
		std::vector <int> _array;
};

#endif