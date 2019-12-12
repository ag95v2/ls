
#include <stdio.h>
#include "file_info.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./file_info <path>\n");
		return (1);
	}
	print_file_info(argv[1]);
	return (0);
}
