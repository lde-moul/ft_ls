#ifndef FT_LS_H
# define FT_LS_H

#include <sys/stat.h>

#include <stdio.h>

typedef struct	s_entry
{
	struct stat	info;
	char		*name;
	int			valid;
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

void	parse_arguments(int argc, char **argv,
						t_options *options, t_entries *operands);

#endif
