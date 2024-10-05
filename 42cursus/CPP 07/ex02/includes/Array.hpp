#ifndef	ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array {
	public:
		Array(void);
		Array(unsigend int &size);
		// Array operator = (const Array &array); O RETORNO TA ERRADO
		~void(void);

	private:
		T *_array;
		unsigend int _size;
};

#endif