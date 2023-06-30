##
## EPITECH PROJECT, 2023
## B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
## File description:
## Makefile
##

SRC =	src/main.c										\
		src/lib.c										\
		src/lib2.c										\
		src/lib3.c										\
		src/lib4.c										\
		src/loop_selector.c								\
		src/get_loot.c									\
		src/loops/menu.c								\
		src/loops/selection.c							\
		src/loops/name.c								\
		src/loops/game.c								\
		src/loops/fight.c								\
		src/loops/inventory.c							\
		src/loops/map.c									\
		src/loops/area1.c								\
		src/loops/in_game_menu.c						\
		src/loops/dungeon1.c							\
		src/save/load_save.c							\
		src/init/menu.c									\
		src/init/selection.c							\
		src/init/name.c									\
		src/init/struct.c								\
		src/init/struct2.c								\
		src/init/player.c								\
		src/init/fight.c								\
		src/init/fight_button.c							\
		src/init/fight_monster.c						\
		src/init/fight_player_stats_area.c				\
		src/init/fight_monster_stats_area.c				\
		src/init/fight_player_stats_texts.c				\
		src/init/fight_monster_stats_texts.c			\
		src/init/finishing_fight.c						\
		src/init/icons.c								\
		src/init/inventory.c							\
		src/init/inventory_player_stat.c				\
		src/init/inventory_item_stat.c					\
		src/init/collisions_tab.c						\
		src/init/mobs.c									\
		src/init/mobs_utils.c							\
		src/init/tutorial.c								\
		src/init/tutorial_sprites.c						\
		src/init/items.c								\
		src/init/area1_struct.c							\
		src/init/area1_npc.c							\
		src/init/dungeon1_struct.c						\
		src/init/dungeon1_npc.c							\
		src/display/menu.c								\
		src/display/selection.c							\
		src/display/name.c								\
		src/display/game.c								\
		src/display/fight.c								\
		src/display/inventory.c							\
		src/display/map.c								\
		src/display/interaction_balloon.c				\
		src/display/area1.c								\
		src/display/area1_interaction_balloon.c			\
		src/display/dungeon1.c							\
		src/display/dungeon1_interaction_balloon.c		\
		src/events/menu.c								\
		src/events/selection.c							\
		src/events/name.c								\
		src/events/principal.c							\
		src/events/player_moves.c						\
		src/events/collision.c							\
		src/events/fight.c								\
		src/events/fight_animation.c					\
		src/events/inventory.c							\
		src/events/inventory2.c							\
		src/events/map.c								\
		src/events/tutorial_interaction.c				\
		src/events/check_interact.c						\
		src/events/in_game_menu.c						\
		src/events/area1_principal.c					\
		src/events/area1_check.c						\
		src/events/area1_interaction_management.c		\
		src/events/selectors.c							\
		src/events/dungeon1_principal.c					\
		src/events/dungeon1_check.c						\
		src/events/dungeon1_interaction_management.c	\
		src/animations/player.c							\
		src/animations/starting_fight.c					\
		src/animations/finishing_fight.c				\
		src/animations/fight_damages.c					\
		src/animations/tutorial.c						\
		src/animations/tutorial2.c						\
		src/animations/tutorial3.c

OBJ =	$(SRC:.c=.o)

NAME =	my_rpg

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:	$(NAME)

$(NAME):
		@gcc -o $(NAME) $(SRC) $(CSFML) -lm
		@rm -f $(OBJ)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re:		fclean all
