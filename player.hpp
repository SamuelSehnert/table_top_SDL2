#include <string.h>
#include <SDL2/SDL.h>

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
};
