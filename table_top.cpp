#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "SDL_Utils.hpp"

#define SCREEN_NAME "Table Top"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MOVE_SIZE 20;

int main(){
    SDL_Window* window = nullptr; 
    SDL_Renderer* renderer = nullptr;
    SDL_Event event;
    
    bool quit = false;

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.h = 32;
    rect.w = 32;

    initialize_SDL();

    window = SDL_CreateWindow(
        SCREEN_NAME,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_OPENGL
    );

    TTF_Font* font = initialize_font();

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //Testing purposes
    const char test = '@';
    SDL_Surface* surfaceText = TTF_RenderText_Solid(font, &test, {255, 0, 0, 255});
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surfaceText);
    SDL_FreeSurface(surfaceText);

    if (window == NULL){
        std::cout << "Window not created: error = " << SDL_GetError() << std::endl;
        exit(1);
    }

    while (!quit){
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT){ //SDL quit includes DWM : alt, shift, c
            quit = true;
        }
        else if (event.type == SDL_KEYDOWN){
            SDL_Keycode key_code = event.key.keysym.sym;
            if (key_code == SDLK_w){
                rect.y -= SCREEN_HEIGHT / MOVE_SIZE;
            }
            if (key_code == SDLK_a){
                rect.x -= SCREEN_WIDTH / MOVE_SIZE;
            }
            if (key_code == SDLK_s){
                rect.y += SCREEN_HEIGHT / MOVE_SIZE;
            }
            if (key_code == SDLK_d){
                rect.x += SCREEN_WIDTH / MOVE_SIZE;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, texture, NULL, &rect);

        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

