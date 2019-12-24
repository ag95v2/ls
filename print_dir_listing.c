#include <dirent.h>
#include "file_info.h"
#include <errno.h>
#include <string.h>
#include "libft.h"
#include "filesort.h"
#include "print_utils.h"

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
		*new++ =*name++;
	*new = 0;
	return (start);
}

static t_stats	*cleanup(t_stats *res, char *path)
{
	rmstats(res, &del);
	free(path);
	return (0);
}

t_stats			*parse_dir(t_flags flags, DIR *d, char *path)
{
	t_stats			*res;
	char			*total_path;
    struct dirent	*dir;

	if (!(res = (t_stats *)ft_memalloc(sizeof(t_stats))))
		return (0);
	while ((dir = readdir(d)))
	{
		if (!flags.all && dir->d_name[0] == '.')
			continue ;
		if (!(total_path = ft_strcmp(path, ".") ?\
				path_append(path, dir->d_name) : dir->d_name) ||\
				push(res, total_path) == critical)
				return (cleanup(res, total_path));
		if (ft_strcmp(path, "."))
			free(total_path);
	}
	closedir(d);
	return (res);
}

void	print_subdirs(t_flags flags, t_stats *stats, char *path)
{
	t_list	*current;
	char	*new_path;
	char	*p;

	current = stats->dirs;
	while (current)
	{
		p = ((t_path_stat *)current->content)->path;
		if (!ft_strcmp(start_of_name(p), "..") || !ft_strcmp(start_of_name(p), "."))
		{
			current = current->next;
			continue ;
		}
		if (!(new_path = path_append(path, ((t_path_stat *)current->content)->path)))
		{
			ft_printf("%s\n", "Memory error"); //to stdout
			return ;
		}
		print_dir_listing(flags, p, 1);
		free(new_path);
		current = current->next;
	}
}

t_file_info **get_dir_fileinfo(t_stats *stats, int *len)
{
	t_file_info	**res;
	int			i;

	i = 0;
	*len = stats->n_files + stats->n_dirs;
	if (!(res = (t_file_info **)ft_memalloc(sizeof(t_file_info *) * *len)))
		return (0);
	while (stats->n_files)
		res[i++] = pop_file(stats);
	while (stats->n_dirs)
		res[i++] = pop_dir(stats);
	return (res);
}

int	total_blocks(t_stats *stats)
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

void	print_dir_listing(t_flags flags, char *path, int dname_needed)
{
    DIR				*d;
	t_stats			*stats;
	t_file_info		**info;
	int				len;

    if (!(d = opendir(path)))
	{
		ft_printf("ls: cannot open directory '%s': %s\n", path, strerror(errno)); //To Stderr
		return ;
	}
	if (!(stats = parse_dir(flags, d, path)))
		return ;
	if (flags.recursive)
		print_subdirs(flags, stats, path);
	if (flags.recursive || dname_needed)
		print_dirname(path);
	if (flags.long_format)
		ft_printf("total %d\n", total_blocks(stats));
	if (!(info = get_dir_fileinfo(stats, &len)))
		return ;
	sort_fileinfo(flags, len, info);
	print_list_files(flags, info, len, 1);
	rmstats(stats, &del);
	rm_arr_fileinfo(info, len);
}
