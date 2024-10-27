#ifndef	RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stdexcept>
#include <deque>

class RPN {
	public:
		RPN(void);
		RPN(const char *argv);
		RPN(const RPN &rpn);
		RPN &operator = (const RPN &rpn);
		~RPN(void);

		bool error(const char *argv) const;
		void readArg(void);
		int result(void);

	private:
		std::string _arg;
		std::deque<std::string> _RPN;
};

#endif