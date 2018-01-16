/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:58:56 by lde-moul          #+#    #+#             */
/*   Updated: 2018/01/16 18:45:20 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>

static void	parse_option(char c, t_options *options)
{
	if (c == 'a')
		options->all = 1;
	else if (c == 'l')
		options->long_format = 1;
	else if (c == 'R')
		options->recursive = 1;
	else if (c == 't')
		options->sort_by_time = 1;
	else if (c == 'S')
		options->sort_by_size = 1;
	else if (c == 'r')
		options->sort_reversed = 1;
	else if (c == 'c')
		options->ctime = 1;
	else if (c == 'U')
		options->btime = 1;
	else
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: ft_ls [-RSUaclrt] [file ...]", 2);
		exit(1);
	}
}

static int	parse_options(int argc, char **argv, t_options *options)
{
	int	i;
	int	j;

	ft_bzero(options, sizeof(t_options));
	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		j = 1;
		while (argv[i][j])
		{
			parse_option(argv[i][j], options);
			j++;
		}
		i++;
	}
	return (i - 1);
}

void		parse_arguments(int argc, char **argv,
							t_options *options, t_entries *operands)
{
	int		num_options;
	t_entry	*operand;
	int		i;

	num_options = parse_options(argc, argv, options);
	operands->number = (argc - num_options - 1);
	if (operands->number == 0)
	{
		display_directory(".", options);
		return ;
	}
	operands->entries = malloc_or_quit(operands->number * sizeof(t_entry));
	i = 0;
	while (i < operands->number)
	{
		operand = &operands->entries[i];
		if (!(operand->name = ft_strdup(argv[i++ + num_options + 1])))
			error("Out of memory");
		operand->valid = !lstat(operand->name, &operand->info);
	}
}
