/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmstats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:12:20 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 15:12:40 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "file_info.h"

void	del(void *content, size_t content_size)
{
	(void)content_size;
	free(((t_path_stat *)content)->path);
	free(((t_path_stat *)content)->sb);
	free(((t_path_stat *)content));
	content = 0;
}

void	rmstats(t_stats *stats, void (*del)(void *, size_t))
{
	ft_lstdel(&(stats->files), del);
	ft_lstdel(&(stats->dirs), del);
	free(stats);
}
