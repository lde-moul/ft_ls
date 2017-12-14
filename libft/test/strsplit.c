#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char *s = "      split       this for   me  !       ";
	char **ss = ft_strsplit(s, ' ');
	while (*ss)
	{
		printf("%s$\n", *ss);
		ss++;
	}
	return (0);
}
