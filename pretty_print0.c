/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretty_print0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:51:04 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 21:38:14 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pretty_print.h"

int					n_columns_terminal(void)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}

int					max_elem(int *arr, int len)
{
	int	max;
	int	i;

	if (len == 0)
		return (0);
	i = 0;
	max = arr[i];
	while (i < len)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

int					choose_ncolumns(int width, int len, int *sizes)
{
	int	max_len;
	int	n;

	max_len = max_elem(sizes, len);
	n = width / (max_len + 3);
	return (n ? n : n + 1);
}

int					my_abs(int x)
{
	return (x > 0 ? x : x * -1);
}

void				ft_itoa_stack(int n, char *s)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		s[0] = '-';
		i++;
	}
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		s[i++] = my_abs(n % 10) + '0';
		n = n / 10;
	}
	ft_strrev((s[0] == '-') ? s + 1 : s);
}
