#include "sys/types.h"
#include "stdio.h"
#include "dirent.h"
#include "errno.h"
#include "stddef.h"
#include "libft/includes/libft.h"

#include "file_info.h"

void sort_files(t_list **files)
{
	if (files || !files)
		return ;
}

void sort_dirs(t_list **dirs)
{
	if (dirs|| !dirs)
		return ;
}

void print_files(const t_list *files)
{
	while (files)
	{
		printf("%s\t", (char*)files->content);
		files = files->next;
	}
	printf("\n");
}

t_dir *get_dir_content(const DIR *dir)
{
	t_dir *dir_data;
	struct dirent *cur_file;

	dir_data = NULL;
	while ((cur_file = readdir(dir)))
	{

	}
}

void print_dirs(const t_list *dirs)
{
	DIR *dir;

	while (dirs)
	{
		dir = opendir(dirs->content);
		get_dir_content()
	}
}

void ft_ls(const char **argv)
{
	t_ls_data	data;

	data.flags = get_flags(argv);
	get_files_and_dirs(argv, &data.files, &data.dirs);

	sort_files(&data.files);
	print_files(data.files);
	if (data.dirs)
		printf("\n");
	print_dirs(data.dirs);


	// printf("Files:\n");
	// while (data.files)
	// {
	// 	printf("\t%s\n", (char*)data.files->content);
	// 	data.files = data.files->next;
	// }
	// printf("\nDirs:\n");
	// while (data.dirs)
	// {
	// 	printf("\t%s\n", (char*)data.dirs->content);
	// 	data.dirs = data.dirs->next;
	// }
}
