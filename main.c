#include <stdio.h>
#include "file_info.h"

int	main(int argc, const char **argv)
{
	if (argc == 1)
	{
		ft_printf("Usage: ./file_info <path>\n");
		return (1);
	}
	ft_ls(argv);
	return (0);
}
