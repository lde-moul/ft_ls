/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:47:40 by lde-moul          #+#    #+#             */
/*   Updated: 2018/04/12 18:39:03 by lde-moul         ###   ########.fr       */
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

int			name_displayable(const char *name, t_options *options)
{
	if (name[0] != '.')
		return (1);
	if (!(options->all || options->all_normal))
		return (0);
	return (!options->all_normal
	|| (ft_strcmp(name, ".") && ft_strcmp(name, "..")));
}

void		fill_entry_size_or_device_field(t_entry *entry)
{
	char	field[32];
	char	*s;

	if ((entry->info.st_mode & S_IFMT) == S_IFBLK
	|| (entry->info.st_mode & S_IFMT) == S_IFCHR)
	{
		if (!(s = ft_itoa(entry->info.st_rdev >> 24)))
			error("Out of memory");
		ft_strcpy(field, s);
		free(s);
		if (!(s = ft_itoa(entry->info.st_rdev & 0xff)))
			error("Out of memory");
		ft_strncat(field, ",   ", 5 - ft_strlen(s));
		ft_strcat(field, s);
		free(s);
		if (!(entry->field_text[3] = ft_strdup(field)))
			error("Out of memory");
	}
	else if (!(entry->field_text[3] = ft_itoa(entry->info.st_size)))
		error("Out of memory");
	entry->field_size[3] = ft_strlen(entry->field_text[3]);
}
