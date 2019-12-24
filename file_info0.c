/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:48:47 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 17:59:54 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_info_utils.h"

char	file_type_char(struct stat sb)
{
	if ((sb.st_mode & S_IFMT) == S_IFBLK)
		return ('b');
	else if ((sb.st_mode & S_IFMT) == S_IFCHR)
		return ('c');
	else if ((sb.st_mode & S_IFMT) == S_IFDIR)
		return ('d');
	else if ((sb.st_mode & S_IFMT) == S_IFIFO)
		return ('p');
	else if ((sb.st_mode & S_IFMT) == S_IFLNK)
		return ('l');
	else if ((sb.st_mode & S_IFMT) == S_IFSOCK)
		return ('s');
	else
		return ('-');
}

void	fill_ftype(struct stat sb, t_file_info *fi)
{
	fi->type = file_type_char(sb);
}

void	fill_prems(struct stat sb, t_file_info *fi)
{
	fi->perms[0] = sb.st_mode & S_IRUSR ? 'r' : '-';
	fi->perms[1] = sb.st_mode & S_IWUSR ? 'w' : '-';
	fi->perms[2] = sb.st_mode & S_IXUSR ? 'x' : '-';
	fi->perms[3] = sb.st_mode & S_IRGRP ? 'r' : '-';
	fi->perms[4] = sb.st_mode & S_IWGRP ? 'w' : '-';
	fi->perms[5] = sb.st_mode & S_IXGRP ? 'x' : '-';
	fi->perms[6] = sb.st_mode & S_IROTH ? 'r' : '-';
	fi->perms[7] = sb.st_mode & S_IWOTH ? 'w' : '-';
	fi->perms[8] = sb.st_mode & S_IXOTH ? 'x' : '-';
	fi->perms[9] = 0;
}

int		fill_owner_group(struct stat sb, t_file_info *fi)
{
	static struct passwd	*pwuser;
	static struct group		*grpnam;

	if (!(pwuser = getpwuid(sb.st_uid)))
		return (1);
	if (!(grpnam = getgrgid(sb.st_gid)))
		return (1);
	fi->owner = ft_strdup(pwuser->pw_name);
	if (!fi->owner)
	{
		ft_fprintf(2, "%s\n", strerror(errno));
		return (1);
	}
	fi->group = ft_strdup(grpnam->gr_name);
	if (!fi->group)
	{
		free(fi->owner);
		ft_fprintf(2, "%s\n", strerror(errno));
		return (1);
	}
	return (0);
}

void	remove_newline(char *s)
{
	while (*s)
	{
		if (*s == '\n')
		{
			*s = 0;
			break ;
		}
		s++;
	}
}
