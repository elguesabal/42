#include <stdio.h>

void *memset(void *ptr, int valor, size_t num_bytes) {
    unsigned char *p = ptr;
    for (size_t i = 0; i < num_bytes; ++i) {
        *p++ = (unsigned char)valor;
    }
}

int	main(void)
{
	char	str[5] = "teste";

	//memset(str, '*', 10);
	//printf("str: %s", str);
printf("%ld", sizeof(str));
	return (0);
}
