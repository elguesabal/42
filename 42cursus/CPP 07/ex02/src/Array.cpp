

template <typename T> Array::Array(void) : _array(NULL), _size(0) {

}

template <typename T> Array::Array(unsigend int size) : _array(new T[size]), _size(size) {

}

template <typename T> Array::Array(const Array &array) : _array(new T[array._size]), _size(array._size) {
	for (int i = 0; i < array._size; i++)
		this->_array[i] = array._array[i];
}

// template <typename T> Array::Array operator = (); O RETORNO TA ERRADO

template <typename T> temArray::~Array(void) {
	delete[] this->_array;
}