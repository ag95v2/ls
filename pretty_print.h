/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretty_print.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 19:49:52 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 19:49:55 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRETTY_PRINT_H
# define PRETTY_PRINT_H

# include "file_info.h"
# include "pretty_print.h"
# include <sys/ioctl.h>
# include "libft.h"
# include "colors.h"

typedef struct	s_pretty_print
{
	int			n_cols;
	int			width;
}				t_pretty_print;

int				n_columns_terminal();
int				max_elem(int *arr, int len);
int				choose_ncolumns(int width, int len, int *sizes);
int				my_abs(int x);
void			ft_itoa_stack(int n, char *s);

#endif
