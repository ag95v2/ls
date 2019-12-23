#include "file_info.h"

void	clear_fileinfo(t_file_info *f)
{
	free(f->owner);
	free(f->group);
	free(f->date);
	free(f->pathname);
	free(f);
}

void	clear_fi_array(t_file_info **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
		clear_fileinfo(arr[i]);
}
