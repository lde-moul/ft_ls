/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:07:09 by lde-moul          #+#    #+#             */
/*   Updated: 2017/12/21 18:01:13 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>

static void	display_entry_mode(mode_t mode)
{
	if ((mode & S_IFMT) == S_IFREG)
		ft_putchar('-');
	else if ((mode & S_IFMT) == S_IFDIR)
		ft_putchar('d');
	else if ((mode & S_IFMT) == S_IFLNK)
		ft_putchar('l');
	else if ((mode & S_IFMT) == S_IFSOCK)
		ft_putchar('s');
	else if ((mode & S_IFMT) == S_IFIFO)
		ft_putchar('p');
	else if ((mode & S_IFMT) == S_IFBLK)
		ft_putchar('b');
	else if ((mode & S_IFMT) == S_IFCHR)
		ft_putchar('c');
	ft_putchar(mode & S_IRUSR ? 'r' : '-');
	ft_putchar(mode & S_IWUSR ? 'w' : '-');
	ft_putchar(mode & S_IXUSR ? 'x' : '-');
	ft_putchar(mode & S_IRGRP ? 'r' : '-');
	ft_putchar(mode & S_IWGRP ? 'w' : '-');
	ft_putchar(mode & S_IXGRP ? 'x' : '-');
	ft_putchar(mode & S_IROTH ? 'r' : '-');
	ft_putchar(mode & S_IWOTH ? 'w' : '-');
	ft_putchar(mode & S_IXOTH ? 'x' : '-');
}

void		display_entry(t_entry *entry, int *max_field_sizes)
{
	int	i;
	int	j;

	display_entry_mode(entry->info.st_mode);
	ft_putchar(' ');
	i = 0;
	while (i < 6)
	{
		ft_putstr(entry->field_text[i]);
		j = -1;
		while (j < max_field_sizes[i] - entry->field_size[i])
		{
			ft_putchar(' ');
			j++;
		}
		i++;
	}
	ft_putchar(' ');
	ft_putendl(entry->name);
}

void		get_max_field_sizes(t_entries *entries, int *max_field_sizes)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		max_field_sizes[i] = 0;
		i++;
	}
	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < entries->number)
		{
			if (max_field_sizes[i] < entries->entries[j].field_size[i])
				max_field_sizes[i] = entries->entries[j].field_size[i];
			j++;
		}
		i++;
	}
}

static void	fill_entry_time_field(t_entry *entry)
{
	char	*s;

	s = ctime(&entry->info.st_mtimespec.tv_sec);
	entry->field_text[4] = malloc_or_quit(7); // !!! Free
	ft_strncpy(entry->field_text[4], s + 4, 6);
	entry->field_size[4] = ft_strlen(entry->field_text[4]);
	if (time(NULL) - entry->info.st_mtimespec.tv_sec < 15552000
	|| entry->info.st_mtimespec.tv_sec - time(NULL) < 15552000)
	{
		entry->field_text[5] = malloc_or_quit(6); // !!! Free
		ft_strncpy(entry->field_text[5], s + 11, 5);
	}
	else
	{
		entry->field_text[5] = malloc_or_quit(5); // !!! Free
		ft_strncpy(entry->field_text[5], s + 20, 4);
	}
	entry->field_size[5] = ft_strlen(entry->field_text[5]);
}

void		fill_entry_fields(t_entry *entry)
{
	struct passwd	*user;
	struct group	*group;

	entry->field_text[0] = ft_itoa(entry->info.st_nlink); // !!! Check // !!! Free
	entry->field_size[0] = ft_strlen(entry->field_text[0]);
	user = getpwuid(entry->info.st_uid);
	entry->field_text[1] = user ?
		ft_strdup(user->pw_name) : ft_itoa(entry->info.st_uid);
	entry->field_size[1] = ft_strlen(entry->field_text[1]);
	group = getgrgid(entry->info.st_gid);
	entry->field_text[2] = group ?
		ft_strdup(group->gr_name) : ft_itoa(entry->info.st_gid);
	entry->field_size[2] = ft_strlen(entry->field_text[2]);
	entry->field_text[3] = ft_itoa(entry->info.st_size); // !!! long
	entry->field_size[3] = ft_strlen(entry->field_text[3]);
	fill_entry_time_field(entry);
}
