/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:24:10 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:24:11 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

Zombie::Zombie(void) {

}

Zombie::~Zombie(void) {
	std::cout << "Deleted: " << _name << std::endl;
}

void Zombie::setName(std::string name) {
	_name = name;
}