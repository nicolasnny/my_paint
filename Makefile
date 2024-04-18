##
## EPITECH PROJECT, 2023
## B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
## File description:
## Makefile
##


SRC	=	src/button.c			\
		src/drop_menu.c			\
		src/drop_menu_list.c	\
		src/click_options.c		\
		src/color_setting.c		\
		src/file_buttons.c		\
		src/file_managment.c	\
		src/help_managment.c	\
		src/edit_buttons.c		\
		src/destroy.c			\
		src/menu_events.c		\
		src/draw.c				\
		src/init.c				\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_paint

LDLIBS	=	-l csfml-graphics -l csfml-window -l csfml-system

CPPFLAGS	=	-iquote./include

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
