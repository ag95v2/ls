/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:05:40 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 18:08:29 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "qsort.h"
#include "libft.h"
#include "comparators.h"

void	sort_fileinfo(t_flags flags, int n, t_file_info **info)
{
	qsort_void_ptr((void **)info, n, choose_comparator(flags));
}
