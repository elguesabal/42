/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:26:34 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:26:35 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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