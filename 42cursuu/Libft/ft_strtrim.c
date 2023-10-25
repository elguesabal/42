

#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int	i, j, k;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (s1[i] == *set)
		{
			j++;
		}
		i++;
	}
	str = malloc((i - j) * sizeof(char *));
	if (str)
	{
		str[i] = '\0';
		k = i - j;
		do
		{
			i--;
			if (s1[i] != *set)
			{
				k--;
				str[k] = s1[i];
			}
		}
		while (i);
	}
	return (str);	// TERMINAR ESSA POHA AKI // ACHO Q TERMINEI MAS TEM Q CONFIRMAR PQ EU TO COM SONO
}

// bool is_trimmed_char(char c, const char *set) {
//     while (*set) {
//         if (*set == c) {
//             return true; // O caractere está no conjunto de caracteres para remover
//         }
//         set++;
//     }
//     return false; // O caractere não está no conjunto de caracteres para remover
// }

// char *strtrim(const char *s1, const char *set) {
//     if (s1 == NULL || set == NULL) {
//         return NULL;
//     }

//     // Avança o ponteiro para o primeiro caractere que não precisa ser removido
//     while (*s1 && is_trimmed_char(*s1, set)) {
//         s1++;
//     }

//     // Move o ponteiro para o final da string para encontrar o último caractere a ser mantido
//     const char *end = s1;
//     while (*end) {
//         end++;
//     }
//     end--; // Aponta para o último caractere válido

//     // Retrocede o ponteiro end para o último caractere que não precisa ser removido
//     while (end > s1 && is_trimmed_char(*end, set)) {
//         end--;
//     }

//     // Calcula o comprimento da string após a remoção dos caracteres indesejados
//     size_t trimmed_length = end - s1 + 1;

//     // Aloca memória para a nova string e copia os caracteres válidos
//     char *trimmed_str = (char *)malloc(trimmed_length + 1);
//     if (trimmed_str == NULL) {
//         return NULL; // Falha na alocação de memória
//     }

//     // Copia os caracteres válidos para a nova string
//     for (size_t i = 0; i < trimmed_length; i++) {
//         trimmed_str[i] = *s1;
//         s1++;
//     }

//     // Adiciona o caractere nulo no final da nova string
//     trimmed_str[trimmed_length] = '\0';

//     return trimmed_str;
// }


int	main(void)
{
	printf("return: %s\n", ft_strtrim("teste", "e")); // PODERIA EXCLUIR MAIS DE 1 CARACTER????
//printf("return: %s", strtrim("teste", "es"));
	return (0);
}
