# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:09:15 by pmigeon           #+#    #+#              #
#    Updated: 2018/10/11 18:24:27 by pmigeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = src/ft_strcmp.c
HEADER = includes/
LIBNAME = libftprintf.a
COMPILER = gcc
FLAGS = -Wall -Werror -Wextra
OFILE = ./b_printf.o ./format.o
NAME = libftprintf.a

all: $(NAME)

$(NAME): 
	$(COMPILER) $(FLAGS) -c $(SOURCES) -I $(HEADER)
	ar rc $(LIBNAME) $(OFILE)
	ranlib $(LIBNAME)

compile: re 
	$(COMPILER) $(FLAGS) -c ./main.c 
	$(COMPILER) $(FLAGS) $(OFILE) ./main.o -o prog

clean:
	/bin/rm -f $(OFILE)
	/bin/rm -f ./main.o

fclean: clean 
	/bin/rm -f $(LIBNAME)
	/bin/rm -f ./prog

re: fclean all
