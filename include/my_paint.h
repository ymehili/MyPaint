/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** my_paint
*/

#ifndef MY_PAINT_H_
    #define MY_PAINT_H_
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <time.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>
    #include <math.h>
    #include <string.h>
    #include <stdarg.h>

typedef struct menubutton_s {
    struct button_s *prev;
    sfRectangleShape *button;
    char *string;
    sfText *text;
    int button_size;
    struct button_s *next;
} button_t;

typedef struct menubar_s {
    sfRectangleShape *bar;
    button_t *buttons;
} menubar_t;

typedef struct global_s {
    sfRenderWindow *window;
    sfEvent event;
    menubar_t *menubar;
} global_t;

int my_paint(int ac, char **av);
sfRenderWindow *create_window(unsigned int width, unsigned int height);
void *my_malloc(unsigned int size);
int my_strlen(char const *str);

#endif /* !MY_PAINT_H_ */
