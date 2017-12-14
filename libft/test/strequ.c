#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

void	test(char *s1, char *s2)
{
	printf("'%s' %c= '%s'\n", s1, ft_strequ(s1, s2) ? '=' : '!', s2);
}

int		main(void)
{
	test("Premier test", "Prem test");
	test("First test", "First test");
	test("1st tst", "1th test");
	test("", "gsdgsdhgs");
	test("", "");
	test("GSDHGUI ", "gsdg");
	test("ds", "F gG");

	return (0);
}
