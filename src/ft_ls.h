/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:59:48 by lde-moul          #+#    #+#             */
/*   Updated: 2018/01/12 17:49:20 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>

#include <stdio.h>

typedef struct	s_field
{
	char	*text;
	int		size;
}				t_field;

typedef struct	s_entry
{
	struct stat	info;
	char		*name;
	int			valid;
	char		*field_text[6];
	int			field_size[6];
}				t_entry;

typedef struct	s_entries
{
	t_entry	*entries;
	int		number;
	int		allocated;
}				t_entries;

typedef struct	s_options
{
	int	all;
	int	long_format;
	int	recursive;
	int	sort_by_time;
	int	sort_reversed;
	int	not_first;
}				t_options;

void			display_entry(t_entry *entry, int *max_field_sizes);
void			display_entries(t_entries *entries, t_options *options);
void			free_entries(t_entries *entries);
void			fill_entry_fields(t_entry *entry);
void			display_directory(const char *name, t_options *options);
void			sort_entries(t_entries *entries, t_options *options);
void			parse_arguments(int argc, char **argv,
								t_options *options, t_entries *operands);
void			error(char *s);
void			*malloc_or_quit(size_t size);
void			display_spaces(int n);
void			display_entry_link_target(t_entry *entry);
const char		*file_name_only(const char *path);

#endif
