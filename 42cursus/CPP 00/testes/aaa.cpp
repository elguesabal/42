#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>

// CIN
// GOTO
// OR
// int main(void) {
// 	char letra;

// 	inicio:
// 	std::cout << "repetir? [s/n] ";
// 	std::cin >> letra;

// 	if (letra == 's' or letra == 'y')
// 		goto inicio;

// 	return (0);
// }



// CURIOSIDADE COM A FUNCAO main()
// int main(int argc, char **argv) {

// 	std::cout << argv[1] << std::endl;

// 	argc++;

// 	if (argc < 10)
// 		main(argc, argv);

// 	return (0);
// }



// CURIOSIDADE COM O sizeof()
// int main(void) {
// 	int v[5] = {0, 10, 20, 30, 40};

// 	for (int i = 0; i < sizeof(v) / sizeof(int); i++) {
// 		std::cout << v[i] << std::endl;
// 	}

// 	return (0);
// }



// NAO CONSIGO DECLARAR FUNCAO DENTRO DA main()
// int main(void) {
// 	int teste(int n) {
// 		return (n);
// 	}
// 	int bits = teste(10);

// 	std::cout << bits << std::endl;

// 	return (0);
// }



// SOBRECARGA DE FUNCAO (FUNCOES COM O MESMO NOME PODEM EXISTE CASO NAO SEJA IGUALMENTE PROTOTIPADA)
// void teste() {
// 	std::cout << 10 << std::endl;
// }
// void teste(int n) {
// 	std::cout << n << std::endl;
// }
// int main(void) {
// 	teste();
// 	teste(100);
// 	return (0);
// }



// POSSO DECLARAR UMA FUNCAO COM PARAMETROS OPCIONAIS
// // void teste(std::string teste = "vazio") {
// // 	std::cout << teste << std::endl;
// // }
// // int main(void) {
// // 	teste();
// // 	teste("kkk");
// // 	return (0);
// // }

// void teste(std::string teste = "vazio");
// int main(void) {
// 	teste();
// 	teste("kkk");
// 	return (0);
// }
// void teste(std::string teste) {
// 	std::cout << teste << std::endl;
// }



// ENUM
// int main(void) {
// 	enum n { n1, n2, n3 = 100, n4, n5 };

// 	std::cout << n3 << std::endl;
// 	std::cout << n4 << std::endl;

// 	n numero = n2;
// 	std::cout << numero << std::endl;
// 	return (0);
// }



// STACK
// .size()
// .top()
// .pop()
// int main(void) {
// 	std::stack <std::string> cartas;

// 	cartas.push("Rei de copas");
// 	cartas.push("Rei de espadas");
// 	cartas.push("Rei de ouros");
// 	cartas.push("Rei de paus");

// 	std::cout << "Tamanho da pilha: " << cartas.size() << std::endl;
// 	std::cout << "Carta do topo: " << cartas.top() << std::endl;
// 	cartas.pop();
// 	std::cout << "Tamanho da pilha: " << cartas.size() << std::endl;
// 	std::cout << "Carta do topo: " << cartas.top() << std::endl;

// 	return (0);
// }



// .empty()
// int main(void) {
// 	std::stack <int> n;

// 	n.push(10);
// 	if (n.empty() == 0)
// 		std::cout << "pilha cheia" << std::endl;
// 	std::cout << n.top() << std::endl;
// 	n.pop();
// 	if (n.empty())
// 		std::cout << "pilha vazia" << std::endl;
// 	return (0);
// }



// .front()
// .back()
// int main(void) {
// 	std::queue <std::string> cartas;

// 	cartas.push("Rei de copas");
// 	cartas.push("Rei de espadas");
// 	cartas.push("Rei de ouros");
// 	cartas.push("Rei de paus");

// 	std::cout << "Tamanho da fila: " << cartas.size() << std::endl;
// 	std::cout << "Primeira carta: " << cartas.front() << std::endl;
// 	std::cout << "Ultima carta: " << cartas.back() << std::endl;

