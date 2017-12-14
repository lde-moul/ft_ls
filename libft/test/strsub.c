#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

void	test(char *s, size_t start, size_t len)
{
	char *ss = ft_strsub(s, start, len);
	printf("'%s'.sub(%d, %d) = '%s'\n", s, (int)start, (int)len, ss);
	free(ss);
}

int		main(void)
{
	test("Bonjour ceci est un test.", 8, 4);
	test("Bonjour ceci est un test.", 13, 12);
	test("Bonjour ceci est un test.", 0, 25);
	return (0);
}
