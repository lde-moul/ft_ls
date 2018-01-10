/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entries.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:39:17 by lde-moul          #+#    #+#             */
/*   Updated: 2018/01/10 19:19:58 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	get_max_field_sizes(t_entries *entries, int *max_field_sizes)
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

void		display_entries(t_entries *entries, t_options *options)
{
	int			max_field_sizes[6];
	int			i;

	sort_entries(entries, options);
	i = 0;
	while (i < entries->number)
		fill_entry_fields(&entries->entries[i++]);
	get_max_field_sizes(entries, max_field_sizes);
	i = 0;
	while (i < entries->number)
	{
		if (entries->entries[i].name[0] != '.' || options->all)
			display_entry(&entries->entries[i], max_field_sizes);
		i++;
	}
}
