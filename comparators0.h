/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparators0.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:24:14 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 16:24:28 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARATORS_0_H
#define COMPARATORS_0_H

#include "comparators.h"

int		time_is_greater(void *a, void *b);
int		time_is_not_grater(void *a, void *b);
int		is_upper(char a);
char	to_lower(char a);
int		case_insensitive_strcmp(char *a, char *b);

#endif
