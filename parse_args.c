/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:41:28 by bgian             #+#    #+#             */
/*   Updated: 2019/12/24 16:09:02 by bgian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_info.h"
#include "errors.h"

static t_stats	*coud_not_push(t_stats *res)
{
	rmstats(res, &del);
	return (0);
}

/*
**	Return 0 in case of valid flags.
**	Consider each command line argument starting with "-" as a flag specifier
**	rather than path (like in original ls)
**	Return 1 in case of serious problems
*/

t_stats			*parse_args(t_flags *flags, int argc, char **argv)
{
	t_stats	*res;

	if (!(res = (t_stats *)ft_memalloc(sizeof(t_stats))))
		return (0);
	init_flags(flags);
	while (argc > 1)
	{
		if (is_option_arg(argv[argc - 1]))
		{
			if (read_option_arg(argv[argc - 1], flags))
			{
				ft_fprintf(2, "ft_ls: unrecognized option: %s\n",\
						argv[argc - 1]);
				rmstats(res, &del);
				return (0);
			}
			argc--;
			continue ;
		}
		if (push(res, argv[argc - 1]) == critical)
			return (coud_not_push(res));
		argc--;
	}
	return (res);
}

t_file_info		**get_args_fileinfo(t_stats *stats)
{
	t_file_info	**info;
	int			i;

	i = 0;
	info = (t_file_info **)malloc(sizeof(t_file_info *) * stats->n_files);
	if (!info)
		return (0);
	while (stats->n_files)
		info[i++] = pop_file(stats);
	return (info);
}

/*
**	TODO: process errors from pop_file
*/
