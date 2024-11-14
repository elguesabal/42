/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:34:45 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:34:46 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "header.h"

class Animal {
	public:
		Animal(const Animal &animal);
		Animal &operator = (const Animal &animal);
		virtual ~Animal(void);
		virtual void makeSound(void) const;
		std::string getType(void) const;

	protected:
		Animal(void);
		std::string _type;
};

#endif