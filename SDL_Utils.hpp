#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define SCREEN_NAME "Table Top"

void initialize_SDL();
void initialize_font();
void create_window(int w, int h);
void create_renderer();
void create_texture(const char icon, SDL_Color color);
void display_rendered_data();
void close_everything();
