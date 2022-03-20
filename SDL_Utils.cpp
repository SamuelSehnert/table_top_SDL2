#include "SDL_Utils.hpp"

TTF_Font* font = nullptr;

void initialize_SDL(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Error in the init phase: " << SDL_GetError() << std::endl;
        exit(1);
    } 
    if (TTF_Init() < 0){
        std::cout << "Error in the TTF init phase: " << TTF_GetError() << std::endl;
        exit(1);
    }
}

TTF_Font* initialize_font(){
    font = TTF_OpenFont("./fonts/8bitoperator_JVE_Regular.ttf", 32);
    if (font == nullptr){
        std::cout << "Error loading Font: " << TTF_GetError() << std::endl;
        exit(1);
    }
    return font;
}
