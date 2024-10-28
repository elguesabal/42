#ifndef	RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stdexcept>
#include <deque>
#include <cstdlib>
#include <sstream>

class RPN {
	public:
		RPN(void);
		RPN(const char *argv);
		RPN(const RPN &rpn);
		RPN &operator = (const RPN &rpn);
		~RPN(void);

		bool error(const char *argv) const;
		void readArg(void);
		std::string result(void);
		int operation(int n1, int n2, std::string &signal) const;

	private:
		std::string _arg;
		std::deque<std::string> _RPN;
};

#endif