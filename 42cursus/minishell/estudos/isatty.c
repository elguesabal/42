#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

// isatty ttyname ttyslot tcgetattr tcsetattr ioctl



// int	main(void)
// {
// 	if (isatty(STDOUT_FILENO))
// 		printf("A saida padrao esta associada a um terminal\n");
// 	else
// 		printf("A saida padrao nao esta associada a um terminal.\n");

// 	return (0);
// }





// int	main(void)
// {
// 	char	*name;

// 	name = ttyname(STDOUT_FILENO);

// 	printf("nome: %s\n", name);

// 	return (0);
// }





// int	main(void)	// NAO ENTENDI A FINALIDADE DESTA FUNCAO
// {

// 	printf("%d\n", ttyslot());

// 	return (0);
// }





// int	main(void)	// NAO ENTENDI A FINALIDADE DESTA FUNCAO
// {
// 	struct termios	attr;

// 	tcgetattr(STDOUT_FILENO, &attr);

//     printf("Atributos atuais do terminal:\n");
//     printf("c_iflag: 0x%08x\n", attr.c_iflag);
//     printf("c_oflag: 0x%08x\n", attr.c_oflag);
//     printf("c_cflag: 0x%08x\n", attr.c_cflag);
//     printf("c_lflag: 0x%08x\n", attr.c_lflag);

// 	return (0);
// }





// int	main(void)	// NAO ENTENDI A FINALIDADE DESTA FUNCAO // SAPOHA AKI FEZ MERDA NO MEU TERMINAL
// {
// 	struct termios	attr;

// 	tcgetattr(STDOUT_FILENO, &attr);

// 	// attr.c_lflag &= ~(ICANON | ECHO);	// DESATIVA O MODO CANONICO E A ECOAGEM

// 	// attr.c_lflag |= ICANON;	// ATIVA O MODO CANONICO
// 	// attr.c_lflag |= ECHO;	// ATIVA A ECOAGEM

// 	tcsetattr(STDOUT_FILENO, TCSANOW, &attr);

// 	return (0);
// }





// int	main(void)	// EXPLORAR MAIS ESSA FUNCAO DPS
// {
// 	struct winsize	ws;

// 	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

//     printf("numero de linhas do terminal: %d\n", ws.ws_row);
//     printf("numero de colunas do terminal: %d\n", ws.ws_col);

// 	printf("latgura da janela em pixels: %d\n", ws.ws_xpixel);
// 	printf("altura da janela em pixels: %d\n", ws.ws_ypixel);

// 	return (0);
// }





// me explique as funcoes "tgetent()", "tgetflag()", "tgetnum()", "tgetstr()", "tgoto()" e "tputs()"

int	main(void)
{


	return (0);
}