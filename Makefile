NAME = libpushswap.a
CFLAGS = -Wall -Wextra -Werror
LEAKLAGS = -g3 -fsanitize=address
SOURCE = pushswap/push_swap.c \
		pushswap/pre_push_swap.c \
		pushswap/quick_sort.c \
		utils/ft_atoi.c \
		utils/ft_split.c \
		utils/exception.c
LIB = -L. -lpushswap
MAIN = pushswap/main.c
OUT = push_swap
OBJECT = push_swap.o \
		quick_sort.o \
		ft_atoi.o \
		ft_split.o \
		exception.o

$(NAME): $(OBJECT)
	ar	rcs $(NAME) $(OBJECT)
$(OBJECT): $(SOURCE)
	gcc $(CFLAGS) -c $(SOURCE)

all : $(NAME)
clean:
	@rm -f $(OBJECT)
fclean: clean
	@rm -f $(NAME)
	@rm -f $(OUT)
re:	fclean all
gcc: all
	gcc $(MAIN) $(CFLAGS) $(LIB) -o $(OUT)

.PHONY: all clean fclean re