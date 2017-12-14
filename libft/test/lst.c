#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

void	delete_elem(void *content, size_t content_size)
{
}

void	display_elem(t_list *elem)
{
	ft_putendl(elem->content);
}

t_list	*map_list2(t_list *elem)
{
	t_list	*newelem;
	char	*s;

	s = &((char*)(elem->content))[1];
	return (ft_lstnew(s, ft_strlen(s)));
}

int		main(void)
{
	t_list *list;
	t_list *list2;

	list = NULL;
	ft_lstadd(&list, ft_lstnew("Bonjour", 8));
	ft_lstadd(&list, ft_lstnew("les", 4));
	ft_lstadd(&list, ft_lstnew("gens", 5));

	ft_lstiter(list, display_elem);

	list2 = ft_lstmap(list, map_list2);
	if (!list2)
		return (1);
	ft_lstiter(list2, display_elem);

	ft_lstdel(&list, delete_elem);
	ft_lstdel(&list2, delete_elem);

	return (0);
}
