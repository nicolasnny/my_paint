##
## EPITECH PROJECT, 2023
## B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
## File description:
## Makefile
##


SRC	=	button.c			\
		init.c		\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_paint

INCLUDES	=	-iquote./src/include

CPPFLAGS	=	$(INCLUDES) 

CFLAGS	=	-Wall -Wextra

CS_CLEAN = *.log

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-window -l csfml-system

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

debug:	CFLAGS += -ggdb3
debug:	re

asan:	CC	=	clang -fsanitize=address
asan:	re

coding_style:	fclean
	coding-style . . > /dev/null 2>&1
	cat $(CS_REPORT)
	make fclean  > /dev/null 2>&1

.PHONY: all clean fclean re debug asan coding_style

.SILENT: coding_style