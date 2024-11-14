/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:24:50 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:24:51 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

Weapon::Weapon(std::string type) {
	this->type = type;
}

Weapon::~Weapon(void) {

}

const std::string Weapon::getType(void) {
	return (type);
}

void Weapon::setType(std::string type) {
	this->type = type;
}
