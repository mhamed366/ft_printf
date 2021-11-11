NAME = libftprintf.a
SRC = conversions.c\
	ft_printf.c\
	i_to_str.c\
	to_hex.c\
	u_to_hex.c\
	ui_to_str.c\
	conversions_2.c
OBJS = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) 
	ar rc $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all