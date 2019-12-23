#ifndef FILESORT_H
#define FILESORT_H

#include "parse_flags.h"
#include "file_info.h"

typedef int		(*t_cmpf)(void *a, void *b);
void			sort_fileinfo(t_flags flags, int n, t_file_info **info);

#endif
