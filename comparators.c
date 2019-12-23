#include "comparators.h"

int		time_is_greater(void *a, void *b)
{
	if (((t_file_info *)a)->timestamp == ((t_file_info *)b)->timestamp)
		return (0);
	return (((t_file_info *)a)->timestamp < ((t_file_info *)b)->timestamp ? 1 : -1);
}

int		time_is_not_grater(void *a, void *b)
{
	return (time_is_greater(b, a));
}

int		is_upper(char a)
{
	return (a >= 'A' && a <= 'Z' ? 1 : 0);
}

char	to_lower(char a)
{
	return (is_upper(a) ? a - 'A' + 'a' : a);
}

int		case_insensitive_strcmp(char *a, char *b)
{
	char	a0;
	char	b0;

	while ((a0 = to_lower(*a)) && (b0 = to_lower(*b)) && a0 - b0 == 0)
	{
		a++;
		b++;
	}
	return (to_lower(*a) - to_lower(*b));
}

int		name_is_greater(void *a, void *b)
{
	char	*n1;
	char	*n2;

	n1 = ((t_file_info *)a)->pathname[0] == '.' ?\
		 ((t_file_info *)a)->pathname + 1 :\
		 ((t_file_info *)a)->pathname;
	n2 = ((t_file_info *)b)->pathname[0] == '.' ?\
		 ((t_file_info *)b)->pathname + 1 :\
		 ((t_file_info *)b)->pathname;
	return (case_insensitive_strcmp(n1, n2));
}

int		inv_name_is_greater(void *a, void *b)
{
	return (name_is_greater(a, b) * -1);
}

t_cmpf	choose_comparator(t_flags flags)
{
	if (flags.sort_by_time)
		return (flags.reverse ? &time_is_not_grater : &time_is_greater);
	return (flags.reverse ? &inv_name_is_greater : &name_is_greater);
}
