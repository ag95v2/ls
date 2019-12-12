#ifndef FILE_INFO_H
#define FILE_INFO_H

int		print_file_info(char *path);
int		ft_printf(const char *format, ...);

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

#define HALF_OF_THE_YEAR 60 * 60 * 24 * 365 / 2

#endif
