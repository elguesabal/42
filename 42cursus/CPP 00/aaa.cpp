#include <iostream>
#include <stack>
#include <queue>
#include <list>

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



// SOBRE CARGA DE FUNCAO (FUNCOES COM O MESMO NOME PODEM EXISTE CASO NAO SEJA IGUALMENTE PROTOTIPADA)
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
// .begin()
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
int main(void) {
	std::list <int> aula;
	std::list <int>::iterator it;

	aula.push_front(1);
	aula.push_front(2);
	aula.push_front(3);
	aula.push_front(4);
	aula.push_front(5);
	aula.reverse();

	while (!aula.empty()) {
		std::cout << aula.front() << std::endl;
		aula.pop_front();
	}
	return (0);
}