/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparators0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:24:32 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 16:30:21 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comparators.h"
#include "comparators0.h"

int		time_is_greater(void *a, void *b)
{
	if (((t_file_info *)a)->timestamp == ((t_file_info *)b)->timestamp)
		return (0);
	return (((t_file_info *)a)->timestamp < ((t_file_info *)b)->timestamp ?\
			1 : -1);
}

int		time_is_not_grater(void *a, void *b)
{
	return (time_is_greater(b, a));
}

int		is_upper(char a)
{
	return (a >= 'A' && a <= 'Z' ? 1 : 0);
}

char	to_lower(char a)
{
	return (is_upper(a) ? a - 'A' + 'a' : a);
}

int		case_insensitive_strcmp(char *a, char *b)
{
	char	a0;
	char	b0;

	while ((a0 = to_lower(*a)) &&\
			(b0 = to_lower(*b)) && a0 - b0 == 0)
	{
		a++;
		b++;
	}
	return (to_lower(*a) - to_lower(*b));
}
