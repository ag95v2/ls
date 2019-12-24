/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offsets.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 19:51:31 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 19:51:40 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFSETS_H
# define OFFSETS_H

# include "file_info.h"

typedef struct	s_offsets
{
	int			n_links;
	int			owner;
	int			group;
	int			size;
	int			major;
	int			minor;
}				t_offsets;

void			fill_offsets(t_offsets *offs, t_file_info **info, int len);
int				ndigits_int(int num);
int				s_len(char *s);

#endif
