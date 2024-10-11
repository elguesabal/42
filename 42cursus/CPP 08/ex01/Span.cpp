#include "Span.hpp"

Span::Span(unsigned int n) : _size(n) {

}

Span::Span(const Span &span) : _size(span._size), _array(span._array) {

}

Span &Span::operator = (const Span &span) {
	this->_size = span._size;
	this->_array = span._array;
	return (*this);
}

Span::~Span(void) {

}

void Span::addNumber(const int n) {
	if (this->_array.size() == this->_size)
		throw (noSpace());

	this->_array.push_back(n);
}

long int Span::shortestSpan(void) {
	if (this->_array.size() < 2)
		throw (noNumbers());
	std::vector <long int> lv(this->_array.size());
	for (size_t i = 0; i < this->_array.size(); i++)
		lv[i] = this->_array[i];
	std::vector <long int> diff(lv.size());
	std::adjacent_difference(lv.begin(), lv.end(), diff.begin());
	for (size_t i = 0; i < diff.size(); i++)
		if (diff[i] < 0)
			diff[i] = -diff[i];
	return(*(std::min_element(diff.begin() + 1, diff.end() - 1)));
}

long int Span::longestSpan(void) {
	if (this->_array.size() < 2)
		throw (noNumbers());
	this->_array.begin();
	return((long int)*(std::max_element(this->_array.begin(), this->_array.end())) - (long int)*(std::min_element(this->_array.begin(), this->_array.end())));
}

const char *Span::noSpace::what() const throw() {
	return ("Error: Array cheio");
}

const char *Span::noNumbers::what() const throw() {
	return ("Error: A matriz não possui números suficientes");
}

void Span::print(void) {
	for (std::vector <int>::iterator it = this->_array.begin(); it != this->_array.end(); it++) {
		std::cout << *it << std::endl;
	}
}