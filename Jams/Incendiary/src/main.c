/*
** EPITECH PROJECT, 2023
** Epitech_Jam_1
** File description:
** main
*/
#include "../include/struct.h"
#include "../include/my.h"
#include "../include/define.h"

void init_window(struct_t *all)
{
    all->settings.height = 1080;
    all->settings.width = 1920;
    MODE.bitsPerPixel = 32;
    MODE.height = all->settings.height;
    MODE.width = all->settings.width;
    WIN = sfRenderWindow_create(MODE, "incendiary", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(WIN, 60);
}
    
void main_loop(struct_t *all)
{
    menu_t menu;
    init_menu(&menu);
    init_sound(all);
    all->set = 1;
    while (sfRenderWindow_isOpen(WIN)) {
        sfRenderWindow_display(WIN);
        sfRenderWindow_clear(WIN, sfBlack);
        switch (all->set) {
            case 0: sfRenderWindow_close(WIN); return;
            case 1: play_menu(all, &menu, &all->settings.event); break;
            case 2: play_keybinds(all, &menu, &all->settings.event); break;
            case 3: ingame_audio(all); play_game(all, &all->settings.event); break;
            case 4: sfMusic_stop(all->soundtrack[1].music); lose_screen(all, &all->settings.event); break;
            case 5: win_audio(all); win_screen(all, &all->settings.event); break;
            case 6: play_villain(all, &all->settings.event); break;
        }
    }
    destroy_menu(&menu, all);
}

int main(void)
{
    struct_t all;
    init_window(&all);
    main_loop(&all);
}
