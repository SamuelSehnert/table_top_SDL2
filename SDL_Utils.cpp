#include "SDL_Utils.hpp"

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Texture* texture = nullptr;
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
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

void add_player_data_to_render(SDL_Rect player_position){
    //We shift the position so that the Icon is in the middle of the grid
    SDL_Rect shifted_position;
    shifted_position.h = player_position.h;
    shifted_position.w = player_position.w;
    shifted_position.x = player_position.x + 3;
    shifted_position.y = player_position.y;
    SDL_RenderCopy(renderer, texture, NULL, &shifted_position);
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

void print_grid(int max_width, int max_height){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    for (int i = 32; i < max_width; i += 32){
        SDL_RenderDrawLine(renderer, i, 0, i, max_height);
    }
    for (int i = 32; i < max_height; i += 32){
        SDL_RenderDrawLine(renderer, 0, i, max_width, i);
    }
}

