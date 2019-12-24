/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 18:04:34 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 18:05:29 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fs_utils.h"

/*
**	Use stat(2)
**	Return 1 if file
**	       2 if directory
**		   0 if invalid path or no read rigts on some dir in path;
**		   set ERRNO
*/

int	is_valid_path(char *path)
{
	struct stat sb;

	if (stat(path, &sb) == -1)
		return (0);
	if ((sb.st_mode & S_IFMT) == S_IFDIR)
		return (2);
	return (1);
}
