#ifndef FILE_INFO_H
#define FILE_INFO_H

#include <sys/types.h>
#include <sys/stat.h>
#include "errors.h"
#include "libft.h"
#include "parse_flags.h"

/*
**	For mtime
*/
#if defined(__APPLE__) || defined(__NetBSD__) 
#define st_atim st_atimespec
#define st_ctim st_ctimespec
#define st_mtim st_mtimespec
#endif

typedef struct			s_file_info
{
	char				type;
	char				perms[10];
	int					nlinks;
	char				*owner;
	char				*group;
	unsigned long long	size;
	char				*date;
	time_t				timestamp;
	char				*pathname;
	char				*points_to;
	int					major;
	int					minor;
}						t_file_info;

typedef struct			s_stats
{
	int					n_invalid;
	int					n_dirs;
	int					n_files;
	t_list				*dirs;
	t_list				*files;
}						t_stats;

typedef struct			s_path_stat
{
	struct stat			*sb;
	char				*path;
}						t_path_stat;

t_stats					*parse_args(t_flags *flags, int argc, char **argv);
t_file_info				*get_file_info(t_path_stat *ps);

t_file_info				**get_args_fileinfo(t_stats *stats);
void					clear_fi_array(t_file_info **arr, int len);
void					init_stats(t_stats *stats);
t_error					push(t_stats *stats, char *path);
void					del(void *content, size_t content_size);
void					rmstats(t_stats *stats, void (*del)(void *, size_t));

void					rm_arr_fileinfo(t_file_info **fi, int len);
char					*start_of_name(char *path);

/*
**	Extract first file / dir
*/

t_file_info				*pop_file(t_stats *stats);
t_file_info				*pop_dir(t_stats *stats);

#define HALF_OF_THE_YEAR 60 * 60 * 24 * 365 / 2

#endif
