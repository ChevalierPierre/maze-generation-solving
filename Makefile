##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

all:
	make -C solver/
	make -C generator/
	cp solver/solver tournament/
	cp generator/generator tournament/

clean:
	make clean -C solver/
	make clean -C generator/

fclean:
	make fclean -C solver/
	make fclean -C generator/
	$(RM) tournament/*

re:	fclean all

.PHONY: all, clean, fclean, re
