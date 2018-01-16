/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:03:18 by lde-moul          #+#    #+#             */
/*   Updated: 2018/01/16 17:25:38 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	error(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}

void	*malloc_or_quit(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		error("Out of memory");
	return (p);
}
