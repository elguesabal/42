/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:21:54 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:21:55 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H_INCLUDED
#define PHONEBOOK_H_INCLUDED

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void add(std::string secret, std::string number, std::string nick, std::string last, std::string fist);
		void search(void);

	private:
		Contact *_contacts[9];
		int size();

};

#endif