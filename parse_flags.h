#ifndef ARG_PARSE_H
#define ARG_PARSE_H

#include "libft.h"

typedef struct	s_flags
{
	int			recursive;
	int			all;
	int			reverse;
	int			sort_by_time;
	int			long_format;
	int			color;
	int			oneline;
}				t_flags;

int		is_option_arg(char *arg);
void	init_flags(t_flags *flags);
int		read_option_arg(char *arg, t_flags *flags);

#endif
