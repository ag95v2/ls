#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>

// Later use libft instead
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
//

#include "file_info.h"
#include <pwd.h>
#include <grp.h>

/* Stub for ft_printf */
int	ft_printf(const char *format, ...)
{
	int ret;
	va_list vl;

	va_start(vl, format);
	ret = vprintf(format, vl);
	va_end(vl);
	return (ret);
}



char	file_type_char(struct stat sb)
{
	if ((sb.st_mode & S_IFMT) == S_IFBLK)
		return('b');
	else if ((sb.st_mode & S_IFMT) == S_IFCHR)
		return('c');
	else if ((sb.st_mode & S_IFMT) == S_IFDIR)
		return('d');
	else if ((sb.st_mode & S_IFMT) == S_IFIFO)
		return('p');
	else if ((sb.st_mode & S_IFMT) == S_IFLNK)
		return('l');
	else if ((sb.st_mode & S_IFMT) == S_IFSOCK)
		return('s');
	else
		return('-');
}

void	fill_ftype(struct stat sb, t_file_info *fi)
{
	fi->type = file_type_char(sb);
}

void	fill_prems(struct stat sb, t_file_info *fi)
{
	fi->perms[0] = sb.st_mode & S_IRUSR ? 'r' : '-';
	fi->perms[1] = sb.st_mode & S_IWUSR ? 'w' : '-';
	fi->perms[2] = sb.st_mode & S_IXUSR ? 'x' : '-';
	fi->perms[3] = sb.st_mode & S_IRGRP ? 'r' : '-';
	fi->perms[4] = sb.st_mode & S_IWGRP ? 'w' : '-';
	fi->perms[5] = sb.st_mode & S_IXGRP ? 'x' : '-';
	fi->perms[6] = sb.st_mode & S_IROTH ? 'r' : '-';
	fi->perms[7] = sb.st_mode & S_IWOTH ? 'w' : '-';
	fi->perms[8] = sb.st_mode & S_IXOTH ? 'x' : '-';
	fi->perms[9] = 0;
}

int		fill_owner_group(struct stat sb, t_file_info *fi)
{
	static struct passwd	*pwuser;
	static struct group		*grpnam;

	if (!(pwuser = getpwuid(sb.st_uid)))
	{
		perror("getpwuid()");
		return (1);
	}

	if (!(grpnam = getgrgid(sb.st_gid)))
	{
		perror("getgrgid()");
		return (1);
	}
	fi->owner = pwuser->pw_name;
	fi->group = grpnam->gr_name;
	return (0);
}

void	remove_newline(char *s)
{
	while (*s)
	{
		if (*s == '\n')
		{
			*s = 0;
			break;
		}
		s++;
	}
}

void	remove_weekday(char *s)
{
	char	*current;

	current = s + 4;
	while (*current)
		*s++ = *current++;
	*s = 0;
}

/*
**	Remove weekday;
**	Remove '\n';
**	Remove seconds;
**	If is_old, put year instead of hr and min
*/

void	format_time(char *s, int is_old)
{
	int		i;

	remove_newline(s);
	remove_weekday(s);
	i = 0;
	while (i != 2)
	{
		if (*s == ':')
			i++;
		s++;
	}
	*(s - 1) = 0;
	if (!is_old)
		return ;
	ft_strcpy(s - 6,s + 3);
}

int		fill_time(struct stat sb, t_file_info *fi)
{
	char	*s;
	time_t	current_time;
	int		old_file;

	if ((current_time = time(0)) == -1)
		return (1);
	if (current_time - sb.st_mtim.tv_sec > HALF_OF_THE_YEAR)
		old_file = 1;
	s = ctime(&sb.st_mtim.tv_sec);
	if (!(fi->date = ft_strdup(s)))
		return (1);
	format_time(fi->date, old_file);
	return (0);
}

/*
**	Print long listing like "ls -l"
*/

int		fill_file_info(char *path, t_file_info *fi)
{
	struct stat sb;

	if (stat(path, &sb) == -1)
	{
		perror("stat");
		return (1);
	}
	fill_ftype(sb, fi);
	fill_prems(sb, fi);
	fi->nlinks = sb.st_nlink;
	fi->size = sb.st_size;
	fill_owner_group(sb, fi);
	fill_time(sb, fi);
	if (!(fi->pathname = ft_strdup(path)))
		return (1);
	if (fi->type == 'b' || fi->type == 'c')
	{
		fi->major = major(sb.st_rdev);
		fi->minor = minor(sb.st_rdev);
	}
	return (0);
}

int		print_file_info(char *path)
{
	t_file_info	fi;

	if (fill_file_info(path, &fi) == 1)
		return (1);
	ft_printf("%c", fi.type);
	ft_printf("%s ",fi.perms);
	ft_printf("%d ",fi.nlinks);
	ft_printf("%s ",fi.owner);
	ft_printf("%s ",fi.group);
	if (fi.type == 'b' || fi.type == 'c')
		ft_printf("%d, %d ", fi.major, fi.minor);
	else
		ft_printf("%d ",fi.size);
	ft_printf("%s ",fi.date);
	ft_printf("%s", fi.pathname);
	ft_printf("%c", '\n');
	free(fi.pathname);
	free(fi.date);
	return (0);
}
