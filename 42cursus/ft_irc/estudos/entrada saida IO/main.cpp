#include <poll.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <unistd.h> // USANDO ISSO PARA VER O PID

// int poll(struct pollfd *fds, nfds_t nfds, int timeout);
// int main(void) {
// 	int fd = open("arquivo.txt", O_RDONLY);

// 	if (fd < 0) {
// 		perror("Erro ao abrir o arquivo");
// 		return (1);
// 	}

// 	struct pollfd pfd;
// 	pfd.fd = fd;
// 	pfd.events = POLLIN;

// 	std::cout << "Aguardando dados no arquivo..." << std::endl;

// 	int ret = poll(&pfd, 1, -1);
// 	if (ret > 0 && (pfd.revents & POLLIN)) {
// 		std::cout << "Dados disponíveis para leitura no arquivo" << std::endl;
// 	} else {
// 		std::cout << "Erro no poll" << std::endl;
// 	}

// 	close(fd);
// 	return (0);
// }



// int main(void) {
// std::cout << "O PID do processo atual é: " << getpid() << std::endl;
// 	struct pollfd pfd;

// 	pfd.fd = STDIN_FILENO;
// 	pfd.events = POLLIN;

// 	std::cout << "Aguardando dados..." << std::endl;

// 	int ret = poll(&pfd, 1, -1);
// 	if (ret > 0 && (pfd.revents & POLLIN)) {
// 		std::cout << "Dados disponíveis para leitura" << std::endl;
// 	} else {
// 		std::cout << "Erro no poll" << std::endl;
// 	}

// 	return (0);
// }



int main(void) {
	struct pollfd fds[2];

	fds[0].fd = STDIN_FILENO;
	fds[0].events = POLLIN;

	fds[1].fd = STDOUT_FILENO;
	fds[1].events = POLLIN;

	std::cout << "Esperando eventos..." << std::endl;
	int ret = poll(fds, 2, 5000);

	if (ret == -1) {
		std::cout << "erro no poll" << std::endl;
		return (1);
	} else if (ret == 0) {
		std::cout << "Tempo esgotado sem eventos" << std::endl;
	} else {
		if (fds[0].revents & POLLIN) {
			std::cout << "Dados disponíveis no stdin" << std::endl;
		}

		if (fds[1].revents & POLLIN) {
			std::cout << "Dados disponíveis no fd 4" << std::endl;
		}
	}

	return (0);
}