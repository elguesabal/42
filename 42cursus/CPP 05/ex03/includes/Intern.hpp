/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:38:15 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:38:16 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

class Intern {
	public:
		Intern(void);
		~Intern(void);

		AForm *makeForm(std::string form, std::string target);
		AForm *newShrubbery(std::string target);
		AForm *newRobotomy(std::string target);
		AForm *newPresidential(std::string target);
};

#endif