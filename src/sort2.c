/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:43:19 by lde-moul          #+#    #+#             */
/*   Updated: 2018/01/16 17:56:09 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	sorted_by_time(t_entry *entry1, t_entry *entry2)
{
	return (entry1->info.st_mtimespec.tv_sec <
			entry2->info.st_mtimespec.tv_sec);
}

int	sorted_by_time_reverse(t_entry *entry1, t_entry *entry2)
{
	return (entry1->info.st_mtimespec.tv_sec >
			entry2->info.st_mtimespec.tv_sec);
}

int	sorted_by_size(t_entry *entry1, t_entry *entry2)
{
	return (entry1->info.st_size <
			entry2->info.st_size);
}

int	sorted_by_size_reverse(t_entry *entry1, t_entry *entry2)
{
	return (entry1->info.st_size >
			entry2->info.st_size);
}
