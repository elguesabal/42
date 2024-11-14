/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:33:16 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:33:17 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "header.h"

class Cat: public Animal {
	public:
		Cat(void);
		Cat(const Cat &cat);
		Cat &operator = (const Cat &cat);
		~Cat(void);
		void makeSound(void) const;
};

#endif