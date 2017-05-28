##
## makefile for make in /home/jordan.roucom/CPool_rush3
## 
## Made by Jordan Rouco miguez
## Login   <jordan.roucom@epitech.net>
## 
## Started on  Sat Oct 29 17:09:21 2016 romain pillot
## Last update Sun May 28 03:59:28 2017 romain pillot
##

CC	=	gcc

NAME	=	ai

RM	=	rm -f

SRCS	=	src/main.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-Werror -Wall -Wextra -Iinc

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
