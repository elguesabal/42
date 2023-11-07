#include "ft_printf.h"
#include <stdio.h>

// MAIN DE TESTE (TOMARA Q EU NAO ESQUECA DE APAGAR ISTO ANTES DE ENVIAR)
int main() {
	int return1, return2;

	// PRINT
	return1 = ft_printf("ft_printf\n");
	return2 = printf("printf\n");
	printf("return1: %d\treturn2: %d\n\n", return1, return2);
	// PRINT

	// %c
	return1 = ft_printf("ft_printf: %c\n", 'a');
	return2 = printf("printf: %c\n", 'a');
	printf("return1: %d\treturn2: %d\n\n", return1, return2);
	// %c

	// %s
	return1 = ft_printf("ft_printf: %s\n", "vampeta");
	return2 = printf("printf: %s\n", "vampeta");
	printf("return1: %d\treturn2: %d\n\n", return1, return2);
	// %s

	// %p
	char c;
	return1 = ft_printf("ft_printf: %p\n", &c);
	return2 = printf("printf: %p\n", &c);
	printf("return1: %d\treturn2: %d\n\n", return1, return2);
	// %p

	// %d
	return1 = ft_printf("ft_printf: %d\n", 42);
	return2 = printf("printf: %d\n", 42);
	printf("return1: %d\treturn2: %d\n\n", return1, return2);
	// %d

	// %i
	return1 = ft_printf("ft_printf: %i\n", 42);
	return2 = printf("printf: %i\n", 42);
	printf("return1: %d\treturn2: %d\n\n", return1, return2);
	// %i

	// %u
	return1 = ft_printf("ft_printf: %u\n", 42);
	return2 = printf("printf: %u\n", 42);
	printf("return1: %d\treturn2: %d\n\n", return1, return2);
	// %u

	// %x
	return1 = ft_printf("ft_printf: %x\n", 42);
	return2 = printf("printf: %x\n", 42);
	printf("return1: %d\treturn2: %d\n\n", return1, return2);
	// %x

	// %X
	return1 = ft_printf("ft_printf: %X\n", 42);
	return2 = printf("printf: %X\n", 42);
	printf("return1: %d\treturn2: %d\n\n", return1, return2);
	// %X

	// %%
	return1 = ft_printf("ft_printf: %%\n");
	return2 = printf("printf: %%\n");
	printf("return1: %d\treturn2: %d\n\n", return1, return2);
	// %%

	// ft_printf("\n\n%p\n", 0);
	// printf("%p\n\n", 0);
}