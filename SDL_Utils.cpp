#include "SDL_Utils.hpp"

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
TTF_Font* font = nullptr;

//Getters
TTF_Font* get_font(){ return font; }
SDL_Renderer* get_renderer(){ return renderer; }

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
    font = TTF_OpenFont("./fonts/Perfect_DOS_VGA_437_Win.ttf", ICON_UNIT_SIZE);
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

void clear_render(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

void display_rendered_data(){
    SDL_RenderPresent(renderer);
}


void close_everything(){
    TTF_CloseFont(font);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void print_grid(int max_width, int max_height){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    for (int i = ICON_UNIT_SIZE; i < max_width; i += ICON_UNIT_SIZE){
        SDL_RenderDrawLine(renderer, i, 0, i, max_height);
    }
    for (int i = ICON_UNIT_SIZE; i < max_height; i += ICON_UNIT_SIZE){
        SDL_RenderDrawLine(renderer, 0, i, max_width, i);
    }
}

void show_floor(int max_width, int max_height){
    const char ch[2] = {'.', '\0'};
    SDL_Surface* floor_text = TTF_RenderText_Solid(font, (const char*)ch, {255,255,255,255}); 
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, floor_text);
    SDL_FreeSurface(floor_text);

    SDL_Rect current_pos;
    current_pos.h = current_pos.w = ICON_UNIT_SIZE;
    current_pos.x = 3;
    current_pos.y = 0;

    for (int i = 0; i < max_height; i += ICON_UNIT_SIZE){
        for (int j = 0; j < max_width; j += ICON_UNIT_SIZE){
            SDL_RenderCopy(get_renderer(), texture, NULL, &current_pos);
            current_pos.x += ICON_UNIT_SIZE;
        }
        current_pos.x = 0;
        current_pos.y += ICON_UNIT_SIZE;
    }
}


