#include <string.h>

#include <SDL2/SDL.h>

class Player{
    private:
        char player_icon = '@';
        SDL_Rect player_pos;
        SDL_Color icon_color;

    public:
        //Constructor
        Player(SDL_Rect initial_pos, SDL_Color initial_color){
            this->player_pos = initial_pos;
            this->icon_color = initial_color;
        }

        //Getters
        char get_player_icon(){ return this->player_icon; }
        SDL_Rect get_player_pos(){ return this->player_pos; }
        SDL_Color get_player_color(){ return this->icon_color; }

        //Setters
};
