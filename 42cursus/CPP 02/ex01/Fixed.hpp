/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:27:24 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:27:25 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		Fixed &operator = (const Fixed &fixed);
		~Fixed(void);
		int getRawBits(void) const;
		void  setRawBits(const int raw);
		float toFloat(void) const;
		int toInt(void) const;

	private:
		int _n1;
		const static int _n2 = 8;

};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif