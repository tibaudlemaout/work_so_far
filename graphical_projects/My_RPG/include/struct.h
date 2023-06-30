/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-tibaud.le-maout
** File description:
** struct
*/
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct {
        sfVideoMode video_mode;
        sfRenderWindow *window;
        sfEvent event;
        int height;
        int width;
    } window_t;

    typedef struct {
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f scale;
        sfVector2f pos;
        sfIntRect rect;
    } sprite_t;

    typedef struct {
        sfText *txt;
        sfFont* font;
        sfColor color;
        sfVector2f scale;
        sfVector2f pos;
        char *str;
    } text_t;

    typedef struct {
        sfRectangleShape *rect;
        sfVector2f pos;
        sfVector2f size;
        text_t txt;
        int display;
        int hover;
    } button_t;

    typedef struct {
        sfTime time;
        sfClock *clock;
        float seconds;
    } countdown_t;

    typedef struct {
        int Default_hpMax;
        int Default_hp;
        int Default_att;
        int Default_def;
        int Default_spd;
        int hpMax;
        int old_hp;
        int hp;
        int lvl;
        int xp;
        int xpMax;
        int att;
        int def;
        int spd;
    } stat_t;

    typedef struct {
        sfTexture *TextureUp;
        sfTexture *TextureDown;
        sfTexture *TextureRight;
        sfTexture *TextureLeft;
        sfSprite *sprite;
        sfIntRect rect;
        sfVector2f scale;
        sfVector2f pos;
        countdown_t clock;
        sprite_t profile;
        sfRectangleShape *hitbox;
        stat_t stat;
        int life;
        int direction;
        int tab_x;
        int tab_y;
        char *name;
    } player_t;

    typedef struct {
        sprite_t sprite;
        stat_t stat;
        text_t txt_name;
        text_t monster_hp;
        text_t monster_ActualHp;
        char *name;
        int hp;
        int old_hp;
        int ads[3];
        int factor[3];
    } fight_monster_t;

    typedef struct {
        sprite_t bg;
        fight_monster_t monster;
        button_t *button;
        button_t player_area;
        button_t player_AttDefSpd_area;
        button_t monster_area;
        text_t player_name;
        text_t player_lvl;
        text_t player_hp;
        text_t player_ActualHp;
        text_t player_ActualXp;
        text_t player_xp;
        text_t *player_AttDefSpd;
        int p_hp;
        int p_att;
        int p_def;
        int p_spd;
        int player_turn;
        countdown_t delay;
    } fight_t;

    typedef struct {
        char *buffer;
        int HpMax;
        int Hp;
        int Att;
        int Def;
        int Spd;
        int Lvl;
        int Xp;
        int XpMax;
        int ActualArea;
        int *UnlockedAreas;
    } save_t;

    typedef struct {
        button_t button;
        sprite_t sprite;
        text_t key;
        text_t title;
    } icon_t;

    typedef struct {
        sprite_t bg_day;
        sprite_t bg_night;
        sprite_t sign1;
        sprite_t sign2;
        sprite_t sign3;
        text_t *text;
        sprite_t bg_selection;
        sprite_t *avatar;
        sprite_t *frame;
        text_t *stats;
        sfRectangleShape **rect;
        int personnage;
        text_t name;
        sprite_t input;
        text_t name_txt;
        int idx;
        icon_t *icon;
    } menu_t;

    typedef struct {
        char *name;
        int hp;
        int *ads;
        int *factor;
        sprite_t profile;
        sfTexture *TextureUp;
        sfTexture *TextureDown;
        sfTexture *TextureRight;
        sfTexture *TextureLeft;
        sfSprite *sprite;
        sfVector2f pos;
        char *profile_filepath;
    } mobs_t;

    typedef struct {
        int *quest;
        text_t *texts;
        mobs_t *npc;
        int quest_index;
        sfVector2f *txt_pos;
        sfVector2f *rect_pos;
        int end;
        int quest_1;
        int quest_2;
    } tutorial_t;

    typedef struct {
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f pos;
        char *name;
        int hp;
        int att;
        int def;
        int spd;
        int equipement;
        int type;
        int nb;
    } items_t;

    typedef struct {
        int taken;
        items_t item;
        sfVector2f pos;
    } tab_t;

    typedef struct {
        sprite_t bg;
        sfRectangleShape **area;
        sfRectangleShape **equipment;
        sfVector2f *areaPos;
        sfVector2f *equipmentPos;
        sfVector2f OldPos;
        sfVector2f offset;
        sprite_t shadow;
        int drag;
        tab_t *tab;
        int idx;
        sfText **player_hads;
        sfText **item_hads;
        sfText *item_name;
    } inventory_t;

    typedef struct {
        sprite_t bg;
        sfSprite *loot_sprite;
        sfText *loot_name;
        sfText *str;
        sfRectangleShape *rect;
    } looting_t;

    typedef struct {
        sfMusic *st;
    } audio_t;

    typedef struct {
        window_t settings;
        sprite_t bg;
        sprite_t overlay;
        sprite_t minimap;
        sfRectangleShape *minimapOutline;
        player_t player;
        sfView *view;
        inventory_t inventory;
        countdown_t fight_start;
        countdown_t mark_clock;
        sfRectangleShape ***wall;
        mobs_t *mob;
        int starting_fight;
        int set;
        int avatar;
        save_t save;
        int random_mob_nb;
        int interact;
        int talk;
        sprite_t interact_balloon;
        text_t interact_txt;
        sprite_t txt_frame;
        tutorial_t tuto;
        tutorial_t area1;
        tutorial_t dungeon1;
        items_t *item;
        int winner;
        int area;
        int old_set;
        sfSprite **icon;
        int map;
        audio_t *music;
    } struct_t;

#endif /* !STRUCT_H_ */
