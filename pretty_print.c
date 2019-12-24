/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretty_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:48:47 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 21:31:35 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_info.h"
#include "pretty_print.h"
#include <sys/ioctl.h>
#include "libft.h"
#include "colors.h"

static void	print(t_flags flags, int len, t_file_info **info, t_pretty_print p)
{
	int			i;
	char		*fmt;
	char		*tmp;
	static char	nbr[12];

	ft_itoa_stack(p.width / p.n_cols, nbr);
	tmp = ft_strjoin("%-", nbr);
	fmt = ft_strjoin(tmp, "s");
	free(tmp);
	i = 0;
	while (i < len)
	{
		if (flags.color)
			set_color(info[i]);
		ft_printf(fmt, start_of_name(info[i]->pathname));
		if (flags.color)
			reset_color();
		if (!((i + 1) % p.n_cols))
			ft_printf("%c", '\n');
		i++;
	}
	if ((i + 1 % p.n_cols))
		ft_printf("%c", '\n');
	free(fmt);
}

void		pretty_print(t_flags flags, t_file_info **info, int len)
{
	int				*sizes;
	int				i;
	t_pretty_print	p;

	p.width = n_columns_terminal();
	sizes = malloc(sizeof(int) * len);
	if (!sizes)
		return ;
	i = -1;
	while (++i < len)
		sizes[i] = ft_strlen(start_of_name(info[i]->pathname));
	p.n_cols = choose_ncolumns(p.width, len, sizes);
	print(flags, len, info, p);
	free(sizes);
}
