
all:
	make -C libft
	gcc -Wall -Wextra -O3 *.c -I. -Ilibft/includes -L libft -lft -o ft_ls 
	gcc -Wall -Wextra -g *.c -I. -Ilibft/includes -L libft -lft -o ft_ls 
