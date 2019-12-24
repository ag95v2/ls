/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:49:03 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 20:15:03 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_info_utils.h"

void			remove_weekday(char *s)
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

void			format_time(char *s, int is_old)
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
	ft_strcpy(s - 6, s + 3);
}

static time_t	max(time_t a, time_t b)
{
	return (a > b ? a : b);
}

static time_t	min(time_t a, time_t b)
{
	return (a < b ? a : b);
}

int				fill_time(struct stat sb, t_file_info *fi)
{
	char	*s;
	time_t	current_time;
	int		old_file;

	old_file = 0;
	if ((current_time = time(0)) == -1)
		return (1);
	if (max(current_time, sb.ST_MTIM.tv_sec) -\
		min(current_time, sb.ST_MTIM.tv_sec) > HALF_OF_THE_YEAR)
		old_file = 1;
	s = ctime(&sb.ST_MTIM.tv_sec);
	fi->timestamp = sb.ST_MTIM.tv_sec;
	if (!(fi->date = ft_strdup(s)))
		return (1);
	format_time(fi->date, old_file);
	return (0);
}
