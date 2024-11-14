/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:23:30 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:23:31 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H_INCLUDED
#define ZOMBIE_H_INCLUDED

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);

	private:
		std::string _name;

};

#endif