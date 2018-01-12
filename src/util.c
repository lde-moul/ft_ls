/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:47:40 by lde-moul          #+#    #+#             */
/*   Updated: 2018/01/12 17:17:16 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void		display_spaces(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(' ');
		i++;
	}
}

void		display_entry_link_target(t_entry *entry)
{
	char	*target_name;
	ssize_t	n;

	target_name = malloc_or_quit(entry->info.st_size + 1);
	n = readlink(entry->name, target_name, entry->info.st_size);
	if (n != entry->info.st_size)
		error("readlink failed");
	target_name[n] = '\0';
	ft_putstr(target_name);
	free(target_name);
}

const char	*file_name_only(const char *path)
{
	const char	*c;

	c = path;
	while (*c)
	{
		if (*c == '/')
			path = c + 1;
		c++;
	}
	return (path);
}
