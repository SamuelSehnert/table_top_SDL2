#include <iostream>
#include <vector>

#include "SDL_Utils.hpp"
#include "pieces.hpp"
#include "shared.hpp"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define BOARD_HEIGHT_UNITS 30
#define BOARD_WIDTH_UNITS 30

#define BOARD_WIDTH ICON_UNIT_SIZE * BOARD_WIDTH_UNITS
#define BOARD_HEIGHT ICON_UNIT_SIZE * BOARD_HEIGHT_UNITS

#define SIDEBAR_WIDTH  SCREEN_WIDTH - BOARD_WIDTH

std::vector<Floor> floor_vector;

void init_floor(int max_width, int max_height){
    SDL_Rect current_pos;
    current_pos.h = current_pos.w = ICON_UNIT_SIZE;
    current_pos.x = 0;
    current_pos.y = 0;

    for (int i = 0; i < max_height; i += 1){
        for (int j = 0; j < max_width; j += 1){
            Floor floor(current_pos, {255,255,255,255}, '.');
            floor_vector.push_back(floor);
            current_pos.x += 1;
        }
        current_pos.x = 0;
        current_pos.y += 1;
    }
}



int main(){
    bool quit = false;
    SDL_Event event;

    initialize_SDL();
    initialize_font();

    create_window(SCREEN_WIDTH, SCREEN_HEIGHT);
    create_renderer();

    Piece player({0,0, ICON_UNIT_SIZE, ICON_UNIT_SIZE}, {255, 0, 0, SDL_ALPHA_OPAQUE}, '@');
    Piece enemy({1,0, ICON_UNIT_SIZE, ICON_UNIT_SIZE}, {255, 0, 0, SDL_ALPHA_OPAQUE}, 'T');

    SDL_Rect side_bar;
    side_bar.h = BOARD_HEIGHT;
    side_bar.w = SIDEBAR_WIDTH;
    side_bar.x = BOARD_WIDTH;
    side_bar.y = 0;

    init_floor(BOARD_WIDTH_UNITS, BOARD_HEIGHT_UNITS);

    std::cout << "here" << std::endl;

    while (!quit){
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT){ //SDL quit includes DWM : alt, shift, c
            quit = true;
        }
        else if (event.type == SDL_KEYDOWN){
            SDL_Keycode key_code = event.key.keysym.sym;
            if (key_code == SDLK_w && player.get_piece_pos().y - 1 >= 0){
                player.set_piece_pos(player.get_piece_pos().x, player.get_piece_pos().y - 1);
            }
            if (key_code == SDLK_a && player.get_piece_pos().x - 1 >= 0){
                player.set_piece_pos(player.get_piece_pos().x - 1, player.get_piece_pos().y);
            }
            if (key_code == SDLK_s && player.get_piece_pos().y + 1 < BOARD_WIDTH_UNITS){
                player.set_piece_pos(player.get_piece_pos().x, player.get_piece_pos().y + 1);
            }
            if (key_code == SDLK_d && player.get_piece_pos().x + 1 < BOARD_WIDTH_UNITS){
                player.set_piece_pos(player.get_piece_pos().x + 1, player.get_piece_pos().y);
            }
        }
        clear_render();
        SDL_SetRenderDrawColor(get_renderer(), 0, 0, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawRect(get_renderer(), &side_bar);
        //show_floor(BOARD_WIDTH, BOARD_HEIGHT);
        player.add_to_render();
        enemy.add_to_render();
        for (Floor& floor : floor_vector) {
            floor.add_to_render();
        }
        display_rendered_data();
    }
    close_everything();
    player.close_texture();
    enemy.close_texture();
    for (Floor& floor : floor_vector){
        floor.close_texture();
    }
    return 0;
}

