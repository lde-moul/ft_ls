#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

void	test(char *s1, char *s2)
{
	char *s = ft_strjoin(s1, s2);
	printf("'%s' + '%s' = '%s'\n", s1, s2, s);
	free(s);
}

int		main(void)
{
	test("Premier ", "test");
	test("Second", " test...");
	test(" Derni", "er test.");
	return (0);
}
