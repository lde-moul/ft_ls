/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:59:48 by lde-moul          #+#    #+#             */
/*   Updated: 2018/04/12 17:55:03 by lde-moul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <sys/types.h>

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
	int	all_normal;
	int	long_format;
	int	recursive;
	int	sort_by_time;
	int	sort_by_size;
	int	sort_reversed;
	int	ctime;
	int	btime;
	int	complete_time;
	int	not_first;
}				t_options;

void			display_entry(t_entry *entry, int *max_field_sizes);
void			display_entries(t_entries *entries, t_options *options);
void			free_entries(t_entries *entries, t_options *options);
void			fill_entry_fields(t_entry *entry, t_options *options);
void			display_directory(const char *name, t_options *options,
									int named);
void			sort_entries(t_entries *entries, t_options *options);
void			parse_arguments(int argc, char **argv,
								t_options *options, t_entries *operands);
void			error(char *s);
void			*malloc_or_quit(size_t size);
void			display_spaces(int n);
void			display_entry_link_target(t_entry *entry);
const char		*file_name_only(const char *path);
int				name_displayable(const char *name, t_options *options);
void			fill_entry_size_or_device_field(t_entry *entry);

int				sorted_by_mtime(t_entry *entry1, t_entry *entry2);
int				sorted_by_mtime_reverse(t_entry *entry1, t_entry *entry2);
int				sorted_by_ctime(t_entry *entry1, t_entry *entry2);
int				sorted_by_ctime_reverse(t_entry *entry1, t_entry *entry2);
int				sorted_by_btime(t_entry *entry1, t_entry *entry2);
int				sorted_by_btime_reverse(t_entry *entry1, t_entry *entry2);
int				sorted_by_size(t_entry *entry1, t_entry *entry2);
int				sorted_by_size_reverse(t_entry *entry1, t_entry *entry2);

#endif
