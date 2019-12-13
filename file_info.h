#ifndef FILE_INFO_H
#define FILE_INFO_H

#include "libft/includes/libft.h"

#define FLAG_L		(1ul << 0)
#define FLAG_REV	(1ul << 1)
#define FLAG_T		(1ul << 2)
#define FLAG_A		(1ul << 3)
#define FLAG_REC	(1ul << 4)

#define HALF_OF_THE_YEAR 60 * 60 * 24 * 365 / 2

typedef t_uint64	t_flags;


typedef struct			s_file_info
{
	char				type;
	char				perms[10];
	int					nlinks;
	char				*owner;
	char				*group;
	unsigned long long	size;
	char				*date;
	char				*name;
	char				*pathname;
	int					major;
	int					minor;
}						t_file_info;

typedef struct			s_dir
{
	t_file_info			*files;
}						t_dir;

t_file_info	get_file_info(const char *filename, t_flags flags);
int		ft_printf(const char *format, ...);
void ft_ls(const char **argv);
t_list	*get_files(const char **argv);
t_uint64	get_flags(const char **argv);


#endif
