#ifndef	CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <sstream>

class ScalarConverter {
	public:
		// ScalarConverter(void); // ISSO NAO FAZ SENTIDO COM FUNCOES STATICAS
		// ScalarConverter(const ScalarConverter &scalarConverter);
		// ScalarConverter(std::string &scalarConverter);
		// ScalarConverter &operator = (const ScalarConverter &scalarConverter);
		// ~ScalarConverter(void);

		static void convert(std::string input);
};

#endif