#include "qsort.h"
#include "libft.h"
#include "comparators.h"

void	sort_fileinfo(t_flags flags, int n, t_file_info **info)
{
	qsort_void_ptr((void **)info, n, choose_comparator(flags));
}