// 	while (!cartas.empty()) {
// 		std::cout << "Primeira carta: " << cartas.front() << std::endl;
// 		cartas.pop();
// 	}
// 	return (0);
// }



// .push_front()
// int main(void) {
// 	std::list <int> aula;

// 	for (int i = 0; i < 10; i++) {
// 		aula.push_front(i);
// 	}

// 	std::cout << "Tamanho da lista: " << aula.size() << std::endl;

// 	while (!aula.empty()) {
// 		std::cout << aula.back() << std::endl;
// 		aula.pop_back();
// 	}

// 	// int tam = aula.size();
// 	// for (int i = 0; i < tam; i++) {
// 	// 	std::cout << aula.front() << std::endl;
// 	// 	aula.pop_front();
// 	// }
// 	return (0);
// }



// iterator
// .begin() SAPOHA NA VDD RETORNA UM ENDERECO DE MEMORIA
// advence()
// .insert()
// int main(void) {
// 	std::list <int> aula;
// 	std::list <int>::iterator it;

// 	for (int i = 0; i < 10; i++) {
// 		aula.push_front(i);
// 	}

// 	it = aula.begin();
// 	advance(it, 5);
// 	aula.insert(it, 0);

// 	while (!aula.empty()) {
// 		std::cout << aula.back() << std::endl;
// 		aula.pop_back();
// 	}
// 	return (0);
// }



// .sort()
// int main(void) {
// 	std::list <int> aula;
// 	std::list <int>::iterator it;

// 	aula.push_front(2);
// 	aula.push_front(1);
// 	aula.push_front(5);
// 	aula.push_front(3);
// 	aula.push_front(4);
// 	aula.sort();

// 	while (!aula.empty()) {
// 		std::cout << aula.front() << std::endl;
// 		aula.pop_front();
// 	}
// 	return (0);
// }



// .reverse()
// int main(void) {
// 	std::list <int> aula;
// 	std::list <int>::iterator it;

// 	aula.push_front(1);
// 	aula.push_front(2);
// 	aula.push_front(3);
// 	aula.push_front(4);
// 	aula.push_front(5);
// 	aula.reverse();

// 	while (!aula.empty()) {
// 		std::cout << aula.front() << std::endl;
// 		aula.pop_front();
// 	}
// 	return (0);
// }



// .erase()
// int main(void) {
// 	std::list <int> aula;
// 	std::list <int>::iterator it;

// 	for (int i = 1; i <= 10; i++)
// 		aula.push_front(i);

// 	it = aula.begin();
// 	advance(it, 3);
// 	aula.insert(it, 0);

// 	aula.erase(--it);

// 	std::cout << "Tamanho da lista: " << aula.size() << std::endl;
// 	while (!aula.empty()) {
// 		std::cout << aula.front() << std::endl;
// 		aula.pop_front();
// 	}
// 	return (0);
// }



// .clear()
// int main(void) {
// 	std::list <int> n;

// 	for (int i = 1; i <= 10; i++)
// 		n.push_back(i);

// 	n.clear();

// 	std::cout << "Tamanho da lista: " << n.size() << std::endl;
// 	return (0);
// }



// .merge()
// int main(void) {
// 	std::list <int> list1;
// 	std::list <int> list2;

// 	for (int i = 1; i <= 5; i++)
// 		list1.push_back(i);
// 	for (int i = 6; i <= 10; i++)
// 		list2.push_back(i);

// 	list1.merge(list2);

// 	std::cout << "Tamanho de list1: " << list1.size() << std::endl;
// 	while (!list1.empty()) {
// 		std::cout << list1.front() << std::endl;
// 		list1.pop_front();
// 	}
// 	std::cout << "Tamanho de list2: " << list2.size() << std::endl;
// 	while (!list2.empty()) {
// 		std::cout << list2.front() << std::endl;
// 		list2.pop_front();
// 	}
// 	return (0);
// }



