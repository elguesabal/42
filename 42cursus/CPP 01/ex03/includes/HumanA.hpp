/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:24:32 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:24:33 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H_INCLUDED
#define HUMANA_H_INCLUDED

#include "../includes/header.h"

class HumanA {
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void attack(void);

	private:
		std::string name;
		Weapon &weapon;

};

#endif