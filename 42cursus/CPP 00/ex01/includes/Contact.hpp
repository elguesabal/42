/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:21:48 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:21:49 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

class Contact {
	public:
		int index;
		Contact(int i);
		void setContact(std::string fist, std::string last, std::string nick, std::string num, std::string sec);
		void printList(void);
		void printContact(void);

	private:
		std::string _fistName;
		std::string _lastName;
		std::string _nickName;
		std::string _number;
		std::string _secret;

};

#endif