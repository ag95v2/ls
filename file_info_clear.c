/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:04:00 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 18:04:07 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_info.h"

void	clear_fileinfo(t_file_info *f)
{
	free(f->owner);
	free(f->group);
	free(f->date);
	free(f->pathname);
	free(f);
}

void	clear_fi_array(t_file_info **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
		clear_fileinfo(arr[i]);
}
