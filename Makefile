##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME	=	my_rpg

SRC		:=	src/main.c						\
			src/other/window.c				\
			src/other/sprite.c				\
			src/other/map.c					\
			src/other/my_str_to_word.c		\
			src/other/poll_event.c			\
			src/other/transition.c			\
			src/player/player_movements.c	\
			src/player/handle_collisions.c	\
			src/player/player.c				\
			src/player/render_life.c		\
			src/player/init_doors.c			\
			src/player/experience.c			\
			src/inventory/handle_events.c	\
			src/inventory/inventory_page.c	\
			src/inventory/weapon.c			\
			src/inventory/stats.c			\
			src/inventory/destroy_stats.c	\
			src/main_menu/actions.c			\
			src/main_menu/menu.c			\
			src/main_menu/texts.c			\
			src/options/actions.c			\
			src/options/buttons.c			\
			src/options/texts.c				\
			src/options/options.c			\
			src/save/display_save.c			\
			src/save/save_events.c			\
			src/save/save_game.c			\
			src/save/destroy_save.c			\
			src/save/save_btn.c				\
			src/pause_menu/actions.c		\
			src/pause_menu/menu.c			\
			src/pause_menu/commands.c		\
			src/bot/bots.c					\
			src/player/assistance.c			\

OBJ		=	$(SRC:.c=.o)

CLIBS	=	-l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window

CFLAGS	=	-Iinclude -lc -lm -g3

$(NAME)	:	$(OBJ)
			gcc -o $(NAME) $(OBJ) $(CLIBS) $(CFLAGS)

all		:	$(NAME)

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
