#include <iostream>
#include <deque>

int main(void) {
	std::deque<int> teste;

	teste.push_back(10);
	teste.push_back(20);
	teste.push_back(30);

	// for (int i = 0; !teste.empty(); i++) {
	// 	std::cout << "teste[" << i << "]: " << teste.front() << std::endl;
	//  teste.pop_front();
	// }

	for (int i = 0; i < teste.size(); i++) {
		std::cout << "teste[" << i << "]: " << teste[i] << std::endl;
	}
	return (0);
}