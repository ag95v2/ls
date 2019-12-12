#ifndef FILE_INFO_H
#define FILE_INFO_H

#include "libft/includes/libft.h"

#define L	(1ul << 0)
#define RU	(1ul << 1)
#define T	(1ul << 2)
#define A	(1ul << 3)
#define RL	(1ul << 4)

int		print_file_info(char *path);
int		ft_printf(const char *format, ...);
void ft_ls(const char **argv);
void	get_files_and_dirs(const char **argv, t_list **files, t_list **dirs);
t_uint64	get_flags(const char **argv);

typedef struct			s_dir
{
	t_file_info		*files;
}						t_dir;


typedef struct			s_file_info
{
	char				type;
	char				perms[10];
	int					nlinks;
	char				*owner;
	char				*group;
	unsigned long long	size;
	char				*date;
	char				*pathname;
}						t_file_info;



typedef struct			s_ls_data
{
	t_uint64			flags;
	t_list				*files;
	t_list				*dirs;
}						t_ls_data;

#define HALF_OF_THE_YEAR 60 * 60 * 24 * 365 / 2

#endif
