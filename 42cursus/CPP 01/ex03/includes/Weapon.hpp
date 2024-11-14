/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:24:37 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:24:38 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED

class Weapon {
	public:
		Weapon(std::string type);
		~Weapon(void);
		const std::string getType(void);
		void setType(std::string type);

	private:
		std::string  type;

};

#endif