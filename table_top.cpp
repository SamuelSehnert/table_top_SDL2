#include <iostream>
#include <vector>

#include "SDL_Utils.hpp"
#include "pieces.hpp"
#include "shared.hpp"

#define MAX_PIECES 3

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define BOARD_HEIGHT_UNITS 30
#define BOARD_WIDTH_UNITS 30

#define BOARD_WIDTH ICON_UNIT_SIZE * BOARD_WIDTH_UNITS
#define BOARD_HEIGHT ICON_UNIT_SIZE * BOARD_HEIGHT_UNITS

#define SIDEBAR_WIDTH SCREEN_WIDTH - BOARD_WIDTH

#define PIECE_HOLD_SIDE_BAR_HEIGHT ICON_UNIT_SIZE
#define PIECE_HOLD_SIDE_BAR_WIDTH ICON_UNIT_SIZE * MAX_PIECES
#define PIECE_HOLD_SIDE_BAR_X_START SIDEBAR_WIDTH + (SIDEBAR_WIDTH / 2) - (ICON_UNIT_SIZE * MAX_PIECES / 2)
#define PIECE_HOLD_SIDE_BAR_Y_START ICON_UNIT_SIZE * 3


std::vector<Floor> floor_vector;
std::vector<Piece> piece_vector;

void init_floor(int max_width, int max_height){
    SDL_Rect current_pos;
    current_pos.h = current_pos.w = ICON_UNIT_SIZE;
    current_pos.x = 0;
    current_pos.y = 0;

    for (int i = 0; i < max_height; i += 1){
        for (int j = 0; j < max_width; j += 1){
            Floor floor(current_pos, {255,255,255,255});
            floor_vector.push_back(floor);
            current_pos.x += 1;
        }
        current_pos.x = 0;
        current_pos.y += 1;
    }
}

void add_all_to_renderer(){
    for (Floor& floor : floor_vector){
        Piece* piece = &floor;
        while (piece->get_on_top() != nullptr){
            piece = piece->get_on_top();
        }
        if (piece == nullptr){
            floor.add_to_render();
        }
        else{
            piece->add_to_render();
        }
    }
}

void pop_off_top(Floor* floor){
    Piece* piece = floor;
    while (piece->get_on_top() != nullptr && piece->get_on_top()->get_on_top() != nullptr){
        piece = piece->get_on_top();
    }
    piece->set_piece_on_top(nullptr);
}

void add_to_top(Floor* floor, Piece* to_place){
    Piece* piece = floor;
    while (piece->get_on_top() != nullptr){
        piece = piece->get_on_top();
    }
    piece->set_piece_on_top(to_place);
}

void set_up_pieces_on_hold(){

}

void show_pieces_on_hold(){
    for (Piece& piece : piece_vector){
//        std::cout << "id: " << piece.get_piece_icon() << std::endl;
        piece.add_to_render();
    }
}

int main(){
    bool quit = false;
    SDL_Event event;

    initialize_SDL();
    initialize_font();

    create_window(SCREEN_WIDTH, SCREEN_HEIGHT);
    create_renderer();

    init_floor(BOARD_WIDTH_UNITS, BOARD_HEIGHT_UNITS);

    SDL_Rect side_bar;
    side_bar.h = BOARD_HEIGHT;
    side_bar.w = SIDEBAR_WIDTH;
    side_bar.x = BOARD_WIDTH;
    side_bar.y = 0;

    SDL_Rect piece_holder_side_bar;
    piece_holder_side_bar.h = PIECE_HOLD_SIDE_BAR_HEIGHT;
    piece_holder_side_bar.w = PIECE_HOLD_SIDE_BAR_WIDTH;
    piece_holder_side_bar.x = PIECE_HOLD_SIDE_BAR_X_START;
    piece_holder_side_bar.y = PIECE_HOLD_SIDE_BAR_Y_START;

    Soldier soldier1({32,32,0,0}, {0, 255, 255, 255});
    Piece piece({32,32,0,1},{0,255,0,255});
    piece_vector.push_back(soldier1);
    floor_vector.at(5 + 5 * BOARD_WIDTH_UNITS).set_piece_on_top(&soldier1);
    floor_vector.at(0 + 1 * BOARD_WIDTH_UNITS).set_piece_on_top(&piece);

    while (!quit){
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT){ //SDL quit includes DWM : alt, shift, c
            quit = true;
        }
        else if (event.type == SDL_KEYDOWN){
            SDL_Keycode key_code = event.key.keysym.sym;
            if (key_code == SDLK_ESCAPE){
                break;
            }
       }
        clear_render();
        SDL_SetRenderDrawColor(get_renderer(), 0, 0, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawRect(get_renderer(), &side_bar);
        SDL_RenderDrawRect(get_renderer(), &piece_holder_side_bar);
        show_pieces_on_hold();
        add_all_to_renderer();
        display_rendered_data();
    }
    close_everything();
    for (Floor& floor : floor_vector){
        floor.close_texture();
    }
    for (Piece& piece : piece_vector){
        piece.close_texture();
    }
    return 0;
}

