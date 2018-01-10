/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:20:35 by lde-moul          #+#    #+#             */
/*   Updated: 2018/01/10 19:12:14 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <dirent.h>
#include <stdlib.h>

static void	add_dir_entry(struct dirent *dir_entry, t_entries *entries)
{
	t_entry	*new_entries;
	t_entry	*entry;

	if (entries->number + 1 > entries->allocated)
	{
		entries->allocated *= 2;
		new_entries = malloc_or_quit(entries->allocated * sizeof(t_entry));
		ft_memcpy(new_entries, entries->entries, entries->number * sizeof(t_entry));
		free(entries->entries);
		entries->entries = new_entries;
 	}
	entry = &entries->entries[entries->number];
	entry->name = ft_strdup(dir_entry->d_name);
	if (!entry->name)
		error("Out of memory");
	if (lstat(entry->name, &entry->info))
		error("lstat failed");
	entries->number++;
}

static void load_directory(const char *name, t_entries *entries)
{
	struct dirent	*dir_entry;
	DIR				*dir;

	dir = opendir(name);
	if (!dir)
		error("Can't open directory");
	entries->number = 0;
	entries->allocated = 1024;
	entries->entries = malloc_or_quit(1024 * sizeof(t_entry));
	while ((dir_entry = readdir(dir)))
		add_dir_entry(dir_entry, entries);
	closedir(dir);
}

void		display_directory(t_entry *entry, t_options *options)
{
	t_entries	entries;

	ft_putstr(entry->name);
	ft_putendl(":");
	load_directory(entry->name, &entries);
	display_entries(&entries, options);
	free_entries(&entries);
}
