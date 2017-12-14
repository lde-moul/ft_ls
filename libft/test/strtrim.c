#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

void	test(char *s)
{
	char *ts = ft_strtrim(s);
	printf("'%s' => '%s'\n", s, ts);
	free(ts);
}

int		main(void)
{
	test("   \n\n \t  \t\tPremier  ");
	test("");
	test("A");
	test("  ABCDEF   ");
	test("     ");
	test(" ");
	test("\n");
	test("\t\t\n \t");
	test("\n \n\n\n\t   f \nFS\n\t\t       ");
	test("     FIN");
	test("Bo bonjour   ");
	test("DEBUT     ");
	return (0);
}
