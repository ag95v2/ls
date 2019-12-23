#ifndef OFFSETS_H
#define OFFSETS_H

#include "file_info.h"

typedef struct	s_offsets
{
	int			n_links;
	int			owner;
	int			group;
	int			size;
	int			major;
	int			minor;
}				t_offsets;

void	fill_offsets(t_offsets *offs, t_file_info **info, int len);
int		ndigits(int num);
int		s_len(char *s);

#endif
