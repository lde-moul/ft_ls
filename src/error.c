/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:03:18 by lde-moul          #+#    #+#             */
/*   Updated: 2018/01/10 16:39:43 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	error(char *s)
{
	ft_putendl(s);
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
