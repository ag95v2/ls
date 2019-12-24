/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dl_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:20:27 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 16:24:47 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_info.h"

int		total_blocks(t_stats *stats)
{
	int		i;
	t_list	*current;

	i = 0;
	current = stats->files;
	while (current)
	{
		i += ((t_path_stat *)current->content)->sb->st_blocks;
		current = current->next;
	}
	current = stats->dirs;
	while (current)
	{
		i += ((t_path_stat *)current->content)->sb->st_blocks;
		current = current->next;
	}
	return (i);
}

/*
**	Leading newline is printed only once
*/

void	print_dirname(char *path)
{
	static int	leading_newline;

	if (leading_newline)
		ft_printf("%c", '\n');
	ft_printf("%s:\n", path);
	leading_newline = 1;
}

/*
**	Result is to be freed
*/

char	*path_append(char *path, char *name)
{
	char	*new;
	char	*start;

	if (!(new = malloc(ft_strlen(path) + ft_strlen(name) + 2)))
		return (0);
	start = new;
	while (*path)
		*new++ = *path++;
	if (*(new - 1) != '/')
		*new++ = '/';
	while (*name)
		*new++ = *name++;
	*new = 0;
	return (start);
}
