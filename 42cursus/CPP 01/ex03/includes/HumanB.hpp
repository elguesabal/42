/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:24:34 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:24:35 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H_INCLUDED
#define HUMANB_H_INCLUDED

#include "../includes/header.h"

class HumanB {
	public:
		HumanB(std::string name);
		~HumanB(void);
		void setWeapon(Weapon &weapon);
		void attack(void);

	private:
		std::string name;
		Weapon *weapon = NULL;

};

#endif