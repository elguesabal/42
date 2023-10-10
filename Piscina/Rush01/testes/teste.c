#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	*nome;

	nome = (char *) malloc(21);

	printf("Digite seu nome: ");
	scanf("%s", nome);

	printf("%s", nome);
}
