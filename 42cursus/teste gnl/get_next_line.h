#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** Necessário para malloc(), free() e write(). Também para typedef size_t e sizeof()*/

# include <unistd.h>
# include <stdlib.h>

/*
** Macro para o tamanho do buffer, o número máximo de descritores de arquivo disponíveis e
** para obter o valor de retorno correto da função gnl_read_file().
** Encontre o número máximo de arquivos:
** Mac: launchctl limit maxfiles
** Linux: ulimit -n
*/

# define BUFF_SIZE 80
# define MAX_FD 1024 + 1
# define RET_VALUE(ret)	ret > 0 ? 1 : ret

/*
** Protótipo para a função get_next_line().
*/

int		get_next_line(int const fd, char **line);

#endif