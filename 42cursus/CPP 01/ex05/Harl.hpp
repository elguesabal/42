#ifndef HARL_H_INCLUDED
#define HARL_H_INCLUDED

#include <iostream>

class Harl {
	public:
		Harl(void);
		~Harl(void);
		void complain(std::string level);

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

};

#endif