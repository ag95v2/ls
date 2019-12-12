/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:04:46 by user              #+#    #+#             */
/*   Updated: 2019/12/12 13:13:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dirent.h"
#include "errno.h"
#include "stdio.h"
#include "file_info.h"

#include "libft/includes/libft.h"

static void		get_flags_from_str(const char *str, t_uint64 *flags)
{
	while (*(++str))
	{
		if (*str == 'R')
			*flags |= RU;
		else if (*str == 'r')
			*flags |= RL;
		else if (*str == 'a')
			*flags |= A;
		else if (*str == 'l')
			*flags |= L;
		else if (*str == 't')
			*flags |= T;
	}
}

t_uint64	get_flags(const char **argv)
{
	t_uint64	flags;

	flags = 0;
	while (*(++argv))
	{
		if (**argv == '-' && (*argv)[1] == '-')
			break;
		else if (**argv == '-')
			get_flags_from_str(*argv, &flags);
	}
	return (flags);
}

void	get_files_and_dirs(const char **argv, t_list **files, t_list **dirs)
{
	DIR		*dir;

	*files = NULL;
	*dirs = NULL;
	while (*(++argv))
	{
		dir = opendir(*argv);
		if (!dir)
		{
			if (errno == EACCES)
				printf("ft_ls: cannot open directory '%s': Permission denied\n", *argv);
			else if (errno == ENOENT)
				printf("ft_ls: cannot access '%s': No such file or directory\n", *argv);
			else if (errno == ENOTDIR)
				ft_lstappend(files, ft_lstnew(*argv, ft_strlen(*argv) + 1));
		}
		else
			ft_lstappend(dirs, ft_lstnew(*argv, ft_strlen(*argv) + 1));
		closedir(dir);
	}
}
