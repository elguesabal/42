#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed &fixed);
		Fixed &operator = (Fixed &fixed);
		~Fixed(void);
		int getRawBits(void) const;
		void  setRawBits(const int raw);

	private:
		int _n1;
		const static int _n2 = 8;

};

#endif