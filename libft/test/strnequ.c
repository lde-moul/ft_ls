#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

void	test(char *s1, char *s2, size_t n)
{
	printf("'%s' %c= '%s'\n", s1, ft_strnequ(s1, s2, n) ? '=' : '!', s2);
}

int		main(void)
{
	test("Premier test", "Prem test", 4);
	test("First test", "First test", 30);
	test("1st tst", "1th test", 0);
	test("", "gsdgsdhgs", 1);
	test("", "", 2);
	test("GSDHGUI ", "gsdg", 4);
	test("ds", "F gG", 2);

	return (0);
}
