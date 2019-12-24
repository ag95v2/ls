/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 19:46:27 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 19:47:10 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_UTILS_H
# define PRINT_UTILS_H

void	print_dirname(char *path);
char	*path_append(char *path, char *name);
int		total_blocks(t_stats *stats);
void	print_list_files(t_flags flags, t_file_info **fi,\
		int len, int only_name);
void	print_dir_listing(t_flags flags, char *path, int dir_needed);
char	*start_of_name(char *path);
void	pretty_print(t_flags flags, t_file_info **info, int len);

#endif
