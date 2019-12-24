#include "libft.h"
#include "offsets.h"
#include "file_info.h"
#include "colors.h"
#include "print_utils.h"

/*
**	Horrible piece of shit
*/

void	print_n_spaces(int n)
{
	if (n <= 0)
		return ;
	while (n--)
		ft_putchar(' ');
}

/*
**	Because we have no %* in printf
**	if (is_int == 0, consider arg as char ** else int *)
*/

static void	offs_crutch(int is_int, void *arg, int offset)
{
	if (is_int)
	{
		print_n_spaces(offset - ndigits_int(*(int *)arg));
		ft_printf("%d", *(int *)arg);
	}
	else
	{
		print_n_spaces(offset - ft_strlen(*(char **)arg));
		ft_printf("%-s", *(char **)arg);
	}
}

char	*start_of_name(char *path)
{
	char	*res;
	char	*current;

	res = path;
	current = res;
	while (*current)
	{
		if (*(current) == '/')
			res = current;
		current++;
	}
	if (res > path)
		res++;
	return (res);
}

int		print_single_file_l(t_flags flags, t_file_info *fi, t_offsets *offs, int only_name)
{
	ft_printf("%c", fi->type);
	ft_printf("%s",fi->perms);
	offs_crutch(1, &(fi->nlinks), offs->n_links);
	offs_crutch(0, &(fi->owner), offs->owner);
	offs_crutch(0, &(fi->group), offs->group);
	if (fi->type == 'b' || fi->type == 'c')
	{
		offs_crutch(1, &(fi->major), offs->major);
		ft_putchar(',');
		offs_crutch(1, &(fi->minor), offs->minor);
	}
	else
		offs_crutch(1, &(fi->size), offs->size);
	ft_putchar(' ');
	ft_printf("%s ",fi->date);
	if (flags.color)
		set_color(fi);
	ft_printf("%s", only_name ? start_of_name(fi->pathname) : fi->pathname);
	if (flags.color)
		reset_color();
	if (fi->type == 'l')
		ft_printf(" -> %s", fi->points_to);
	ft_printf("%c", '\n');
	return (0);
}

void	print_list_files(t_flags flags, t_file_info **fi, int len, int only_name)
{
	int			i;
	t_offsets	offs;

	if (flags.long_format)
		fill_offsets(&offs, fi, len);
	if (!flags.oneline && !flags.long_format)
	{
		pretty_print(flags, fi, len);
		return ;
	}
	i = -1;
	while (++i < len)
	{
		if (!flags.all && fi[i]->pathname[0] == '.')
			continue ;
		if (flags.long_format)
			print_single_file_l(flags, fi[i], &offs, only_name);
		else 
		{
			if (flags.color)
				set_color(fi[i]);
			ft_printf("%s\n", only_name ? start_of_name(fi[i]->pathname) : fi[i]->pathname);
			if (flags.color)
				reset_color();

		}
	}
}
