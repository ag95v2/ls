#include "sys/types.h"
#include "stdio.h"
#include "dirent.h"
#include "errno.h"
#include "stddef.h"
#include "libft/includes/libft.h"

#include "file_info.h"

void sort_files(t_list **files, t_flags flags)
{
	if (files && flags)
		return ;
	return ;
}

void print_all(t_list *files, t_flags flags)
{
	if (flags && !flags)
		return ;
	while (files)
	{
		// printf("%s\t", ((t_file_info*)files->content)->name);
		files = files->next;
	}
}

void print_files(const t_list *files, t_flags flags)
{
	if (flags && !flags)
		return ;
	while (files)
	{
		// if (((t_file_info*)files->content)->type != 'd')
		// 	printf("%s\t", ((t_file_info*)files->content)->name);
		files = files->next;
	}
}

void print_dirs(const t_list *files, t_flags flags, int rec_depth)
{
	DIR *dir;
	struct dirent *cur_file;
	t_file_info		info;
	char *str;
	t_list *dir_data;

	dir_data = NULL;
	while (files)
	{
		if (((t_file_info*)files->content)->type == 'd')
		{
			printf("%s\n", ((t_file_info*)files->content)->pathname);
			if (!ft_strequ(".", ((t_file_info*)files->content)->name) && !ft_strequ("..", ((t_file_info*)files->content)->name))
			{
				printf("%s:\n", ((t_file_info*)files->content)->pathname);
				dir = opendir(((t_file_info*)files->content)->pathname);
				while ((cur_file = readdir(dir)))
				{
					str = ft_strjoin(((t_file_info*)files->content)->pathname, "/");
					str = ft_strjoin(str, cur_file->d_name);
					info = get_file_info(str, flags);
					info.name = ft_strdup(cur_file->d_name);
					ft_lstadd(&dir_data, ft_lstnew(&info, sizeof(t_file_info)));
				}
				closedir(dir);
				sort_files(&dir_data, flags);
				print_all(dir_data, flags);
				printf("\n\n");
				if (flags & FLAG_REC)
					print_dirs(dir_data, flags, rec_depth + 1);
			}
		}
		files = files->next;
	}
}

void ft_ls(const char **argv)
{
	t_flags	flags;
	t_list	*files;

	flags = get_flags(argv);
	files = get_files(argv);
	sort_files(&files, flags);
	print_files(files, flags);
	print_dirs(files, flags, 0);
	ft_lstpurge(&files);
}
