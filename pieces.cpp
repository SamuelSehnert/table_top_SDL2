#include "pieces.hpp"


// ====================== Piece ====================== //

Piece::Piece(SDL_Rect initial_pos, SDL_Color initial_color){
    this->piece_pos = initial_pos;
    this->icon_color = initial_color;
    this->piece_icon = '@';
}

//Getters
char Piece::get_piece_icon(){ return this->piece_icon; }
SDL_Rect Piece::get_piece_pos(){ return this->piece_pos; }
SDL_Color Piece::get_piece_color(){ return this->icon_color; }

//Setters
void Piece::set_piece_pos(int x, int y){
    this->piece_pos.x = x;
    this->piece_pos.y = y;
}

//SDL
