#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed(const int fixed);
		Fixed(const float fixed);
		~Fixed(void);
		int getRawBits(void) const;
		void  setRawBits(const int raw);
		float toFloat(void) const;
		int toInt(void) const;

		Fixed operator + (const Fixed &fixed) const;
		Fixed operator - (const Fixed &fixed) const;
		Fixed operator * (const Fixed &fixed) const;
		Fixed operator / (const Fixed &fixed) const;
		Fixed &operator = (const Fixed &fixed);

		bool operator > (const Fixed &fixed) const;
		bool operator < (const Fixed &fixed) const;
		bool operator >= (const Fixed &fixed) const;
		bool operator <= (const Fixed &fixed) const;
		bool operator == (const Fixed &fixed) const;
		bool operator != (const Fixed &fixed) const;

		Fixed &operator ++ (void);
		Fixed &operator -- (void);
		Fixed operator ++ (int);
		Fixed operator -- (int);


	private:
		int _n1;
		const static int _n2 = 8;

};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif