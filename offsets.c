#include "offsets.h"
#include "libft.h"

void	init_offsets(t_offsets *o)
{
	o->n_links = 2;
	o->size = 2;
	o->owner = 2;
	o->group = 2;
	o->major = 0;
	o->minor = 0;
}

int		s_len(char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int		ndigits_int(int num)
{
	int	count;

	count = 1;
	while ((num = num / 10))
		count++;
	return (count);
}

void	fill_offsets(t_offsets *offs, t_file_info **info, int len)
{
	int	i;

	i = -1;
	init_offsets(offs);
	while (++i < len)
	{
		if (ndigits_int(info[i]->nlinks) + 1 > offs->n_links)
			offs->n_links = ndigits_int(info[i]->nlinks) + 1;
		if (ndigits_int(info[i]->size) + 1 > offs->size)
			offs->size = ndigits_int(info[i]->size) + 1;
		if (s_len(info[i]->owner) + 1 > offs->owner)
			offs->owner = ft_strlen(info[i]->owner) + 1;
		if (s_len(info[i]->group) + 1 > offs->group)
			offs->group = ft_strlen(info[i]->group) + 1;
		if (info[i]->type == 'b' || info[i]->type == 'c')
		{
			if (ndigits_int(info[i]->major) + 1 > offs->major)
				offs->major = ndigits_int(info[i]->major) + 1;
			if (ndigits_int(info[i]->minor) + 1 > offs->minor)
				offs->minor = ndigits_int(info[i]->minor) + 1;
		}
	}
	if (offs->minor + offs->major + 1 > offs->size)
		offs->size = offs->minor + offs->major + 1;
	else
		offs->major += offs->size - offs->major - offs->minor - 1;
}
