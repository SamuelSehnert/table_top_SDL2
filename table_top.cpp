#include <iostream>

#include "SDL_Utils.hpp"
#include "player.hpp"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MOVE_SIZE 20;

int main(){
    bool quit = false;
    SDL_Event event;
    Player player({0,0,32,32}, {255, 0,0,SDL_ALPHA_OPAQUE});

    initialize_SDL();
    initialize_font();

    create_window(SCREEN_WIDTH, SCREEN_HEIGHT);
    create_renderer();

    create_texture(player.get_player_icon(), player.get_player_color());

    //Testing purposes
    while (!quit){
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT){ //SDL quit includes DWM : alt, shift, c
            quit = true;
        }
        else if (event.type == SDL_KEYDOWN){
            SDL_Keycode key_code = event.key.keysym.sym;
            if (key_code == SDLK_w){
                //rect.y -= SCREEN_HEIGHT / MOVE_SIZE;
            }
            if (key_code == SDLK_a){
                //rect.x -= SCREEN_WIDTH / MOVE_SIZE;
            }
            if (key_code == SDLK_s){
                //rect.y += SCREEN_HEIGHT / MOVE_SIZE;
            }
            if (key_code == SDLK_d){
                //rect.x += SCREEN_WIDTH / MOVE_SIZE;
            }
        }
        display_rendered_data();
    }
    close_everything();
    return 0;
}

