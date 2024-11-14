/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:42:15 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:42:16 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

template <typename Container> void Span::fillSpan(const typename Container::iterator &begin, const typename Container::iterator &end) {
	for (std::vector <int>::iterator it = begin; it != end; it++)
		this->addNumber(*it);
}

#endif