#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

class Veiculo {
    public:
        int vel;
        int tipo;
        Veiculo(int tp);
        int getVelMax(void);
        void setVelMax(int vm);
        bool getLigado(void);
        void setLigado(int l);

    private:
        std::string nome;
        int velMax;
        bool ligado;
};

Veiculo::Veiculo(int tp) {
    tipo = tp;
    if (tipo == 1) {
        nome = "Carro";
        velMax = 200;
    } else if (tipo == 2) {
        nome = "Aviao";
        velMax = 800;
    } else if (tipo == 3) {
        nome = "Navio";
        velMax = 120;
    }
    setLigado(0);
}

int Veiculo::getVelMax(void) {
    return (velMax);
}

void Veiculo::setVelMax(int vm) {
    velMax = vm;
}

bool Veiculo::getLigado(void) {
    return (ligado);
}

void Veiculo::setLigado(int l) {
    if (l == 1) {
        ligado = true;
    } else if (l == 0) {
        ligado = false;
    }
}

#endif