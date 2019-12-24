NAME = ft_ls

FLAGS = -Wall -Wextra -Werror

SRC = colors.c \
	comparators.c \
	comparators0.c \
	file_info.c \
	file_info0.c \
	file_info1.c \
	file_info_clear.c \
	filesort.c \
	fs_utils.c \
	get_stats.c \
	main.c \
	offsets.c \
	parse_args.c \
	parse_flags.c \
	pretty_print.c \
	pretty_print0.c \
	print_dir_listing.c \
	print_dl_0.c \
	print_file_info.c \
	print_n_spaces.c \
	rm_fileinfo.c \
	rmstats.c \
	sort_void_ptr.c

OBJS = $(SRC:.c=.o)

all: $(NAME)
	@gcc -o $(NAME) $(OBJS) -L libft/ -lft 

$(NAME): lib $(OBJS)

lib:
		@make -C libft/

%.o : %.c
		@gcc -I. -I libft/includes/ $(FLAGS) -c $^ 

all: $(NAME)

clean:
		@make -C libft/ clean
		@rm -f $(OBJS)

fclean: clean
		@make -C libft/ fclean
		@rm -f $(NAME)

re: fclean all
