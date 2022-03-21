#include <string.h>
#include <SDL2/SDL.h>

class Piece{
    private:
        char piece_icon;
        SDL_Rect piece_pos;
        SDL_Color icon_color;

    public:
        //Constructor
        Piece(SDL_Rect initial_pos, SDL_Color initial_color);

        //Getters
        char get_piece_icon();
        SDL_Rect get_piece_pos();
        SDL_Color get_piece_color();

        //Setters
        void set_piece_pos(int x, int y);

        //SDL
};




