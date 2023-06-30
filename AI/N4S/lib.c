/*
** EPITECH PROJECT, 2023
** B-AIA-200-NAN-2-1-n4s-tibaud.le-maout
** File description:
** lib
*/
#include "include/my.h"

int get_words_nb(char *str)
{
	int cmp = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] == ':')
			cmp++;
	}
	return (cmp + 1);
}

char **str_to_tab(char *str)
{
	char **tab = malloc(sizeof(char *) * (get_words_nb(str) + 1));
	int y = 0;

	for (int i = 0; str[i]; i++) {
		tab[y] = malloc(sizeof(char) * (256));
		for (int x = 0; str[i] && str[i] != ':'; x++) {
			tab[y][x] = str[i++];
			tab[y][x + 1] = '\0';
		}
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

char *next(char *line, int i, char *buf, int *start)
{
	char *new = NULL;
	int len = 0;

	if (line != NULL)
		len = strlen(line);
	new = malloc((len + i + 1) * sizeof(*new));
	if (line != NULL)
		strncpy(new, line, len);
	else
		strncpy(new, "", len);
	new[len + i] = 0;
	strncpy(new + len, buf + *start, i);
	free(line);
	*start += (i + 1);
	return (new);
}

char *get_next_line(int fd, int start)
{
	size_t size = 1;
	char buffer[size];
	char *line = NULL;
	int ret = 0;

	for (int i = 0; 1; i++) {
		if (ret <= start) {
			start = 0;
			ret = read(fd, buffer, size);
			if (ret == 0)
				return (line);
			i = 0;
		}
		if (buffer[start + i] == '\n') {
			line = next(line, i, buffer, &start);
			return (line);
		}
		if ((start + i) == (ret - 1))
			line = next(line, i + 1, buffer, &start);
	}
}
