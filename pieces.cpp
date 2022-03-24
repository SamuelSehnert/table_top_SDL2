#include "pieces.hpp"


// ====================== Piece ====================== //

Piece::Piece(SDL_Rect initial_pos, SDL_Color initial_color, char piece_icon){
    this->piece_pos = initial_pos;
    this->icon_color = initial_color;
    this->piece_icon = piece_icon;
    create_piece_texture(); //Sets up the individual texture to render char
    this->onTop = nullptr;
}

//Getters
char Piece::get_piece_icon(){ return this->piece_icon; }
SDL_Rect Piece::get_piece_pos(){ return this->piece_pos; }
SDL_Color Piece::get_piece_color(){ return this->icon_color; }
Piece* Piece::get_on_top(){ return this->onTop; }

//Setters
void Piece::set_piece_pos(int x, int y){
    this->piece_pos.x = x;
    this->piece_pos.y = y;
}
void Piece::set_piece_color(SDL_Color newColor){
    this->icon_color = newColor;
    create_piece_texture();
}
void Piece::set_piece_on_top(Piece* piece){
    this->onTop = piece;
}

//SDL
void Piece::create_piece_texture(){
    char SDL_icon[2];
    SDL_icon[0] = this->piece_icon;
    SDL_icon[1] = '\0';

    SDL_Surface* surface_text = TTF_RenderText_Solid(get_font(), (const char *)SDL_icon, this->get_piece_color());
    this->piece_texture = SDL_CreateTextureFromSurface(get_renderer(), surface_text);
    SDL_FreeSurface(surface_text);
}

void Piece::add_to_render(){
    SDL_Rect shifted_position = this->get_piece_pos();
    shifted_position.x *= ICON_UNIT_SIZE;
    shifted_position.x += 3;
    shifted_position.y *= ICON_UNIT_SIZE;

    SDL_RenderCopy(get_renderer(), this->piece_texture, NULL, &shifted_position);
}

void Piece::close_texture(){
    SDL_DestroyTexture(this->piece_texture);
}


// ====================== Floor ====================== //
Floor::Floor(SDL_Rect initial_pos, SDL_Color initial_color, char piece_icon)
    : Piece(initial_pos, initial_color, piece_icon){
        this->piece_pos = initial_pos;
        this->icon_color = initial_color;
        this->piece_icon = piece_icon;
        create_piece_texture(); //Sets up the individual texture to render char
    }


