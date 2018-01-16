/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:09:53 by lde-moul          #+#    #+#             */
/*   Updated: 2018/01/16 18:43:07 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static int	sorted_by_name(t_entry *entry1, t_entry *entry2)
{
	return (ft_strcmp(entry1->name, entry2->name) > 0);
}

static int	sorted_by_name_reverse(t_entry *entry1, t_entry *entry2)
{
	return (ft_strcmp(entry1->name, entry2->name) < 0);
}

static void	sort_entries_in_range(t_entry *array, int n,
							int (*sorted)(t_entry*, t_entry*))
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
	while (j < n - 1)
	{
		if (!sorted(&array[j], &pivot))
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
	sort_entries_in_range(array, i, sorted);
	sort_entries_in_range(array + i + 1, n - i - 1, sorted);
}

void		sort_entries(t_entries *entries, t_options *options)
{
	int	(*sorted)(t_entry*, t_entry*);

	if (options->sort_by_size)
		sorted = options->sort_reversed ?
			sorted_by_size_reverse : sorted_by_size;
	else if (options->sort_by_time)
	{
		if (options->ctime)
			sorted = options->sort_reversed ?
				sorted_by_ctime_reverse : sorted_by_ctime;
		else if (options->btime)
			sorted = options->sort_reversed ?
				sorted_by_btime_reverse : sorted_by_btime;
		else
			sorted = options->sort_reversed ?
				sorted_by_mtime_reverse : sorted_by_mtime;
	}
	else
		sorted = options->sort_reversed ?
			sorted_by_name_reverse : sorted_by_name;
	sort_entries_in_range(entries->entries, entries->number, sorted);
}
