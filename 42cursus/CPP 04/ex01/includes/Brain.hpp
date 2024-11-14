/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:34:01 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:34:02 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "header.h"

class Brain {
	public:
		Brain(void);
		Brain(const Brain &brain);
		Brain &operator = (const Brain &brain);
		~Brain(void);

	protected:
		std::string ideas[100];
};

#endif