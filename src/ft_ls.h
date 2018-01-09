#ifndef FT_LS_H
# define FT_LS_H

#include <sys/stat.h>

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
}				t_entries;

typedef struct	s_options
{
	int	all;
	int	long_format;
	int	recursive;
}				t_options;

void			display_entry(t_entry *entry, int *max_field_sizes);
void			get_max_field_sizes(t_entries *entries, int *max_field_sizes);
void			fill_entry_fields(t_entry *entry);
void			display_directory(t_entry *entry);
void			sort_entries(t_entries *entries);
void			parse_arguments(int argc, char **argv,
								t_options *options, t_entries *operands);
void			*malloc_or_quit(size_t size);

#endif
