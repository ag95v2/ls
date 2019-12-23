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
	return(ok);
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
	char		*duplicate_path;
	t_path_stat	*ps;

	sb = NULL;
	duplicate_path = NULL;
	ps = NULL;
	if (!(sb = (struct stat *)ft_memalloc(sizeof(struct stat))) ||\
		!(duplicate_path = ft_strdup(path)) ||\
		!(ps = (t_path_stat *)malloc(sizeof(t_path_stat))))
	{
		free3(sb, duplicate_path, ps);
		ft_printf("%s\n", "Memory error");// To stderr not stdout!
		return (critical);
	}
	if (lstat(path, sb) == -1)
	{
		ft_printf("ls: cannot access '%s': %s\n", strerror(errno), duplicate_path); // To stderr not stdout!
		stats->n_invalid++;
		free3(sb, duplicate_path, ps);
		return (not_critical);
	}
	ps->sb = sb;
	ps->path = duplicate_path;
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