// typedef struct s_carro {
// 	std::string nome;
// 	std::string cor;
// 	int pot;
// 	int velMax;
// } t_carro;

// int main(void) {
// 	t_carro car;

// 	car.nome = "tornado";
// 	car.cor = "vermelho";
// 	car.pot = 450;
// 	car.velMax = 350;

// 	std::cout << "Nome: " << car.nome << std::endl;
// 	std::cout << "Cor: " << car.cor << std::endl;
// 	std::cout << "Potencia: " << car.pot << std::endl;
// 	std::cout << "Velocidade maxima: " << car.velMax << std::endl;
// 	return (0);
// }



// #include <stdlib.h>

// typedef struct s_teste {
// 	int n;
// 	struct s_teste *next;
// } t_teste;

// int main(void) {
// 	t_teste *teste;

// 	teste = (t_teste*)malloc(sizeof(t_teste));
// 	teste->n = 1;
// 	teste->next = (t_teste*)malloc(sizeof(t_teste));
// 	teste->next->n = 2;
// 	teste->next->next = (t_teste*)malloc(sizeof(t_teste));
// 	teste->next->next->n = 3;
// 	teste->next->next->next = NULL;

// 	std::cout << teste->n << std::endl;
// 	std::cout << teste->next->n << std::endl;
// 	std::cout << teste->next->next->n << std::endl;
// 	return (0);
// }



// typedef struct s_carro {
// 	std::string nome;
// 	std::string cor;
// 	int pot;
// 	int velMax;
// 	int vel;

// 	void insere(std::string stnome, std::string stcor, int stpot, int stvelMax) {
// 		nome = stnome;
// 		cor = stcor;
// 		pot = stpot;
// 		velMax = stvelMax;
// 		vel = 0;
// 	}

// 	void mostra() {
// 		std::cout << "Nome: " << nome << std::endl;
// 		std::cout << "Cor: " << cor << std::endl;
// 		std::cout << "Potencia: " << pot << std::endl;
// 		std::cout << "Velocidade maxima: " << velMax << std::endl;
// 		std::cout << "Velocidade atual: " << vel << std::endl;
// 	}

// 	void mudaVel(int mv) {
// 		if (mv > velMax)
// 			vel = velMax;
// 		else if (mv < 0)
// 			vel = 0;
// 		else
// 			vel = mv;
// 	}
// } t_carro;

// int main(void) {
// 	t_carro car;
// 	car.insere("tornado", "vermelho", 450, 350);
// 	car.mostra();
// 	return (0);
// }



// typedef struct s_carro {
// 	std::string nome;
// 	std::string cor;
// 	int pot;
// 	int velMax;
// 	int vel;

// 	void insere(std::string stnome, std::string stcor, int stpot, int stvelMax) {
// 		nome = stnome;
// 		cor = stcor;
// 		pot = stpot;
// 		velMax = stvelMax;
// 		vel = 0;
// 	}

// 	void mostra() {
// 		std::cout << "Nome: " << nome << std::endl;
// 		std::cout << "Cor: " << cor << std::endl;
// 		std::cout << "Potencia: " << pot << std::endl;
// 		std::cout << "Velocidade maxima: " << velMax << std::endl;
// 		std::cout << "Velocidade atual: " << vel << std::endl;
// 	}

// 	void mudaVel(int mv) {
// 		if (mv > velMax)
// 			vel = velMax;
// 		else if (mv < 0)
// 			vel = 0;
// 		else
// 			vel = mv;
// 	}
// } t_carro;

// int main(void) {
// 	s_carro *carros = new s_carro[5];
// 	s_carro car1, car2, car3, car4, car5;

// 	carros[0] = car1;
// 	carros[1] = car2;
// 	carros[2] = car3;
// 	carros[3] = car4;
// 	carros[4] = car5;

// 	carros[0].insere("tornado", "vermelho", 450, 350);
// 	carros[1].insere("luxo", "preto", 250, 260);
// 	carros[2].insere("familia", "prata", 150, 180);
// 	carros[3].insere("trabalho", "branco", 80, 120);
// 	carros[4].insere("padrao", "cinza", 100, 150);

