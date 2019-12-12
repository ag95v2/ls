SRCS = file_info.c main.c ft_ls.c get_input.c libft/glibft.a

all:
	gcc -Wall -Wextra -g $(SRCS) -I. -Ilibft/includes -o file_info
