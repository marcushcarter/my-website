#include <SDL3/SDL.h>
#include <stdio.h>
#include <math.h>

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

        // draws a circle around point (400, 300)
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        float r = 200; // radius in px
        for(float i = 0; i < 2 * M_PI; i+=0.01) {
            SDL_RenderPoint(renderer, 400.0f+sin(i)*r, 300.0f+cos(i)*r);
        }

        SDL_RenderPresent(renderer);
    }
    
    return 0;
}
