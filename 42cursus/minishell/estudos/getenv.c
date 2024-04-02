#include <stdio.h>
#include <stdlib.h>

// getenv



int	main(void)
{
	char	*str;

	str = getenv("USER");

	printf("variavel: %s\n", str);

	return (0);
}