#ifndef	SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

template <typename Container> void Span::fillSpan(const typename Container::iterator &begin, const typename Container::iterator &end) {
	for (std::vector <int>::iterator it = begin; it != end; it++)
		this->addNumber(*it);
}

#endif