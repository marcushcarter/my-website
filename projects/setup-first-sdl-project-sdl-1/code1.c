#include <SDL3/SDL.h>
#include <stdio.h>

SDL_Window* window;
SDL_Renderer* renderer;

int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("main", 800, 600, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, NULL);
	SDL_SetRenderScale(renderer, 1, 1);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_EVENT_QUIT) running = false;
        }
        // run game loop here
    }
    
    return 0;
}
