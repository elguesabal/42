#include <iostream>

// class Veiculo {
//     public:
//         int vel;
//         int blind;
//         int rodas;
//         void setTipo(int tp);
//         void setVelMax(int vm);
//         void setArma(bool ar);
//         void imp();

//     private:
//         int tipo;
//         int velMax;
//         bool arma;

// };

// void Veiculo::setTipo(int tp) {
//     this->tipo = tp;
// }

// void Veiculo::setVelMax(int vm) {
//     this->velMax = vm;
// }

// void Veiculo::setArma(bool ar) {
//     this->arma = ar;
// }

// void Veiculo::imp() {
//     std::cout << "Tipo veiculo: " << this->tipo << std::endl;
//     std::cout << "Velocidade maxima: " << this->velMax << std::endl;
//     std::cout << "Qtde rodas: " << this->rodas << std::endl;
//     std::cout << "Blindagem: " << this->blind << std::endl;
//     std::cout << "Armamento: " << this->arma << std::endl;
//     std::cout << "---------------------------------" << std::endl << std::endl;
// }



// class Moto:public Veiculo {
//     public:
//         Moto();

//     private:

// };

// Moto::Moto() {
//     this->vel = 0;
//     this->blind = 0;
//     this->rodas = 2;
//     this->setTipo(1);
//     this->setVelMax(120);
//     this->setArma(false);
// }



// class Carro:public Veiculo {
//     public:
//         Carro();

//     private:

// };

// Carro::Carro() {
//     this->vel = 0;
//     this->blind = 0;
//     this->rodas = 4;
//     this->setTipo(2);
//     this->setVelMax(180);
//     this->setArma(false);
// }



// class Tanque:public Veiculo {
//     public:
//         Tanque();

//     private:

// };

// Tanque::Tanque() {
//     this->vel = 0;
//     this->blind = 1;
//     this->rodas = 8;
//     this->setTipo(4);
//     this->setVelMax(200);
//     this->setArma(true);
// }

// int main(void) {
//     Moto v1 = Moto();
//     Carro v2 = Carro();
//     Tanque v3 = Tanque();

//     v1.imp();
//     v2.imp();
//     v3.imp();

//     return (0);
// }










class Base1 {
    public:
        void impBase1();
};

void Base1::impBase1() {
    std::cout << "Imp classe Base1" << std::endl;
}



class Base2 {
    public:
        void impBase2();
};

void Base2::impBase2() {
    std::cout << "Imp classe Base2" << std::endl;
}



class CFB:public Base1, public Base2 {

};

int main(void) {
    Base1 obj1 = Base1();
    Base2 obj2 = Base2();
    CFB obj3 = CFB();

    obj1.impBase1();
    obj2.impBase2();

    std::cout << std::endl;

    obj3.impBase1();
    obj3.impBase2();

    return (0);
}