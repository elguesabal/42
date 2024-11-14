/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:31:55 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:31:56 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "header.h"

class DiamondTrap:public ScavTrap, public FragTrap {
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &diamondTrap);
		DiamondTrap &operator = (const DiamondTrap &diamondTrap);
		~DiamondTrap(void);
		void attack(const std::string &target);
		void whoAmI(void);

	private:
		std::string _name;
};

#endif