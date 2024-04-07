#include "../minishell.h"

void    cd(char *path)
{
	// char	*command;
	char	*pwd;
	int		i;

// printf("path: %s\n", path);

	path += 2;
	while (*path != ' ' && *path != '	')
		path++;
    path++;

	pwd = getcwd(NULL, 0);
// printf("pwd: %s\n", pwd);

	if (path[0] == '.' && path[1] == '.')
	{
		i = 0;
		while (pwd[i])
			i++;

		while (pwd[i] != '/')
		{
			pwd[i] = '\0';
			i--;
		}
		pwd[i] = '\0';	// pwd[i] == '/';
	}
	else
	{

	}

// printf("teste path: %s\n", path);
// printf("pwd: %s\n", pwd);

// if (chdir("/home/jose/programacao/42/42cursus/minishell/estudos/jos") == -1) AKI DA ERRO FALTA ARRUMAR O ELSE
	if (chdir(pwd) == -1)
        printf("minishell: cd: %s: Arquivo ou diretório inexistente\n", pwd);

	// printf("onde estou: %s\n", pwd);

	// free(command);
	free(pwd);
}