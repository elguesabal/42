/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:34:55 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:34:56 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "header.h"

class Dog: public Animal {
	public:
		Dog(void);
		Dog(const Dog &dog);
		Dog &operator = (const Dog &dog);
		~Dog(void);
		void makeSound(void) const;

	private:
		Brain *_brain;
};

#endif