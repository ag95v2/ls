SRCS = file_info.c main.c ft_ls.c get_input.c 

all:
	make -C libft
	gcc -Wall -Wextra -g $(SRCS) -I. -Ilibft/includes -L libft -lft -o file_info
