##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	=	generator

NAMET	=	unit_tests

CC	=	gcc

SRC	=	src/main.c \
		src/init.c \
		src/digging.c

SRCT	=	tests/tests.c

CFLAGS	=	-W -Wall -Wextra -pedantic

CPPFLAGS=	 -Iinclude/

OBJ	=	$(SRC:.c=.o)

OBJT	=	tests.o

LIB_DIR	=	lib/

LDFLAGS	=	-L$(LIB_DIR) -lmy_strings

all:	$(NAME)

lib_make:
	make -C $(LIB_DIR)my_strings

$(NAME):	lib_make $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)

tests_run:	lib_make
	$(CC) --coverage -c $(SRCT)
	$(CC) $(CFLAGS) $(OBJT) -lcriterion -lgcov -o $(NAMET) $(LDFLAGS)
	./$(NAMET)

clean:
	make clean -C $(LIB_DIR)my_strings
	$(RM) $(OBJ) $(OBJT)
	$(RM) *.gcno *.gcda

fclean:	clean
	make fclean -C $(LIB_DIR)my_strings
	$(RM) $(NAME) $(NAMET)

re:	fclean all

.PHONY: all clean fclean re tests_run lib_make
