/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** my
*/
#include "struct.h"
#include "define.h"

#ifndef MY_H_
    #define MY_H_

// lib
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(const char *s1, const char *s2);
int my_get_nbr(int i, char *str);
char *nbr_to_str(int nb);
char *my_strcat(char *dest, char *str);
void main_loop(struct_t *data, menu_t *menu, fight_t *fight);
sfVector2i get_mouse_position(struct_t *data);
void reset_view(struct_t *data);
int my_parsing_strlen(char const *str, int idx);
int get_random_number(int max, int range);
int my_parsing_get_nbr(int i, char *str);
int idx_move(char *buffer, int idx, char stop);
void init_mob_move_sprite(mobs_t *mob, char *name);
int my_item_get_nbr(int i, char *str);
void init_one_cell(struct_t *data, int i);
void set_item_position(struct_t *data, int i);
int get_universal_loot(struct_t *data, int drop);
int get_area_loot(struct_t *data, int index);
void set_loot_into_inventory(struct_t *data, int index);
void update_inventory_item_stat(struct_t *data, items_t item);

// save
save_t load_save(struct_t *data);

// init
menu_t *init_menu(void);
void init_selection_from_menu(menu_t *menu);
void init_name_from_menu(menu_t *menu);
struct_t *init_struct(void);
void init_player(struct_t *data);
fight_t *fight_init(struct_t *data);
void init_fight_monster(struct_t *data, fight_t *fight);
void init_fight_button(fight_t *fight);
void init_player_stats_area(struct_t *data, fight_t *fight);
void init_monster_stats_area(struct_t *data, fight_t *fight);
void init_player_name_text(struct_t *data, fight_t *fight);
void init_player_attdefspd_texts(fight_t *fight);
void init_player_hp_text(struct_t *data, fight_t *fight);
void init_player_xp_text(struct_t *data, fight_t *fight);
void init_monster_name_text(struct_t *data, fight_t *fight);
void init_monster_hp_text(struct_t *data, fight_t *fight);
void init_inventory(struct_t *data);
void init_inventory_shadow(struct_t *data);
void init_icons(menu_t *menu);
void get_collision_tab(struct_t *data, char *filepath);
void init_mobs_area_1(struct_t *data);
void init_tutorial(struct_t *data);
void init_tutorial_sprites(struct_t *data);
void init_interact_balloon(struct_t *data);
void init_items_tab(struct_t *data);
void init_inventory_player_stat_txt(struct_t *data);
void init_inventory_item_stat_txt(struct_t *data);
looting_t *init_finishing_fight(struct_t *data, int idx);
void init_main_icons(struct_t *data);
void init_area1_struct(struct_t *data);
void init_area_1_npc(struct_t *data);
void init_all_quests(struct_t *data);
void init_dungeon1_struct(struct_t *data);
void init_dungeon_1_npc(struct_t *data);

// display
void menu_display(struct_t *data, menu_t *menu);
void selection_display(struct_t *data, menu_t *menu);
void name_display(struct_t *data, menu_t *menu);
void game_display(struct_t *data);
void fight_display(struct_t *data, fight_t *fight);
void inventory_display(struct_t *data);
void map_display(struct_t *data);
void display_interaction_ballon(struct_t *data);
void area1_display(struct_t *data);
void area1_display_interaction_ballon(struct_t *data);
void dungeon1_display(struct_t *data);
void dungeon1_display_interaction_ballon(struct_t *data);

// events
void menu_manage_events(struct_t *data, menu_t *menu);
void selection_manage_events(struct_t *data, menu_t *menu);
void name_manage_events(struct_t *data, menu_t *menu);
void manage_events(struct_t *data);
int manage_player_moves(struct_t *data);
int check_hitbox(struct_t *data, sfVector2f movement);
void fight_manage_events(struct_t *data, fight_t *fight);
void fight_animation_manage_events(struct_t *data);
void inventory_manage_events(struct_t *data);
int check_in_equipment_item_tab(struct_t *data, sfVector2i posi);
int check_in_main_item_tab(struct_t *data, sfVector2i posi);
void update_player_stats(struct_t *data, int idx);
void map_manage_events(struct_t *data);
void move_all(struct_t *data, sfVector2f movement);
void interaction_management(struct_t *data);
int check_interact(struct_t *data, sfVector2f old_pos, sfRectangleShape *rect);
void is_npc_for_quest(struct_t *data, sfRectangleShape *rect, int set);
void is_npc_for_quest_tuto(struct_t *data, sfRectangleShape *rect);
int progress_check(struct_t *data, sfVector2f pos, int set);
int tuto_progress_check(struct_t *data, sfVector2f pos);
void last_tutorial_interaction(struct_t *data);
void check_for_object_position(struct_t *data, sfVector2i posi);
void in_game_menu_manage_events(struct_t *data, menu_t *menu);
void area1_manage_events(struct_t *data);
void is_npc_for_quest_area1(struct_t *data, sfRectangleShape *rect);
int area1_progress_check(struct_t *data, sfVector2f pos);
void area1_interaction_management(struct_t *data);
void dungeon1_manage_events(struct_t *data);
void is_npc_for_quest_dungeon1(struct_t *data, sfRectangleShape *rect);
int dungeon1_progress_check(struct_t *data, sfVector2f pos);
void dungeon1_interaction_management(struct_t *data);

// animation
void player_move_animation(struct_t *data);
void starting_fight_animation(struct_t *data, int starting_fight, int set);
void monster_damages_animation(struct_t *data, fight_t *fight, int n, int dmg);
void player_damages_animation(struct_t *data, fight_t *fight, int n, int dmg);
void finishing_fight_animation(struct_t *data, fight_t *fight);
void tutorial_animation(struct_t *data);
void tutorial_animation2(struct_t *data);
void tutorial_animation3(struct_t *data);

// loop
void menu_loop(struct_t *data, menu_t *menu);
void selection_loop(struct_t *data, menu_t *menu);
void name_loop(struct_t *data, menu_t *menu);
void game_loop(struct_t *data);
fight_t *fight_loop(struct_t *data);
void inventory_loop(struct_t *data);
void map_loop(struct_t *data);
void area1_loop(struct_t *data);
void in_game_menu_loop(struct_t *data);
void dungeon1_loop(struct_t *data);

#endif /* !MY_H_ */
