#include "file_info.h"
#include "pretty_print.h"
#include <sys/ioctl.h>
#include "libft.h"

int		n_columns_terminal()
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	return(w.ws_col);
}

int		max_elem(int *arr, int len)
{
	int	max;
	int	i;

	i = 0;
	max = arr[i];
	while (i < len)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

int		choose_ncolumns(int width, int len, int *sizes)
{
	int	max_len;

	max_len = max_elem(sizes, len);
	return (width / (max_len + 3));
}

static int		my_abs(int x)
{
	return (x > 0 ? x : x * -1);
}

static void			ft_itoa_stack(int n, char *s)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		s[0] = '-';
		i++;
	}
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		s[i++] = my_abs(n % 10) + '0';
		n = n / 10;
	}
	ft_strrev((s[0] == '-') ? s + 1 : s);
}


static void	print(int n_cols, int len, int width, t_file_info **info)
{
	int		i;
	char	*fmt;
	char	nbr[12];

	ft_itoa_stack(width / n_cols, nbr);
	fmt = ft_strjoin("%-", nbr);
	fmt = ft_strjoin(fmt, "s");
	i = 0;
	while (i < len)
	{
		ft_printf(fmt, start_of_name(info[i]->pathname));
		if (!((i + 1) % n_cols))
			ft_printf("%c", '\n');
		i++;
	}
	if ((i + 1 % n_cols))
		ft_printf("%c", '\n');
	free(fmt);
}

void	pretty_print(t_flags flags, t_file_info **info, int len)
{
	int	*sizes;
	int	i;
	int	n_cols;
	int	term_width;

	(void )flags;
	term_width = n_columns_terminal();
	sizes = malloc(sizeof(int) * len);
	if (!sizes)
		return ;
	i = -1;
	while (++i < len)
		sizes[i] = ft_strlen(start_of_name(info[i]->pathname));
	n_cols = choose_ncolumns(term_width, len, sizes);
	print(n_cols, len, term_width, info);
	free(sizes);
}
