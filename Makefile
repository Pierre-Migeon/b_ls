# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:09:15 by pmigeon           #+#    #+#              #
#    Updated: 2018/10/18 13:01:29 by pmigeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = src/ft_strcmp.c src/ls.c src/sort.c
HEADER = ./includes/
LIBNAME = libftprintf.a
COMPILER = gcc
FLAGS = -Wall -Werror -Wextra
OFILE = ft_strcmp.o ls.o sort.o
NAME = libftprintf.a

all: $(NAME)

$(NAME):
	$(COMPILER) $(FLAGS) -c $(SOURCES)
	$(COMPILER) $(FLAGS) $(OFILE) -o ./ls

makelib: re
	ar rc $(LIBNAME) $(OFILE)
	ranlib $(LIBNAME)

compile: re
	$(COMPILER) $(FLAGS) -c $(SOURCES) 
	$(COMPILER) $(FLAGS) $(OFILE) -o ls

re: fclean all

clean:
	/bin/rm -f $(OFILE)

fclean: clean 
	/bin/rm -f $(LIBNAME)
