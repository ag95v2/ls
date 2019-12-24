/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 19:49:04 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 19:58:38 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FLAGS_H
# define PARSE_FLAGS_H

# include "libft.h"

typedef struct	s_flags
{
	int			recursive;
	int			all;
	int			reverse;
	int			sort_by_time;
	int			long_format;
	int			color;
	int			oneline;
}				t_flags;

int				is_option_arg(char *arg);
void			init_flags(t_flags *flags);
int				read_option_arg(char *arg, t_flags *flags);

#endif
