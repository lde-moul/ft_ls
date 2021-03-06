/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:20:35 by lde-moul          #+#    #+#             */
/*   Updated: 2018/03/19 19:41:54 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <dirent.h>
#include <stdlib.h>

static void	add_dir_entry(struct dirent *dir_entry, t_entries *entries,
							const char *parent_name)
{
	t_entry	*new_entries;
	t_entry	*entry;

	if (entries->number + 1 > entries->allocated)
	{
		entries->allocated *= 2;
		new_entries = malloc_or_quit(entries->allocated * sizeof(t_entry));
		ft_memcpy(new_entries, entries->entries,
					entries->number * sizeof(t_entry));
		free(entries->entries);
		entries->entries = new_entries;
	}
	entry = &entries->entries[entries->number];
	entry->name = malloc_or_quit(ft_strlen(parent_name)
									+ ft_strlen(dir_entry->d_name) + 2);
	ft_strcpy(entry->name, parent_name);
	ft_strcat(entry->name, "/");
	ft_strcat(entry->name, dir_entry->d_name);
	if (!entry->name)
		error("Out of memory");
	if (lstat(entry->name, &entry->info))
		error("lstat failed");
	entries->number++;
}

static int	load_directory(const char *name, t_entries *entries,
							t_options *options, int named)
{
	struct dirent	*dir_entry;
	DIR				*dir;

	if (named)
	{
		ft_putstr(name);
		ft_putendl(":");
	}
	dir = opendir(name);
	if (!dir)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(file_name_only(name), 2);
		ft_putendl_fd(": Permission denied", 2);
		return (0);
	}
	entries->number = 0;
	entries->allocated = 1024;
	entries->entries = malloc_or_quit(1024 * sizeof(t_entry));
	while ((dir_entry = readdir(dir)))
		if (name_displayable(dir_entry->d_name, options))
			add_dir_entry(dir_entry, entries, name);
	closedir(dir);
	return (1);
}

static void	display_sub_directories(t_entries *entries, t_options *options)
{
	const char	*file_name;
	int			i;

	i = 0;
	while (i < entries->number)
	{
		if ((entries->entries[i].info.st_mode & S_IFMT) == S_IFDIR)
		{
			file_name = file_name_only(entries->entries[i].name);
			if (ft_strcmp(file_name, ".") && ft_strcmp(file_name, ".."))
				display_directory(entries->entries[i].name, options, 1);
		}
		i++;
	}
}

void		display_directory(const char *name, t_options *options, int named)
{
	t_entries	entries;
	int			blocks;
	int			i;

	if (options->not_first)
		ft_putchar('\n');
	options->not_first = 1;
	if (!load_directory(name, &entries, options, named))
		return ;
	blocks = 0;
	i = 0;
	while (i < entries.number)
		blocks += entries.entries[i++].info.st_blocks;
	if (options->long_format)
	{
		ft_putstr("total ");
		ft_putnbr(blocks);
		ft_putchar('\n');
	}
	display_entries(&entries, options);
	if (options->recursive)
		display_sub_directories(&entries, options);
	free_entries(&entries, options);
}
