# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:09:15 by pmigeon           #+#    #+#              #
#    Updated: 2018/10/11 18:28:18 by pmigeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = src/ft_strcmp.c src/ls.c
HEADER = ./includes/
LIBNAME = libftprintf.a
COMPILER = gcc
FLAGS = -Wall -Werror -Wextra
OFILE = ft_strcmp.o ls.o
NAME = libftprintf.a

all: $(NAME)

$(NAME):
	$(COMPILER) $(FLAGS) -c $(SOURCES)
	$(COMPILER) $(FLAGS) $(OFILE) -o ./ls

makelib: re
	ar rc $(LIBNAME) $(OFILE)
	ranlib $(LIBNAME)

re: fclean all

clean:
	/bin/rm -f $(OFILE)

fclean: clean 
	/bin/rm -f $(LIBNAME)


