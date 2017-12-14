#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

void print(char *s)
{
	printf("%s$\n", s);
}

char	it(unsigned int i, char c)
{
	return ('G' + i);
}

int		main(void)
{
	char *s = ft_strnew(8);
	print(s);

	ft_strcpy(s, "12345678");
	print(s);

	char *maps = ft_strmapi(s, it);
	print(maps);
	free(maps);

	free(s);
	return (0);
}
