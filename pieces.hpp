#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "shared.hpp"
#include "SDL_Utils.hpp"

class Piece{
    protected:
        char piece_icon;
        SDL_Rect piece_pos;
        SDL_Color icon_color;
        SDL_Texture* piece_texture;
        void create_piece_texture();

        Piece* onTop; // will act like a linked list to show what pieces are on top of others

    public:
        //Constructor
        Piece(SDL_Rect initial_pos, SDL_Color initial_color);

        //Getters
        char get_piece_icon();
        SDL_Rect get_piece_pos();
        SDL_Color get_piece_color();
        Piece* get_on_top();

        //Setters
        void set_piece_pos(int x, int y);
        void set_piece_color(SDL_Color new_color);
        void set_piece_on_top(Piece* piece);

        //SDL
        void add_to_render();
        void close_texture();
};

//Active Pieces
class Soldier : public Piece{
    private:
        int health;
        int attack_range;
        int movement_range;
    public:
        //Constructor
        Soldier(SDL_Rect initial_pos, SDL_Color initial_color);

        //Getters
        int get_health(){ return this->health; }
        int get_attack_range(){ return this->attack_range; }
        int get_movement_range(){ return this->movement_range; }
};

//Environmental Pieces
class Floor : public Piece{
    public:
        Floor(SDL_Rect initial_pos, SDL_Color initial_color);
};


