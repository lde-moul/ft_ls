/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:13:25 by lde-moul          #+#    #+#             */
/*   Updated: 2018/01/12 18:10:57 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>

static void	display_invalid_operands(t_entries *operands, int n,
										t_options *options)
{
	t_entries	invalids;
	int			i;
	int			j;

	if (n == 0)
		return ;
	invalids.number = n;
	invalids.entries = malloc_or_quit(n * sizeof(t_entry));
	i = -1;
	j = 0;
	while (++i < operands->number)
		if (!operands->entries[i].valid)
			invalids.entries[j++] = operands->entries[i];
	sort_entries(&invalids, options);
	i = 0;
	while (i < invalids.number)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(invalids.entries[i].name);
		ft_putendl(": No such file or directory");
		i++;
	}
	free_entries(&invalids);
}

static void	display_file_operands(t_entries *operands, int n,
										t_options *options)
{
	t_entries	files;
	int			i;
	int			j;

	if (n == 0)
		return ;
	files.number = n;
	files.entries = malloc_or_quit(n * sizeof(t_entry));
	i = -1;
	j = 0;
	while (++i < operands->number)
		if (operands->entries[i].valid
		&& (operands->entries[i].info.st_mode & S_IFMT) != S_IFDIR)
			files.entries[j++] = operands->entries[i];
	display_entries(&files, options);
	free_entries(&files);
}

static void	display_directory_operands(t_entries *operands, int n,
										t_options *options)
{
	t_entries	directories;
	int			i;
	int			j;

	if (n == 0)
		return ;
	directories.number = n;
	directories.entries = malloc_or_quit(n * sizeof(t_entry));
	i = -1;
	j = 0;
	while (++i < operands->number)
		if (operands->entries[i].valid
		&& (operands->entries[i].info.st_mode & S_IFMT) == S_IFDIR)
			directories.entries[j++] = operands->entries[i];
	sort_entries(&directories, options);
	i = 0;
	while (i < directories.number)
	{
		display_directory(directories.entries[i].name, options);
		i++;
	}
	free_entries(&directories);
}

static void	display_operands(t_entries *operands, t_options *options)
{
	int	num_invalids;
	int	num_files;
	int	num_dirs;
	int	i;

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
	display_invalid_operands(operands, num_invalids, options);
	display_file_operands(operands, num_files, options);
	display_directory_operands(operands, num_dirs, options);
}

int			main(int argc, char **argv)
{
	t_options	options;
	t_entries	operands;

	parse_arguments(argc, argv, &options, &operands);
	display_operands(&operands, &options);
	if (operands.number)
		free(operands.entries);
	return (0);
}
