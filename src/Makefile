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

SOURCES = ft_strcmp.c  
HEADER = ../includes/
LIBNAME = libftprintf.a
COMPILER = gcc
FLAGS = -Wall -Werror -Wextra
OFILE = ft_strcmp.o
NAME = libftprintf.a

all: $(NAME)

$(NAME):
	$(COMPILER) $(FLAGS) -c $(SOURCES) -I $(HEADER)
	ar rc $(LIBNAME) $(OFILE)
	ranlib $(LIBNAME)

compile: re
	$(COMPILER) $(FLAGS) -c ../ls.c
	$(COMPILER) $(FLAGS) $(OFILE) ls.o -o ../ls

clean:
	/bin/rm -f $(OFILE)
	/bin/rm -f ./main.o

fclean: clean 
	/bin/rm -f $(LIBNAME)

re: fclean all
