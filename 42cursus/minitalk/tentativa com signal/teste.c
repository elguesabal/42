// #include <stdio.h>

// void charToBinary(char c) {
//     int i;
//     printf("Caractere '%c' em binário: ", c);

//     i = 7;
//     while (i >= 0) {
//         if (c & (1 << i))
//             printf("1");
//         else
//             printf("0");
//         i--;
//     }

//     printf("\n");
// }

// int main() {
//     char character = 'A'; // Substitua pelo caractere desejado
//     charToBinary(character);

//     return 0;
// }












// #include <stdio.h>

// long long teste(int valor_decimal)
// {
//     long long valor_binario = 0;
//     int resto, sequencial = 1;

// 	//Enquanto o valor decimal for diferente de zero
//     while (valor_decimal != 0)
//     {
// 		//Pega o resto da divisão
//         resto = valor_decimal % 2;
        
//         //Divide o valor decimal por 2
//         valor_decimal /= 2;
        
//         //Incrementa o valor binário, multiplicando o resto da divisão pelo sequencial
//         valor_binario += resto * sequencial;
        
//         //Multiplica o sequencial por 10
//         sequencial *= 10;
//     }
    
//     return valor_binario;
// }

// // void    teste(int c)
// // {
// //     int i;
// //     int res;

// //     i = 0;
// //     while(i < 8)
// //     {
// //         res = 
// //         i++;
// //     }
// // }

// int main()
// {
//     char c = 'a';
//     printf("%lld", teste(c));
// }








// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// char* char_bin(char c) {
//     int i;
//     char *bin;

//     bin = malloc(9 * sizeof(char));
//     i = 7;
//     while(i >= 0)
//     {
//         bin[i] = (c & 1) + '0';
//         c >>= 1;
//         i--;
//     }
//     bin[8] = '\0';
//     return (bin);
// }

// int main()
// {
//     char c = 'a';
//     printf("%s\n", char_bin(c));
// }






// #include <stdio.h>
// #include <stdlib.h>

// char binaryToChar(const char *bin_str) {
//     int c = 0;
//     int i;

//     i = 0;
//     while(i < 8)
//     {
//         if(bin_str[i] == '1')
//             c |= (1 << (7 - i));
//         i++;
//     }
//     return ((char)c);
// }

// int main() {
//     char binaryString[9] = "01100001"; // 8 bits + '\0'

//     printf("Caractere correspondente: %c\n", binaryToChar(binaryString));

//     return 0;
// }






#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dest);
	len_src = ft_strlen(src);
	j = len_dst;
	i = 0;
	if (size > 0 && len_dst < size - 1)
	{
		while (len_dst + i < size - 1 && src[i] != '\0')
		{
			dest[j] = src[i];
			i++;
			j++;
		}
		dest[j] = '\0';
	}
	if (len_dst > size)
	{
		len_dst = size;
	}
	return (len_dst + len_src);
}

int	main(void)
{
	char	str1[20] = "testando ", str2[] = "o codigo";

	printf("Tamanho da nova string: %ld\nstr1: %s", ft_strlcat(str1, str2, sizeof(str1)), str1);
	return (0);
}