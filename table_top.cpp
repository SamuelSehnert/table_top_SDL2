#include <iostream>

#include "SDL_Utils.hpp"
#include "pieces.hpp"
#include "shared.hpp"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define BOARD_WIDTH ICON_UNIT_SIZE * 15
#define BOARD_HEIGHT ICON_UNIT_SIZE * 15

int main(){
    bool quit = false;
    SDL_Event event;
    Player player({0,0, ICON_UNIT_SIZE, ICON_UNIT_SIZE}, {255, 0,0,SDL_ALPHA_OPAQUE});

    initialize_SDL();
    initialize_font();

    create_window(SCREEN_WIDTH, SCREEN_HEIGHT);
    create_renderer();
    create_texture(player.get_player_icon(), player.get_player_color());

    while (!quit){
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT){ //SDL quit includes DWM : alt, shift, c
            quit = true;
        }
        else if (event.type == SDL_KEYDOWN){
            SDL_Keycode key_code = event.key.keysym.sym;
            if (key_code == SDLK_w && player.get_player_pos().y - ICON_UNIT_SIZE >= 0){
                player.set_player_pos(player.get_player_pos().x, player.get_player_pos().y - ICON_UNIT_SIZE);
            }
            if (key_code == SDLK_a && player.get_player_pos().x - ICON_UNIT_SIZE >= 0){
                player.set_player_pos(player.get_player_pos().x - ICON_UNIT_SIZE, player.get_player_pos().y);
            }
            if (key_code == SDLK_s && player.get_player_pos().y + ICON_UNIT_SIZE < BOARD_HEIGHT){
                player.set_player_pos(player.get_player_pos().x, player.get_player_pos().y + ICON_UNIT_SIZE);
            }
            if (key_code == SDLK_d && player.get_player_pos().x + ICON_UNIT_SIZE < BOARD_WIDTH){
                player.set_player_pos(player.get_player_pos().x + ICON_UNIT_SIZE, player.get_player_pos().y);
            }
        }
        clear_render();
        add_player_data_to_render(player.get_player_pos());
        print_grid(BOARD_WIDTH, BOARD_HEIGHT);
        display_rendered_data();
    }
    close_everything();
    return 0;
}

