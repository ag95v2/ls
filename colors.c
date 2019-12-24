#include "colors.h"

void	set_color(t_file_info *fi)
{
	if (!isatty(1))
		return ;
	if (fi->type == 'd')
		ft_printf("%s", KBLU);
	if (fi->type == 'l')
		ft_printf("%s", KCYN);
	if (fi->type == '-' && (fi->perms[2] == 'x' || fi->perms[7] == 'x' ||  fi->perms[5] == 'x' ))
		ft_printf("%s", KGRN);
}

void	reset_color()
{
	if (!isatty(1))
		return ;
	ft_printf("%s", KNRM);
}


