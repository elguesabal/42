/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:25:33 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:25:34 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H_INCLUDED
#define HARL_H_INCLUDED

#include <iostream>

class Harl {
	public:
		Harl(void);
		~Harl(void);
		void complain(std::string level);

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

};

#endif