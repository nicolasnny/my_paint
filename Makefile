##
## EPITECH PROJECT, 2023
## B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
## File description:
## Makefile
##


SRC	=	button.c			\
		drop_menu.c			\
		drop_menu_list.c	\
		menu_hovering.c		\
		click_options.c		\
		color_setting.c		\
		file_buttons.c		\
		file_managment.c	\
		help_managment.c	\
		edit_buttons.c		\
		destroy.c			\
		menu_events.c		\
		draw.c				\
		init.c				\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_paint

LDLIBS	=	-l csfml-graphics -l csfml-window -l csfml-system

CPPFLAGS	=	-iquote./src/include

CFLAGS	=	-Wall -Wextra

CS_REPORT = coding-style-reports.log

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(CS_REPORT)

re:	fclean all

debug:	CFLAGS += -g3
debug:	re

asan:	CC	=	clang -fsanitize=address
asan:	CFLAGS += -g3
asan:	re

gdb: debug
	gdb -ex "run" -ex "bt full" -ex "detach" -ex "quit" $(NAME)

coding_style:	fclean
	coding-style . . > /dev/null 2>&1
	cat $(CS_REPORT)
	make fclean  > /dev/null 2>&1

.PHONY: all clean fclean re debug coding_style

.SILENT: coding_style
