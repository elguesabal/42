/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:43:13 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:43:14 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stdexcept>
#include <deque>
#include <cstdlib>
#include <sstream>

class RPN {
	public:
		RPN(void);
		RPN(const char *argv);
		RPN(const RPN &rpn);
		RPN &operator = (const RPN &rpn);
		~RPN(void);

		void readArg(void);
		std::string result(void);

	private:
		std::string _arg;
		std::deque<std::string> _RPN;
		bool error(const char *argv) const;
		int operation(int n1, int n2, std::string &signal) const;
};

#endif