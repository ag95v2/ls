
all:
	make -C libft
	gcc -Wall -Wextra -pg -g -O3 *.c -I. -Ilibft/includes -L libft -lft -o ft_ls
	gcc -Wall -Wextra -pg -g *.c -I. -Ilibft/includes -L libft -lft -o ft_ls
