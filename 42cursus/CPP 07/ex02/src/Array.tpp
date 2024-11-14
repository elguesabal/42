/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseanto <joseanto@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:41:35 by joseanto          #+#    #+#             */
/*   Updated: 2024/11/14 01:41:36 by joseanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T> Array<T>::Array(void) : _array(NULL), _size(0) {

}

template <typename T> Array<T>::Array(unsigned int size) : _array(new T[size]), _size(size) {

}

template <typename T> Array<T>::Array(const Array<T> &array) : _array(new T[array._size]), _size(array._size) {
	for (unsigned int i = 0; i < array._size; i++)
		this->_array[i] = array._array[i];
}

template <typename T> Array<T> &Array<T>::operator = (const Array<T> &array) {
	if (this == &array)
		return (*this);
	delete[] this->_array;
	this->_size = array._size;
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = array._array[i];
	return (*this);
}

template <typename T> T &Array<T>::operator [] (const int index) {
	if (index < 0 || index >= (int)this->_size)
		throw (Array::indexOutOfBounds());
	return (this->_array[index]);
}

template <typename T> Array<T>::~Array(void) {
	delete[] this->_array;
}

template <typename T> const char *Array<T>::indexOutOfBounds::what(void) const throw() {
	return ("Error: índice fora dos limites");
}