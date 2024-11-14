/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:31:09 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:31:09 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "header.h"

class FragTrap:public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &fragTrap);
		FragTrap &operator = (const FragTrap &fragTrap);
		~FragTrap(void);
		void attack(const std::string &target);
        void highFivesGuys(void);
};

#endif