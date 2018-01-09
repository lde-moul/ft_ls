/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:03:18 by lde-moul          #+#    #+#             */
/*   Updated: 2018/01/09 13:58:21 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*malloc_or_quit(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
	{
		ft_putendl("Out of memory\n");
		exit(1);
	}
	return (p);
}
