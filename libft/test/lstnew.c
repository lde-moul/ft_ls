#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char *s = "Bonjour !";
	t_list *elem = ft_lstnew(s, strlen(s) + 1);

	free(elem->content);

	return (0);
}
