/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 19:47:20 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 19:48:55 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QSORT_H
# define QSORT_H

void	qsort_void_ptr(void **arr, int len, int (*is_greater)(void *, void *));

#endif
