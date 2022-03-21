#include "SDL_Utils.hpp"

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Texture* texture = nullptr;
TTF_Font* font = nullptr;

SDL_Rect char_rect = {0,0,32,32};

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

void initialize_font(){
    font = TTF_OpenFont("./fonts/8bitoperator_JVE_Regular.ttf", 32);
    if (font == nullptr){
        std::cout << "Error loading Font: " << TTF_GetError() << std::endl;
        exit(1);
    }
}

void create_window(int w, int h){
    window = SDL_CreateWindow(
        SCREEN_NAME,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        w,
        h,
        SDL_WINDOW_OPENGL
        );
    if (window == nullptr){
        std::cout << "Error creating window: " << TTF_GetError() << std::endl;
        exit(1);
    }
}

void create_renderer(){
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr){
        std::cout << "Error creating renderer: " << TTF_GetError() << std::endl;
        exit(1);
    }
}

void create_texture(const char icon, SDL_Color color){
    char SDL_icon[2];
    SDL_icon[0] = icon; 
    SDL_icon[1] = '\0'; 

    SDL_Surface* surfaceText = TTF_RenderText_Solid(font, (const char*)SDL_icon, color);
    texture = SDL_CreateTextureFromSurface(renderer, surfaceText);
    SDL_FreeSurface(surfaceText);
}

void clear_render(){
    SDL_SetRenderDrawColor(renderer, 0, 0,0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

void add_player_data_to_render(SDL_Rect player_position){
    SDL_RenderCopy(renderer, texture, NULL, &player_position);
}

void display_rendered_data(){
    SDL_RenderPresent(renderer);
}


void close_everything(){
    TTF_CloseFont(font);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


