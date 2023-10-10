#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin(int size, char **strs, char *sep) {
	int i, j, k, size_new_str = 0;

	i = 0;
	while (i < size) {
		j = 0;
		while (strs[i][j] != '\0') {
			size_new_str++;
			j++;
		}
		i++;
	}
	char *new_str = malloc(size_new_str * sizeof(char*));
	new_str[0] = '\0';

	i = 0;
	while (i < size) {
		j = 0;
		while (new_str[j] != '\0') {
			j++;
		}

		k = 0;
		while (strs[i][k] != '\0') {
			new_str[j] = strs[i][k];
			j++;
			k++;
		}
		new_str[j] = sep[0];
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

int main(void) {
	int size = 3;
	char str1[] = "teste1";
	char str2[] = "teste2";
	char str3[] = "teste3";

	char **strs = malloc(size * sizeof(char*));
	strs[0] = str1;
	strs[1] = str2;
	strs[2] = str3;

	char *sep = " ";

	printf("%s", ft_strjoin(size, strs, sep));
}