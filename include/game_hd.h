/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __created by Magalie Vandenbriele__
*/

#ifndef GAME_DEFENDER
#define GAME_DEFENDER

#ifndef READ_SIZE
#define READ_SIZE (128)
#endif

typedef struct info_fight {
    int damage;
    int range[4];
} info_fight_t;

typedef struct node {
    object_t object;
    int type;
    int lvl;
    object_t *attak;
    info_fight_t fight;
    int way[4];
    sfVector2f init;
    sfVector2f range;
    sfVector2f vectf;
    struct node *next;
    struct node *prev;
} node_t;

typedef struct link {
    anim_t anim;
    anim_t *anim_tab;
    sfVector2f pos;
    sfIntRect rect;
    object_t *hey;
    int type;
    int life;
    bool display;
    sfClock *clock;
    sfTime time;
    float speed;
    struct link *next;
    struct link *prev;
} link_t;

typedef struct list {
    node_t *first;
    node_t *end;
} list_t;

    //DISPLAY
typedef struct line {
    sfVector2i a;
    sfVector2i b;
}line_t;

typedef struct moove {
    char moove;
    int bol;
    sfIntRect corner;
} moove_t;

typedef struct path {
    my_button_t *place;
    moove_t *moove;
} path_t;

typedef struct game_play {
    link_t *monster;
    node_t *node;
    object_t *castle;
    link_t *link;
    int life;
    moove_t *mvt;
    sfClock **cl;
    path_t tmp;
} game_play_t;

    //ANIM
        //Anim_fire
char **create_tab_fire(sfVector2f, char *, int, int);
sfVector2f found_pos(my_button_t *, game_t);
link_t *add_link_on_list(link_t *, event_game_t *, game_t, my_button_t *);
link_t *create_link_fire(link_t *, event_game_t *, game_t, my_button_t *);
void draw_fire(link_t *, game_t);

        //Anim_monster
object_t *add_life_monster(sfVector2f);
anim_t *create_mstr(game_t, moove_t *);
link_t *create_link_monster(link_t *, event_game_t *, game_t, moove_t *);
link_t *add_monster(link_t *, event_game_t *, game_t, game_play_t);

        //Attaque_ini
object_t *ini_attaque(sfVector2f, int);
node_t *ini_path(node_t *, moove_t *, int *, float);
node_t *found_attaque_path(node_t *, moove_t *);
object_t *create_attaq(node_t *, sfVector2f, int, moove_t *);

        //Attaque
void try_down(node_t *, int);
node_t *reini_node(node_t *, int);
void moove_attak(node_t *, game_t);
void display_attaque(node_t *, game_t, sfClock *);

        //Moove_monster
void draw_life(link_t *, game_t);
void draw_monster(link_t *, game_t, sfClock *);
link_t *moove_anim_monster(link_t *, moove_t *, sfVector2f);
link_t *moove_monster(link_t *, char **, moove_t *, sfClock *);

        //Mvt_monster
link_t *mvt_monster(link_t *, moove_t *, sfVector2f, bool);
link_t *on_function(moove_t *, int, sfVector2f, link_t *);
link_t *loop_affect(moove_t *, link_t *, int *, sfVector2f);
int check_button_game(my_button_t *butt, sfRenderWindow *window);

        //Touch_monster
void verify_touch(link_t *, node_t *);
void is_monster_touch(link_t *, node_t *);

    //DISPLAY
        //Back_ground
object_t *create_place_object(object_t *, char const *, char *, game_t *);
int ini_back_game(game_t, event_game_t);
my_button_t *create_road(void);

        //Display_game
void draw_all_anim(game_t, link_t *, link_t *, sfClock *);
void display_element(game_t, my_button_t **, object_t *, event_game_t);
void display_text(game_t, event_game_t *, sfClock *, node_t *);
void print_tower(node_t *, game_t);
void display_object_after_mouse(event_game_t *, game_t, object_t **, sfClock *);

        //Display
void display_font_game(object_t **, int, int, game_t);
void display_object(object_t *, game_t);
void use_button(game_t, event_game_t *);
void display_background(game_t, object_t **, event_game_t, my_button_t **);

        //Pause_menu
bool pause_loop(game_t, my_button_t *, int *);
void display_pause_menu(game_t *, event_game_t *, object_t, my_button_t *);

    //EVENT
        //Create_all_object
my_button_t **create_all_button(char *, read_t);

        //End_Game
int castle_dead(int *, moove_t *, link_t *);
int all_monster_died(link_t *, event_game_t);
void event_end(game_t, my_button_t *);
void display_end(int, game_t, object_t);

        //Event_game
sfVector2i check_pos_mouse(sfRenderWindow *);
void event_to_quit_game(game_t *, event_game_t *, my_button_t **, object_t);
link_t *create_link(link_t *, event_game_t *, game_t, my_button_t *);
node_t *create_tower(node_t *, event_game_t *, path_t, char **);
bool on_rect(sfIntRect, sfVector2f, int, int);

        //Fire_path
moove_t *remove_fire_path(link_t *, moove_t *);
moove_t *place_fire_path(link_t *, moove_t *);

    //OBJECT
        //Castle
object_t *create_castle(void);
void win_money(event_game_t *);

        //Create_tab_object
my_button_t *create_button_tab(char *, char *, read_t, sfVector2f);
object_t **tab_game(object_t **, char **, game_t *);
object_t **on_tab(object_t **, char **, int *);

        //Link
node_t *add_node(object_t, int *, sfVector2f, moove_t *);
void connect_links(node_t *, node_t *, link_t *, link_t *);
node_t *one_link(node_t *, char **, event_game_t *, my_button_t *);
node_t *no_link(node_t *, char **, event_game_t *, path_t);
node_t *empire_list(node_t *, char **, event_game_t *, path_t);

        //Node
link_t *add_link(link_t *, anim_t, int, anim_t *);

        //Tower_display
object_t lvl_up_tower(int *, sfVector2f, char **, event_game_t *);
void what_tower(int, object_t *, game_t, sfClock *);
int if_tower_support(game_t, my_button_t *, event_game_t *);
int tower_to_list(game_t, event_game_t *);

    //PATH
        //Assign_path
moove_t *follow_path(moove_t *, int *, char **);
int verify_end(char **, int, int);
moove_t *assign_moovt_path(moove_t *);
        //Found_path
sfIntRect assign_moove(int, int, sfIntRect);
sfVector2f found_pos_path(char **, int *, bool *);
int found_moove(int, int, int, int);
void found_start(int *, int *, char **);
moove_t *found_path(char **);

    //TEXT_GAME
        //Score
char *reverse_str(char const *);
void number_of_digit(int, int *);
char *nb_to_string(int, char *, int);
void up_score(sfClock *, event_game_t *, game_t);
void put_nb_on_screen(int, game_t, sfVector2f, int);

        //Text_create
sfText *text_create(char const *, int, int, sfFont *);
sfText *text_creation(char **, int, sfColor, sfVector2f);
int create_text(char **, text_t *);

    //DESTROY
void destroy_doub_tab(char **);
void destroy_obj(object_t *);
void destroy_menu(game_t, object_t *, object_t);

    //GNL
char *get_next_line(int);

    //INIT_GAME_BORDER
int alloc_place_board(object_t **, read_t *, char *);
char **read_doub_file(char const *);

//ptr.function
int found_menu_ad(game_t, int);

int option(game_t *);
void test_building(game_t, event_game_t *);
#endif
