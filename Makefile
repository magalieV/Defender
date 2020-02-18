##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile runner
##

ECHO    =       /bin/echo -e

CC      =       gcc

RM      =       rm -f

INC     =       -I./include

LIBF	=	-l csfml-graphics -l csfml-window -l csfml-system -l csfml-network -l csfml-audio

CFLAGS  +=      $(INC)

LIB_G	=	lib/graph/set_struct_button.c	\
			lib/graph/set_struct_objet.c	\
			lib/graph/set_struct_anim.c		\
			lib/graph/set_struct_text.c		\
			lib/graph/set_struct_music.c

LIB_NG	=	lib/no_graph/gnl.c					\
			lib/no_graph/my_itoa.c				\
			lib/no_graph/my_strdup.c			\
			lib/no_graph/open_file.c			\
			lib/no_graph/my_str_to_word_array.c	\
			lib/no_graph/str_to_tab.c

LIB		=	$(LIB_G)	\
			$(LIB_NG)

ANIM	=	src/game/anim/anim_fire.c		\
			src/game/anim/anim_monster.c	\
			src/game/anim/moove_monster.c	\
			src/game/anim/attaque.c			\
			src/game/anim/attaque_ini.c		\
			src/game/anim/touch_monster.c	\
			src/game/anim/mvt_monster.c

GAME	=	src/game/destroy.c			\
			src/game/get_next_line.c	\
			src/game/init_game_board.c	\
			src/save/save_game.c		\
			src/save/test_bulding.c

DISPLAY	=	src/game/display/back_ground.c	\
			src/game/display/display_game.c	\
			src/game/display/display.c		\
			src/game/display/pause_menu.c

EVENT	=	src/game/event/event_game.c		\
			src/game/event/fire_path.c		\
			src/game/event/create_all_object.c	\
			src/game/event/end_game.c

OBJECT	=	src/game/object/castle.c			\
			src/game/object/create_tab_object.c	\
			src/game/object/link.c				\
			src/game/object/tower_display.c		\
			src/game/object/node.c

PATHH	=	src/game/path/assign_path.c		\
			src/game/path/found_path.c

TEXT	=	src/game/text_game/score.c	\
			src/game/text_game/text_create.c

MENU	=	src/menu/load.c				\
			src/menu/main.c				\
			src/draw/pixel.c			\
			src/menu/menu_display.c		\
			src/event/check_event.c		\
			src/menu/page_menu.c		\
			src/menu/play_menu.c		\
			src/menu/back_gestion.c		\
			src/menu/how_to_play/how_to_play_gestion.c	\
			src/menu/option/option_gestion.c			\
			src/menu/option/option_event.c				\
			src/menu/credit/credit_gestion.c			\
			src/draw/melted.c							\

SRC_C	=	$(LIB)	\
			$(MENU)	\
			$(GAME)	\
			$(PATHH)	\
			$(DISPLAY)	\
			$(EVENT)	\
			$(OBJECT)	\
			$(ANIM)	\
			$(TEXT)

OBJ	=	$(SRC_C:.c=.o)

NAME	=	my_defender

all	:	title $(NAME)

title	:
		@$(ECHO) "Program is: $(NAME)"

$(NAME)	:	$(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS) $(LIBF)	&&	\
		$(ECHO) "[OK] [$(NAME) Has Been Created]" || \
		$(ECHO) "[KO] [$(NAME) Has Been Failed]"

%.o :   %.c
		@$(CC) -c -o $@ $< $(CFLAGS) $(LIBF)&& \
		$(ECHO) "[OK]" $< || \
		$(ECHO) "[KO]" $<

clean :
		@$(RM) $(OBJ)

fclean :        clean
		@$(RM) vgcore.*
		@$(RM) $(NAME) && \
		$(ECHO) "[OK] [$(NAME) Has Been Deleted]"

re :	fclean all

.PHONY :	all re clean fclean
