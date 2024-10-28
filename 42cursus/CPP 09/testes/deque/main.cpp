#include <iostream>
#include <deque>

// int main(void) {
// 	std::deque<int> teste;

// 	teste.push_back(10);
// 	teste.push_back(20);
// 	teste.push_back(30);

// 	// for (int i = 0; !teste.empty(); i++) {
// 	// 	std::cout << "teste[" << i << "]: " << teste.front() << std::endl;
// 	//  teste.pop_front();
// 	// }

// 	for (int i = 0; i < teste.size(); i++) {
// 		std::cout << "teste[" << i << "]: " << teste[i] << std::endl;
// 	}
// 	return (0);
// }



int main(void) {
	std::deque<int> teste;

	teste.push_back(1);
	teste.push_back(2);
	teste.push_back(3);
	teste.push_back(4);
	teste.push_back(5);

	std::deque<int>::iterator it = teste.begin() + 2;

	// teste.erase(it - 1);

	// std::cout << *(it - 1) << std::endl;
	// std::cout << *it << std::endl;
	// std::cout << *(it + 1) << std::endl;

	std::cout << *it << std::endl;
	teste.erase(it);
	std::cout << *it << std::endl;
	teste.erase(it - 1);
	std::cout << *it << std::endl;
}