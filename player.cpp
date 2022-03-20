#include "player.hpp"

class Player{
    private:
        char playerIcon = '@';

    public:
        char get_player_icon(){
            return this->playerIcon;
        }
};
