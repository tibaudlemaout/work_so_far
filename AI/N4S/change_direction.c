/*
** EPITECH PROJECT, 2023
** B-AIA-200-NAN-2-1-n4s-tibaud.le-maout
** File description:
** change_direction
*/
#include "include/my.h"

void left(struct_t *data, double direction[6], int range[5])
{
	int i = 0;

	while (i < 5) {
		if (data->middle < range[i]) {
			dprintf(1, "wheels_dir: %.2f\n", direction[i]);
			get_next_line(0, 0);
			break;
		} else
			i++;
	}
}

void right(struct_t *data, double direction[6], int range[5])
{
	int i = 0;

	while (i < 5) {
		if (data->middle < range[i]) {
			dprintf(1, "wheels_dir: %.2f\n", (direction[i] *= -1));
			get_next_line(0, 0);
			break;
		} else
			i++;
	}
}

int change_direction(struct_t *data, char **tab)
{
	double direction[6] = {0.33, 0.3, 0.22, 0.18, 0.03, 0.01};
	int range[5] = {400, 500, 700, 1020, 1350};

	data->left = atof(tab[3]);
	data->right = atof(tab[34]);
	data->middle = atof(tab[19]);
	if (data->left > data->right)
		left(data, direction, range);
	else
		right(data, direction, range);
	return (0);
}
