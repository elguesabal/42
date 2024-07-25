#ifndef AVIAO_H_INCLUDED
#define AVIAO_H_INCLUDED

#include <iostream>

class Aviao {
    public:
        int vel = 0;
        int velMax;
        std::string tipo;
        Aviao(int tp);
        void imprimir();

    private:
};

Aviao::Aviao(int tp) {
	if (tp == 1) {
		velMax = 800;
		tipo = "jato";
	} else if (tp == 2) {
		velMax = 350;
		tipo = "monomotor";
	} else if (tp == 3) {
		velMax = 180;
		tipo = "planador";
	}
}

void Aviao::imprimir() {
    std::cout << "tipo: " << tipo << std::endl;
    std::cout << "velocidade maxima" << velMax << std::endl;
    std::cout << "velocidade atual" << vel << std::endl;
}

#endif