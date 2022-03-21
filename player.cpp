#include "player.hpp"

Player::Player(SDL_Rect initial_pos, SDL_Color initial_color){
    this->player_pos = initial_pos;
    this->icon_color = initial_color;
    this->player_icon = '@';
}

//Getters
char Player::get_player_icon(){ return this->player_icon; }
SDL_Rect Player::get_player_pos(){ return this->player_pos; }
SDL_Color Player::get_player_color(){ return this->icon_color; }

//Setters
void Player::set_player_pos(int x, int y){
    this->player_pos.x = x;
    this->player_pos.y = y;
}

//SDL