##
## makefile for make in /home/jordan.roucom/CPool_rush3
## 
## Made by Jordan Rouco miguez
## Login   <jordan.roucom@epitech.net>
## 
## Started on  Sat Oct 29 17:09:21 2016 romain pillot
## Last update Sat Jun  3 23:23:59 2017 romain pillot
##

CC	=	gcc

NAME	=	ai

RM	=	rm -f

SRCS	=	src/main.c			\
		src/sender.c			\
		src/util/print.c		\
		src/util/read.c			\
		src/util/array.c		\
		src/util/free.c			\
		src/util/nbr/nbr_parseint.c	\
		src/util/str/str_contains.c	\
		src/util/str/str_countchar.c	\
		src/util/str/str_duplicate.c	\
		src/util/str/str_equals.c	\
		src/util/str/str_length.c	\
		src/util/str/str_reduce.c	\
		src/util/str/str_split.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-Iinc -g3 -Werror -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
