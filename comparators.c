/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparators.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:24:42 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 18:10:34 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "comparators.h"
#include "comparators0.h"

int		name_is_greater(void *a, void *b)
{
	char	*n1;
	char	*n2;

	n1 = ((t_file_info *)a)->pathname[0] == '.' ? \
			((t_file_info *)a)->pathname + 1 : ((t_file_info *)a)->pathname;
	n2 = ((t_file_info *)b)->pathname[0] == '.' ?\
			((t_file_info *)b)->pathname + 1 : ((t_file_info *)b)->pathname;
	return (case_insensitive_strcmp(n1, n2));
}

int		inv_name_is_greater(void *a, void *b)
{
	return (name_is_greater(a, b) * -1);
}

t_cmpf	choose_comparator(t_flags flags)
{
	if (flags.sort_by_time)
		return (flags.reverse ? &time_is_not_grater : &time_is_greater);
	return (flags.reverse ? &inv_name_is_greater : &name_is_greater);
}
