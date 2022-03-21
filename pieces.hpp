#include <string.h>
#include <SDL2/SDL.h>

//class Piece{
//    protected:
//        char piece_icon;
//        SDL_Color icon_color;
//        SDL_Rect piece_pos;
//    public:
//        //Constructor
//        Piece(SDL_Rect initial_pos, SDL_Color initial_color);
//
//        //Getters
//        char get_piece_icon();
//        SDL_Rect get_piece_pos();
//        SDL_Color get_piece_color();
//
//        //Setters
//        void set_piece_pos(int x, int y);
//
//        //SDL
//};
//
//class Player : public Piece {
//    public:
//        using Piece::Piece;
//};

class Player{
    private:
        char player_icon;
        SDL_Rect player_pos;
        SDL_Color icon_color;

    public:
        //Constructor
        Player(SDL_Rect initial_pos, SDL_Color initial_color);

        //Getters
        char get_player_icon();
        SDL_Rect get_player_pos();
        SDL_Color get_player_color();

        //Setters
        void set_player_pos(int x, int y);

        //SDL
};




