/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:13:25 by lde-moul          #+#    #+#             */
/*   Updated: 2017/12/21 17:56:40 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>

static void	display_invalid_operands(t_entries *operands, int n)
{
	t_entries	invalids;
	int			i;
	int			j;

	invalids.number = n;
	invalids.entries = malloc_or_quit(n * sizeof(t_entry));
	i = -1;
	j = 0;
	while (++i < operands->number)
		if (!operands->entries[i].valid)
			invalids.entries[j++] = operands->entries[i];
	sort_entries(&invalids);
	i = 0;
	while (i < invalids.number)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(invalids.entries[i].name);
		ft_putendl(": No such file or directory");
		i++;
	}
	free(invalids.entries);
}

static void	display_file_operands(t_entries *operands, int n)
{
	t_entries	files;
	int			max_field_sizes[6];
	int			i;
	int			j;

	files.number = n;
	files.entries = malloc_or_quit(n * sizeof(t_entry));
	i = -1;
	j = 0;
	while (++i < operands->number)
		if (operands->entries[i].valid
		&& (operands->entries[i].info.st_mode & S_IFMT) != S_IFDIR)
			files.entries[j++] = operands->entries[i];
	sort_entries(&files);
	i = 0;
	while (i < files.number)
		fill_entry_fields(&files.entries[i++]);
	get_max_field_sizes(&files, max_field_sizes);
	i = 0;
	while (i < files.number)
		display_entry(&files.entries[i++], max_field_sizes);
	free(files.entries);
}

static void	display_directory_operands(t_entries *operands, int n)
{
	t_entries	directories;
	int			i;
	int			j;

	directories.number = n;
	directories.entries = malloc_or_quit(n * sizeof(t_entry));
	i = -1;
	j = 0;
	while (++i < operands->number)
		if (operands->entries[i].valid
		&& (operands->entries[i].info.st_mode & S_IFMT) == S_IFDIR)
			directories.entries[j++] = operands->entries[i];
	sort_entries(&directories);
	i = 0;
	while (i < directories.number)
	{
		// display_entry(&directories.entries[i]);
		i++;
	}
	free(directories.entries);
}

static void	display_operands(t_entries *operands)
{
	int			num_invalids;
	int			num_files;
	int			num_dirs;
	int			i;

	num_invalids = 0;
	num_files = 0;
	num_dirs = 0;
	i = 0;
	while (i < operands->number)
	{
		if (!operands->entries[i].valid)
			num_invalids++;
		else if ((operands->entries[i].info.st_mode & S_IFMT) == S_IFDIR)
			num_dirs++;
		else
			num_files++;
		i++;
	}
	display_invalid_operands(operands, num_invalids);
	display_file_operands(operands, num_files);
	display_directory_operands(operands, num_dirs);
}

int			main(int argc, char **argv)
{
	t_options	options;
	t_entries	operands;

	parse_arguments(argc, argv, &options, &operands);
	display_operands(&operands);
	free(operands.entries);
	return (0);
}
