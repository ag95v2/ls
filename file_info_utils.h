/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:49:08 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 19:52:05 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_INFO_UTILS_H
# define FILE_INFO_UTILS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <stdlib.h>
# include <string.h>
# include "file_info.h"
# include <pwd.h>
# include <grp.h>
# include <unistd.h>
# include <errno.h>
# include <limits.h>

char	file_type_char(struct stat sb);
void	fill_ftype(struct stat sb, t_file_info *fi);
void	fill_prems(struct stat sb, t_file_info *fi);
int		fill_owner_group(struct stat sb, t_file_info *fi);
void	remove_newline(char *s);
void	remove_weekday(char *s);
void	format_time(char *s, int is_old);
int		fill_time(struct stat sb, t_file_info *fi);

#endif
