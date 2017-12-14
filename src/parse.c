/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:58:56 by lde-moul          #+#    #+#             */
/*   Updated: 2017/12/14 16:56:30 by lde-moul         ###   ########.fr       */
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
	// else
        // !!!
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
	operands->entries = malloc(operands->number * sizeof(t_entry)); // !!! check
	i = 0;
	while (i < operands->number)
	{
		operand = &operands->entries[i];
		operand->name = argv[i + num_options + 1];
		operand->valid = stat(operand->name, &operand->info);
		operand->valid = !stat(operand->name, &operand->info);
		i++;
	}
}