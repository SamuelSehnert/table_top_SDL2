#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "SDL_Utils.hpp"

class Piece{
    private:
        char piece_icon;
        SDL_Rect piece_pos;
        SDL_Color icon_color;
        //Tester
        SDL_Texture* piece_texture;
        void create_piece_texture();


    public:
        //Constructor
        Piece(SDL_Rect initial_pos, SDL_Color initial_color, char piece_icon);

        //Getters
        char get_piece_icon();
        SDL_Rect get_piece_pos();
        SDL_Color get_piece_color();

        //Setters
        void set_piece_pos(int x, int y);

        //SDL
        void add_to_render();
        void close_texture();
};




