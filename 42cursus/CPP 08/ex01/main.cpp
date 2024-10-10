#include "Span.hpp"

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
// 	Span span(3);

// 	try {
// 		span.addNumber(1);
// 		span.addNumber(6);
// 		span.addNumber(3);
// 		// span.addNumber(5);
// 		std::cout << span.shortestSpan() << std::endl;
// 		std::cout << span.longestSpan() << std::endl;
// 	} catch (std::exception &error) {
// 		std::cout << error.what() << std::endl;
// 	}

// 	// span.print();

// 	return (0);
// }