// 	for (int i = 0; i < 5; i++) {
// 		carros[i].mostra();
// 		std::cout << std::endl;
// 	}
// 	return (0);
// }



// int main(void) {
// 	std::string teste1 = "kkk";
// 	std::string *teste2 = &teste1;

// 	std::cout << &teste1 << ": " << teste1 << std::endl;
// 	std::cout << teste2 << ": " << *teste2 << std::endl;
// 	return (0);
// }



// int main(void) {
// 	char *buffer = (char*) malloc(sizeof(char) + 1); // ESSA FUNCAO SO ALOCA 1 CHAR???

// 	std::cin >> buffer; // SE DIGITAR MAIS DE 1 CHAR NAO DARIA LEAK NO VALGRIND?
// 	std::cout << "teste: " << buffer << std::endl;
// 	return (0);
// }



// VECTOR
// .swap()
// .at()
// int main(void) {
// 	std::vector <int> n1;
// 	std::vector <int> n2;

// 	for (int i = 1; i < 5; i++) {
// 		n1.push_back(i);
// 		n2.push_back(i + 4);
// 	}
// 	std::cout << "tamanho n1: " << n1.size() << std::endl;
// 	std::cout << "tamanho n2: " << n2.size() << std::endl;

// 	std::cout << "n1[2]: " << n1.at(2) << std::endl;
// 	std::cout << "n2[1]: " << n2.at(1) << std::endl;

// 	n1.swap(n2);

// 	std::cout << "n1: ";
// 	for (int i = 0; i < 4; i++)
// 		std::cout << n1[i] << " ";
// 	std::cout << std::endl << "n2: ";
// 	for (int i = 0; i < 4; i++)
// 		std::cout << n2[i] << " ";
// 	return (0);
// }



// .insert()
// .end()
// .erase()
// int main(void) {
// 	std::vector <int> n;

// 	n.push_back(0);
// 	n.push_back(1);
// 	n.push_back(3);
// 	n.push_back(5);
// 	n.push_back(999);

// 	n.insert(n.begin() + 2, 2);
// 	n.insert(n.end() - 2, 4);
// 	n.erase(n.end() - 1); // end() ME RETORNA O ENDERECO DO FECHAMENTO FIM DE STRING

// 	for (int i = 0; i < n.size(); i++)
// 		std::cout << n[i] << std::endl;
// 	while (!n.empty())
// 		n.pop_back();
// 	std::cout << "tamanho de n: " << n.size() << std::endl;
// 	return (0);
// }



// class aviao {
// 	public:
// 		int vel = 0;
// 		int velMax;
// 		std::string tipo;
// 		void ini(int tp);

// 	private:
// };

// void aviao::ini(int tp) {
// 	if (tp == 1) {
// 		this->velMax = 800;
// 		this->tipo = "jato";
// 	} else if (tp == 2) {
// 		this->velMax = 350;
// 		this->tipo = "monomotor";
// 	} else if (tp == 3) {
// 		this->velMax = 180;
// 		this->tipo = "planador";
// 	}
// }

// int main(void) {
// 	aviao *av1 = new aviao();

// 	av1->ini(1);
// 	std::cout << av1->velMax << std::endl;
// 	return (0);
// }



// #include "aviao.h" // ARQUIVO ./aviao.h

// int main(void) {
//     Aviao *av1 = new Aviao(1);

//     av1->imprimir();
// 	return (0);
// }



#include "classes.h"

int main(void) {
    Veiculo *v1 = new Veiculo(1);

    v1->setLigado(1);
    // v1->setVelMax(500);

    if (v1->getLigado()) {
        std::cout << "veiculo ligado" << std::endl;
    } else {
        std::cout << "veiculo desligado" << std::endl;
    }
    std::cout << "velocidade maxima: " << v1->getVelMax() << std::endl;

    return (0);
}