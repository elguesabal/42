#ifndef	ERROR_HPP
#define ERROR_HPP

// ACABEI CRIANDO ESSA CLASSE PQ NAO SABIA DA EXISTENCIA DA CLASSE std::runtime_error

class Error: public std::exception {
	public:
		Error(const std::string &error) : _error(error) {}
		virtual ~Error(void) throw() {}
		virtual const char *what() const throw() { return (this->_error.c_str()); }

	private:
		const std::string _error;
};

#endif