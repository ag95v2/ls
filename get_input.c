/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 13:04:46 by user              #+#    #+#             */
/*   Updated: 2019/12/13 13:25:43 by dbendu           ###   ########.fr       */
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
			*flags |= FLAG_REC;
		else if (*str == 'r')
			*flags |= FLAG_REV;
		else if (*str == 'a')
			*flags |= FLAG_A;
		else if (*str == 'l')
			*flags |= FLAG_L;
		else if (*str == 't')
			*flags |= FLAG_T;
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

t_list	*get_files(const char **argv)
{
	t_list *files;
	t_file_info	info;

	files = NULL;
	while (*(++argv))
	{
		if (**argv != '-')
		{
			info = get_file_info(*argv, 0);
			ft_lstadd(&files, ft_lstnew(&info, sizeof(t_file_info)));
		}
	}
	return (files);
}
