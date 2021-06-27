NAME = libpushswap.a
CFLAGS = -Wall -Wextra -Werror -g
SOURCE = pushswap/push_swap.c \
		pushswap/find_route.c \
		pushswap/pre_push_swap.c \
		pushswap/move_val.c \
		pushswap/quick_sort.c \
		pushswap/simple_push_swap.c \
		utils/ft_atoi.c \
		utils/ft_split.c \
		utils/exception.c \
		utils/commands.c \
		utils/handle_deque.c \
		utils/handle_deque2.c \

LIB = -L. -lpushswap
MAIN = pushswap/main.c
OUT = push_swap
OBJECT = push_swap.o \
		find_route.o \
		pre_push_swap.o \
		move_val.o \
		commands.o \
		quick_sort.o \
		ft_atoi.o \
		ft_split.o \
		exception.o \
		handle_deque.o \
		handle_deque2.o \
		simple_push_swap.o \

$(NAME): $(OBJECT)
	ar	rcs $(NAME) $(OBJECT)
$(OBJECT): $(SOURCE)
	gcc $(CFLAGS) -c $(SOURCE)

all : $(NAME)
	gcc $(MAIN) $(CFLAGS) $(LIB) -o $(OUT)
clean:
	@rm -f $(OBJECT)
fclean: clean
	@rm -f $(NAME)
	@rm -f $(OUT)
re:	fclean all

.PHONY: all clean fclean re