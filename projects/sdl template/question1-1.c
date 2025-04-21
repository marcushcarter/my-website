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
        
        // clear the backround color
        SDL_SetRenderDrawColor(renderer, 0, 0, 128, 255);
        SDL_RenderClear(renderer);

        // draws a triangle in the middle of the screen
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderLine(renderer, 300.0f, 400.0f, 400.0f, 200.0f);   // bottom left point
        SDL_RenderLine(renderer, 400.0f, 200.0f, 500.0f, 400.0f);   // middle point
        SDL_RenderLine(renderer, 300.0f, 400.0f, 500.0f, 400.0f);   // bottom right point

        SDL_RenderPresent(renderer);
    }
    
    return 0;
}
