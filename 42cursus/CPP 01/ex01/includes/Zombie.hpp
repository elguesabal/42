/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:24:03 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:24:04 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H_INCLUDED
#define ZOMBIE_H_INCLUDED

class Zombie {
	public:
		Zombie(void);
		~Zombie(void);
		void setName(std::string name);

	private:
		std::string _name;

};

#endif