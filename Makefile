NAME	:= push_swap
CFLAGS	:= -Wextra -Wall -Werror
LIBFT	:= ./lib/Libft
PUSH_SWAP:= ./lib/Push_Swap

HEADERS	:= -I $(LIBFT) -I $(PUSH_SWAP)
LIBS	:= $(LIBFT)/libft.a
SRCS	:=  ./src
OBJS	:= ${SRCS:.c=.o}

all: libft $(NAME)

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<) "

$(NAME): swap

swap: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C ./lib/Libft clean

fclean: clean
	@rm -f push_swap
	@make -C ./lib/Libft fclean

re: fclean all

.PHONY: all, clean, fclean, re, libft, push_swap