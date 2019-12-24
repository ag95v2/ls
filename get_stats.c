/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:23:45 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 16:19:12 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "errors.h"
#include "file_info.h"
#include <errno.h>

t_error				add_stat(t_stats *stats, t_path_stat *ps)
{
	t_list		*new;

	if (!(new = ft_lstnew(ps, sizeof(t_path_stat *))))
	{
		ft_printf("%s\n", "Memory error");
		return (critical);
	}
	if ((ps->sb->st_mode & S_IFMT) == S_IFDIR)
	{
		ft_lstadd(&(stats->dirs), new);
		stats->n_dirs += 1;
	}
	else
	{
		ft_lstadd(&(stats->files), new);
		stats->n_files += 1;
	}
	return (ok);
}

void				free3(struct stat *a, char *b, t_path_stat *c)
{
	free(a);
	free(b);
	free(c);
}

t_error				push(t_stats *stats, char *path)
{
	struct stat	*sb;
	char		*d_pth;
	t_path_stat	*ps;

	sb = NULL;
	d_pth = NULL;
	ps = NULL;
	if (!(sb = (struct stat *)ft_memalloc(sizeof(struct stat))) ||\
		!(d_pth = ft_strdup(path)) ||\
		!(ps = (t_path_stat *)malloc(sizeof(t_path_stat))))
	{
		free3(sb, d_pth, ps);
		ft_fprintf(2, "%s\n", "Memory error");
		return (critical);
	}
	if (lstat(path, sb) == -1)
	{
		ft_fprintf(2, "ls: cannot access '%s': %s\n", strerror(errno), d_pth);
		stats->n_invalid++;
		free3(sb, d_pth, ps);
		return (not_critical);
	}
	ps->sb = sb;
	ps->path = d_pth;
	return (add_stat(stats, ps));
}

t_file_info			*pop_file(t_stats *stats)
{
	t_path_stat	*file;
	t_file_info	*res;

	if (!stats->n_files)
		return (0);
	file = (t_path_stat *)stats->files->content;
	res = get_file_info(file);
	ft_lstdelone(&(stats->files), del);
	stats->n_files -= 1;
	return (res);
}

t_file_info			*pop_dir(t_stats *stats)
{
	t_path_stat	*dir;
	t_file_info	*res;

	if (!stats->n_dirs)
		return (0);
	dir = (t_path_stat *)stats->dirs->content;
	res = get_file_info(dir);
	ft_lstdelone(&(stats->dirs), &del);
	stats->n_dirs -= 1;
	return (res);
}
