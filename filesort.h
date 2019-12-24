/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesort.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 19:52:20 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 19:52:36 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILESORT_H
# define FILESORT_H

# include "parse_flags.h"
# include "file_info.h"

typedef int		(*t_cmpf)(void *a, void *b);
void			sort_fileinfo(t_flags flags, int n, t_file_info **info);

#endif
