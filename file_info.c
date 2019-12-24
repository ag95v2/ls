/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:52:45 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 18:02:52 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>

#include <string.h>

#include "file_info.h"
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include "file_info_utils.h"

/*
**	return pathname of file
*/

char			*follow_symlink(struct stat *sb, char *path)
{
	char	*name;
	ssize_t	size;
	ssize_t	nbytes;

	size = sb->st_size ? sb->st_size + 1 : PATH_MAX;
	if (!(name = malloc(size)))
		return (0);
	if ((nbytes = readlink(path, name, size)) == -1)
	{
		ft_fprintf(2, "ls: cannot access '%s': %s\n", strerror(errno), path);
		return (0);
	}
	name[nbytes] = 0;
	return (name);
}

int				fill_file_info(struct stat sb, char *path, t_file_info *fi)
{
	fill_ftype(sb, fi);
	if (fi->type == 'l')
		fi->points_to = follow_symlink(&sb, path);
	fill_prems(sb, fi);
	fi->nlinks = sb.st_nlink;
	fi->size = sb.st_size;
	fill_owner_group(sb, fi);
	fill_time(sb, fi);
	if (!(fi->pathname = ft_strdup(path)))
		return (1);
	if (fi->type == 'b' || fi->type == 'c')
	{
		fi->major = major(sb.st_rdev);
		fi->minor = minor(sb.st_rdev);
	}
	return (0);
}

t_file_info		*get_file_info(t_path_stat *ps)
{
	t_file_info	*info;

	info = (t_file_info *)ft_memalloc(sizeof(t_file_info));
	if (!info)
		return (0);
	fill_file_info(*(ps->sb), ps->path, info);
	return (info);
}
