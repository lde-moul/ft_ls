/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:05:56 by lde-moul          #+#    #+#             */
/*   Updated: 2018/01/16 18:44:47 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	sorted_by_ctime(t_entry *entry1, t_entry *entry2)
{
	return (entry1->info.st_ctimespec.tv_sec <
			entry2->info.st_ctimespec.tv_sec);
}

int	sorted_by_ctime_reverse(t_entry *entry1, t_entry *entry2)
{
	return (entry1->info.st_ctimespec.tv_sec >
			entry2->info.st_ctimespec.tv_sec);
}

int	sorted_by_btime(t_entry *entry1, t_entry *entry2)
{
	return (entry1->info.st_birthtimespec.tv_sec <
			entry2->info.st_birthtimespec.tv_sec);
}

int	sorted_by_btime_reverse(t_entry *entry1, t_entry *entry2)
{
	return (entry1->info.st_birthtimespec.tv_sec >
			entry2->info.st_birthtimespec.tv_sec);
}
