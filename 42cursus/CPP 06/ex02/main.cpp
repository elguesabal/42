#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	std::srand(time(0));

	int n = std::rand() % 3;
	switch (n) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Erro ao converter tipo" << std::endl;
	}
}

void identify(Base &p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (const std::exception &error) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (const std::exception &error) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch (const std::exception &error) {}
	std::cout << "Erro ao converter tipo" << std::endl;
}

int main(void) {
	Base *base = generate();

	identify(base);
	identify(*base);
	delete base;
	return (0);
}