#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    // Truncar a string se ela exceder o tamanho máximo
    if (input.size() > 3) {
        input = input.substr(0, 3);
        input[2] = '.';
    }

    // Usar std::setw para definir a largura mínima
    std::cout << std::setw(3) << input << std::endl;

    return 0;
}
