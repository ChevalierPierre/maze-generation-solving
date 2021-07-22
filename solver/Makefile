##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	=	solver

NAMET	=	unit_tests

CC	=	gcc

SRC	=	src/main.c \
		src/get_file.c \
		src/my_math.c \
		src/destroy.c \
		src/algorithm/algorithm_add.c \
		src/algorithm/algorithm_destroy.c \
		src/algorithm/algorithm_moves.c \
		src/algorithm/algorithm_tools.c

SRCT	=	tests/tests.c

CPPFLAGS=	-Iinclude/

CFLAGS	=	-W -Wall -Wextra -pedantic

OBJ	=	$(SRC:.c=.o)

OBJT	=	tests.o

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

tests_run:
	$(CC) --coverage -c $(SRCT)
	$(CC) $(CFLAGS) $(OBJT) -lcriterion -lgcov -o $(NAMET)
	./$(NAMET)

clean:
	$(RM) $(OBJ) $(OBJT)
	$(RM) *.gcno *.gcda

fclean:	clean
	$(RM) $(NAME) $(NAMET)

re:	fclean all

.PHONY: all, clean, fclean, re, tests_run, lib_make
