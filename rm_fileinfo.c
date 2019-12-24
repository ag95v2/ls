/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_fileinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:15:06 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 16:15:10 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_info.h"

void	rm_fileinfo(t_file_info **fi)
{
	free((*fi)->pathname);
	free((*fi)->owner);
	free((*fi)->group);
	free((*fi)->points_to);
	free((*fi)->date);
	free(*fi);
}

void	rm_arr_fileinfo(t_file_info **fi, int len)
{
	while (len--)
		rm_fileinfo(fi + len);
	free(fi);
}
