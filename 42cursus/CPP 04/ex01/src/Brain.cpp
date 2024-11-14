/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:34:24 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:34:25 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

Brain::Brain(void) {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "random ideas";
}

Brain::Brain(const Brain &brain) {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
}

Brain &Brain::operator = (const Brain &brain) {
	if (this == &brain)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	return (*this);
}

Brain::~Brain(void) {

}