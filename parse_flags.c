#include "libft.h"
#include "parse_flags.h"

void	init_flags(t_flags *flags)
{
	flags->recursive = 0;
	flags->reverse = 0;
	flags->sort_by_time = 0;
	flags->all = 0;
	flags->long_format = 0;
}

/*
**	"-" is a filename not option string
*/

int		is_option_arg(char *arg)
{
	if ((*arg == '-' && *(arg + 1)) || !ft_strcmp(arg, "--all"))
		return (1);
	return (0);
}

/*
**	Return 0 if argument contains only valid option
**		   invalid option character otherwise
**	Fill t_flags
*/

int		read_option_arg(char *arg, t_flags *flags)
{
	if (!ft_strcmp(arg, "--all"))
	{
		flags->all = 1;
		return (0);
	}
	while (*(++arg))
	{
		if (*arg == 'l')
			flags->long_format = 1;
		else if (*arg == 'a')
			flags->all = 1;
		else if (*arg == 'R')
			flags->recursive = 1;
		else if (*arg == 'r')
			flags->reverse = 1;
		else if (*arg == 't')
			flags->sort_by_time = 1;
		else
			return (*arg);
	}
	return (0);
}
