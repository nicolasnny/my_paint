##
## EPITECH PROJECT, 2023
## B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
## File description:
## Makefile
##


SRC	=	button.c	\
		drop_menu.c	\
		init.c		\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_paint

LDFLAGS =	-L./lib/my

LDLIBS	=	-lmy -l csfml-graphics -l csfml-window -l csfml-system

LIBNAME	=	libmy.a

CPPFLAGS	=	-iquote./src/include

CFLAGS	=	-Wall -Wextra

CS_REPORT = coding-style-reports.log

all:	lib	$(NAME)

lib: fclean
	$(MAKE) -C lib/my

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C lib/my clean

fclean:	clean
	$(MAKE) -C lib/my fclean
	$(RM) $(NAME)
	$(RM) $(CS_REPORT)

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
