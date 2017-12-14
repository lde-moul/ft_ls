#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char *src = "Salut les gens";
	char dst1[30];
	char dst2[30];
	ft_bzero(dst1, 30);
	ft_bzero(dst2, 30);
	ft_strncpy(dst1, src, 5);
	strncpy(dst2, src, 5);
	printf("src = $%s$\n", src);
	printf("dst1 = $%s$\n", dst1);
	printf("dst2 = $%s$\n", dst2);
	return (0);
}
