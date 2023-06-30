/*
** EPITECH PROJECT, 2023
** Paint
** File description:
** events
*/
#include "../include/my.h"

void enable_menu_events(struct_t *data, menu_t *menu, sfVector2i pos)
{
    for (int i = 0; i < 8; i++) {
        if (pos.x >= 767 && pos.x <= 843 && pos.y >= 475 && pos.y <= 550) {
            if (menu->button[0].clicked == 1)
                menu->button[0].clicked = 0;
            else
                menu->button[0].clicked = 1;
            menu->button[3].display = 1;
            menu->button[4].display = 1;
            menu->side_menu.display = 1;
            // printf("on pencil\n");
            return;
        }
        if (pos.x >= 882 && pos.x <= 958 && pos.y >= 475 && pos.y <= 550) {
            menu->side_menu.set = 3;
            // printf("on grid\n");
            return;
        }
        if (pos.x >= 992 && pos.x <= 1078 && pos.y >= 475 && pos.y <= 550) {
            menu->side_menu.set = 4;
            // printf("on file\n");
            return;
        }
        if (pos.x >= 770 && pos.x <= 870 && pos.y >= 565 && pos.y <= 595 &&
            menu->button[0].clicked == 1) {
            menu->side_menu.set = 2;
            printf("eraser\n");
        }
        if (pos.x >= 770 && pos.x <= 870 && pos.y >= 600 && pos.y <= 630 &&
            menu->button[0].clicked == 1) {
            menu->side_menu.set = 1;
            printf("pencil\n");
        }
        if(is_on_color(data, menu, pos, i) == 1) {
            data->set_color = i;
            return;
        }
    }
    return;
}

void drawing(struct_t *data, menu_t *menu, sfVector2i pos)
{
    if (menu->tools[menu->set_tool].shape == 1)
        draw_square(data, menu, data->set_color, pos);
    if (menu->tools[menu->set_tool].shape == 2)
        draw_circle(data, menu, data->set_color, pos);
    return;
}

void edit_brush_size(struct_t *data, menu_t *menu)
{
    if (EVENT.mouseWheelScroll.delta > 0)
        menu->tools[menu->set_tool].size += 1;
    else if (menu->tools[menu->set_tool].size > 1)
        menu->tools[menu->set_tool].size -= 1;
    return;
}

void manage_events(struct_t *data, menu_t *menu)
{
    if (EVENT.type == sfEvtClosed) {
        data->set = 0;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfVector2i posi = getMousePosi(data, menu);
        printf("x : %d | y : %d\n", posi.x, posi.y);
        if (data->menu == 1)
            enable_menu_events(data, menu, posi);
        else
            drawing(data, menu, posi);
        return;
    }

    if (data->menu == 1 && EVENT.type ==sfEvtMouseMoved) {
        sfVector2i posi = getMousePosi(data, menu);
        if (posi.x >= 767 && posi.x <= 843 && posi.y >= 475 && posi.y <= 550) {
            menu->button[3].display = 1;
            menu->button[4].display = 1;
        } else if (menu->button[0].clicked == 0){
            menu->button[3].display = 0;
            menu->button[4].display = 0;
        }
    }

    if (EVENT.type == sfEvtMouseWheelScrolled) {
        edit_brush_size(data, menu);
    }
    if (EVENT.type == sfEvtKeyReleased && EVENT.key.code == sfKeySpace) {
        if (data->menu == 1) {
            data->menu = 0;
            menu->side_menu.display = 0;
            menu->button[3].display = 0;
            menu->button[4].display = 0;
        } else
            data->menu = 1;
    }
}
