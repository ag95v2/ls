#include <stdio.h>
#include "qsort.h"
#include <string.h>

int	is_greater(void *a, void *b)
{
	return (strcmp((const char *)a, (const char *)b));
}

void	print_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		printf("%s\n", argv[i]);
}

int	main(int argc, char **argv)
{
	qsort_void_ptr((void *)(argv + 1), argc - 1, is_greater);
	print_args(argc, argv);
}
