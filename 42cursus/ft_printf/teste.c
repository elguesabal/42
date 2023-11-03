#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

// int my_putchar(char c) {
//     return write(1, &c, 1);
// }

// int main() {
//     // int teste = printf("teste %d", 100, 200);
//     // printf("\nreturn: %d", teste);
//     void str;
//     char teste[] = sprintf(str, "%p\n", (void)str);
//     printf("%s", teste);
//     return 0;
// }


// void print_address(void *ptr) {
//     unsigned long long int address = (unsigned long long int)ptr;
//     char hex_digits[] = "0123456789abcdef";
//     char buffer[16]; // assumindo um ponteiro de 64 bits, precisamos de 16 caracteres
//     int i;

//     // Converter o endereço para hexadecimal e armazenar em buffer
//     for (i = 0; i < 16; ++i) {
//         buffer[i] = hex_digits[address & 0xf]; // obter o dígito hexadecimal mais à direita
//         address >>= 4; // deslocar 4 bits para a direita
//     }

//     // Escrever o buffer na saída padrão (stdout) usando a função write()
//     write(1, "0x", 2); // Escrever o prefixo "0x" indicando que é um endereço hexadecimal
//     write(1, buffer, 16);
//     write(1, "\n", 1); // Nova linha no final
// }

// int main() {
//     int variable;
//     void *ptr = &variable; // Obtendo o endereço de memória da variável

//     print_address(ptr);

//     printf("%p", ptr);
//     return 0;
// }

// int main() {
//     int i;
//     printf("%i\n%p", &i, &i);
// // 6422047
// // 000000000061FE1F
// // 610010 + 70000 + 6900 + 10 + 70
//     printf("\n000000000061%d%d1%d", 'F', 'E', 'C');
// }

// void    teste(char *s, ...) {
//     va_list arg1, arg2;
//     va_start(arg1, s);

// 	va_copy(arg2, arg1);

//     printf("%s, %d", s, va_arg(arg2, int));
// 	printf(", %d", va_arg(arg2, int));
// 	printf(", %d", va_arg(arg2, int));
// 	printf(", %d", va_arg(arg2, int));

//     va_end(arg1);
// 	va_end(arg2);
// }

// int main() {
//     teste("teste", 1, 2, 3);
// }

// int main() {
// 	printf("%u", -10);
// }

// int main() {
//     int decimal = 42;
//     int octal = 052;      // O prefixo 0 indica um número octal (base 8)
//     int hexadecimal = 0x2A; // O prefixo 0x ou 0X indica um número hexadecimal (base 16)

//     printf("Decimal (%%d): %d\n", decimal);   // Imprime 42 em decimal usando %d
//     printf("Octal (%%d): %d\n", octal);       // Imprime 42 (052 é interpretado como decimal) usando %d
//     printf("Hexadecimal (%%d): %d\n\n", hexadecimal); // Imprime 42 (0x2A é interpretado como decimal) usando %d
    
//     printf("Decimal (%%i): %i\n", decimal);   // Imprime 42 em decimal usando %i
//     printf("Octal (%%i): %i\n", octal);       // Imprime 42 (052 é interpretado como octal) usando %i
//     printf("Hexadecimal (%%i): %i\n", hexadecimal); // Imprime 42 (0x2A é interpretado como hexadecimal) usando %i

//     return 0;
// }

// int main() {
//     int numero = 255; // Um número inteiro

//     printf("Numero em hexadecimal: %x\n", numero);

//     return 0;
// }

void decimalParaHexadecimal(int numero, char c) {
    if (numero == 0) {
        printf("0");
        return;
    }

    int numeroOriginal = numero;
    char hexaDecimal[100]; // Um array para armazenar os dígitos hexadecimais
    int indice = 0;

    while (numero > 0) {
        int resto = numero % 16;

        // Converte números de 10 a 15 para letras A-F
        if (resto < 10) {
            hexaDecimal[indice] = resto + '0';
        } else {
            hexaDecimal[indice] = resto - 10 + c;
        }

        indice++;
        numero = numero / 16;
    }

    printf("Número decimal %d em hexadecimal: ", numeroOriginal);

    // Imprime os dígitos hexadecimais em ordem reversa
    for (int i = indice - 1; i >= 0; i--) {
        printf("%c", hexaDecimal[i]);
    }

    printf("\n");
}
int main() {
    int numero = 16;

    decimalParaHexadecimal(numero, 'a');

    return 0;
}
