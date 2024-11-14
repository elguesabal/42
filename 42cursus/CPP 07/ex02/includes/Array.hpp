/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:41:31 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:41:32 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array {
	public:
		Array(void);
		Array(unsigned int size);
		Array(const Array &array);
		Array &operator = (const Array &array);
		T &operator [] (const int index);
		~Array(void);

		class indexOutOfBounds : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};

	private:
		T *_array;
		unsigned int _size;
};

#endif