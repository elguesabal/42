/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:24:07 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:24:08 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int main(void) {
	Zombie *zombies = zombieHorde(3, "zumbieHorde");

	delete[] zombies;
	return (0);
}