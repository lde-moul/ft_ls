#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	size_t nnn = atoi(argv[1]);

	printf("size = %d\n", (int)nnn);

	char s1[30] = "ABC";
	char *s2 = "DEF";
	int n = strlcat(s1, s2, nnn);
	printf("%d:%s$\n", n, s1);

	char ss1[30] = "ABC";
	char *ss2 = "DEF";
	int nn = ft_strlcat(ss1, ss2, nnn);
	printf("%d:%s$\n", nn, ss1);

	return (0);
}
