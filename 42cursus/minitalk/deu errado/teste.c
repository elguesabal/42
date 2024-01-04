// #include <stdio.h>

// int main()
// {
//     int i = 0;
//     printf("%p", &i);
// }



// 7ffe95365144
// 140731401785668
// 11111111111111010010101001101100101000101000100



// testando transformar texto em binario
// 01110100 01100101 01110011 01110100 01100001 01101110 01100100 01101111 00100000 01110100 01110010 01100001 01101110 01110011 01100110 01101111 01110010 01101101 01100001 01110010 00100000 01110100 01100101 01111000 01110100 01101111 00100000 01100101 01101101 00100000 01100010 01101001 01101110 01100001 01110010 01101001 01101111 












// #include <stdio.h>

// // Função para converter binário para decimal
// int binarioParaDecimal(long long binario) {
//     int decimal = 0, base = 1, resto;

//     // Converte o número binário para decimal
//     while (binario > 0) {
//         resto = binario % 10;
//         decimal += resto * base;
//         binario /= 10;
//         base *= 2;
//     }

//     return decimal;
// }

// int main() {
//     long long numeroBinario;

//     // Solicita ao usuário inserir um número binário
//     printf("Digite um número binário: ");
//     scanf("%lld", &numeroBinario);

//     // Chama a função para converter e imprimir o número decimal
//     int numeroDecimal = binarioParaDecimal(numeroBinario);
//     printf("O número decimal equivalente: %d\n", numeroDecimal);

//     return 0;
// }











#include <stdio.h>
#include <stdlib.h>

void	*ponteiro(void)
{
	return ((char *)94485062976160);
}

void    imprimir(unsigned long long p)
{
    printf("%llu\n", p);
}

int	main(int argc, char **argv)
{
	char	*p;

	// p = malloc(1 * sizeof(int));
	// *p = 15;

	p = ponteiro();
	imprimir((unsigned long long)p);

	return (0);
}