/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:09:53 by lde-moul          #+#    #+#             */
/*   Updated: 2017/12/14 17:58:21 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void	sort_entries_in_range(t_entry *array, int n)
{
	t_entry	pivot;
	int		i;
	int		j;
	t_entry	tmp;

	if (n < 2)
		return ;
	pivot = array[n - 1];
	i = 0;
	j = 0;
	while (j < n)
	{
		if (ft_strcmp(array[j].name, pivot.name) < 0)
		{
			tmp = array[i];
			array[i++] = array[j];
			array[j] = tmp;
		}
		j++;
	}
	tmp = array[i];
	array[i] = array[n - 1];
	array[n - 1] = tmp;
	sort_entries_in_range(array, i);
	sort_entries_in_range(array + i + 1, n - i - 1);
}

void		sort_entries(t_entries *entries)
{
	sort_entries_in_range(entries->entries, entries->number);
}
