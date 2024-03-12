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
    #define FONT_PATH "assets/font.ttf"
    #define MENUBAR_HEIGHT 30
    #define MENUBAR_BTN_MARGIN 10
    #define WINDOW_WIDTH 1920
    #define WINDOW_HEIGHT 1080

typedef struct button_s button_t;
typedef struct global_s global_t;
struct button_s {
    button_t *prev;
    sfRectangleShape *button;
    char *string;
    sfText *text;
    int button_size;
    button_t *next;
    int (*hover_func)(global_t *, void *);
    int (*click_func)(global_t *, void *);
    void *hover_param;
    void *click_param;
};

typedef struct dropdown_menu_s {
    button_t *buttons;
    sfRectangleShape *shape;
    int displayed;
} dropdown_menu_t;

typedef struct menubar_s {
    sfRectangleShape *bar;
    button_t *buttons;
} menubar_t;

typedef struct drawing_s {
    sfVector2f scale;
    sfVector2f spritePos;
    sfColor color;
    sfImage *image;
    sfVector2u textureSize;
    sfVector2i diff;
    int steps;
    sfVector2i interpolatedPos;
} drawing_t;


typedef struct layerbutton_s {
    sfRectangleShape *shape;
    sfTexture *imageTexture;
    sfText *text;
    int selected;
} layerbutton_t;

typedef struct layer_s {
    struct layer_s *prev;
    sfSprite *sprite;
    sfTexture *texture;
    int displayed;
    int selected;
    char *name;
    layerbutton_t *button;
    struct layer_s *next;
} layer_t;

typedef struct pencil_s {
    sfVector2i lastPos;
    sfColor color;
    int size;
    int eraser;
    int pencil;
    int shape;
} pencil_t;

typedef struct popup_s {
    sfRenderWindow *popup;
    sfEvent event;
    button_t *size_buttons[3];
    button_t *color_buttons[10];
    button_t *shape_buttons[2];
    sfColor colors[10];
} popup_t;

struct global_s {
    sfRenderWindow *window;
    sfEvent event;
    menubar_t *menubar;
    sfColor color;
    sfVector2i windowSize;
    layer_t *layers;
    int nb_layers;
    pencil_t *pencil;
};

int my_paint(int ac, char **av);
sfRenderWindow *create_window(unsigned int width, unsigned int height);
void *my_malloc(unsigned int size);
int my_strlen(char const *str);
char *my_strcat(char *dest, char *src);
void my_putstr(char const *str);
char *my_putnbr_in_str(int nb_init);
int my_strcmp(char const *s1, char const *s2);
button_t *initbutton(sfVector2f pos, sfVector2f size, char *text);
menubar_t *initmenubar(int nbbuttons, global_t *global, ...);
int display(global_t *global);
int update(global_t *global);
void display_menubar(sfRenderWindow *window, menubar_t *menubar);
char *my_strdup(char const *src);
dropdown_menu_t *init_dropdown(
    sfVector2f pos, int nbbutton, global_t *global, va_list buttons);
int display_dropdown(global_t *global, void *dropdown_menu);
int check_click_btn(global_t *global, button_t *btn);
int check_hover_btn(global_t *global, button_t *btn);
int check_dropdown_hover(global_t *global, void *dropdown_menu);
dropdown_menu_t *add_dd_menu(global_t *global, char *text, int nbbuttons, ...);
void zoom_in(layer_t *layers, sfVector2i mousePos, int delta);
void zoom_out(layer_t *layers, sfVector2i mousePos, int delta);
void draw_on_layer(global_t *global, sfVector2i mousePos);
void reset_lastpos(global_t *global);
layer_t *initlayers(void);
int my_abs(int nb);
int add_click_func(menubar_t *menubar, char *menu_btn, char *dd_btn,
    int (*func)(global_t *global, void *param));
int close_btn(global_t *global, void *param);
int check_dd_btn(global_t *global, button_t *btn);
int pick_pencil(global_t *global, void *param);
int pick_eraser(global_t *global, void *param);
sfRectangleShape *create_rectangle(sfVector2f position, sfVector2f size);
sfText *create_text(char *str, sfVector2f position, char *fontfile, int size);
int addlayer(global_t *global, void *param);
int removelayer(global_t *global, void *param);
void pencilpopup(global_t *global);
void display_button(sfRenderWindow *window, button_t *button);
void handleevents(popup_t *popup, global_t *global);
void displaybuttons(popup_t *popup);

#endif /* !MY_PAINT_H_ */
