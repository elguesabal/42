#include <stdio.h>
#include <unistd.h>

// isatty ttyname



// int	main(void)
// {
// 	if (isatty(STDOUT_FILENO))
// 		printf("A saida padrao esta associada a um terminal\n");
// 	else
// 		printf("A saida padrao nao esta associada a um terminal.\n");

// 	return (0);
// }





int	main(void)
{
	char	*name;

	name = ttyname(STDOUT_FILENO);

	printf("nome: %s\n", name);

	return (0);
}
