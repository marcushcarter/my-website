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

        // clear the backround color
        SDL_SetRenderDrawColor(renderer, 0, 0, 128, 255);
        SDL_RenderClear(renderer);

        // draws a red square
        SDL_SetRenderDrawColor(renderer, 128, 0, 0, 255);
        SDL_FRect rect = {250.0f, 250.0f, 50.0f, 50.0f};
        SDL_RenderFillRect(renderer, &rect);

        // draws a cross in the square
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderLine(renderer, 250.0f+50.0f, 250.0f, 250.0f, 250.0f+50.0f);
        SDL_RenderLine(renderer, 250.0f+50.0f, 250.0f+50.0f, 250.0f, 250.0f);

        // draws the curved line
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (float i = 0; i < 600; i+=0.1) {
            SDL_RenderPoint(renderer, i*30, (i*i));
        }

        SDL_RenderPresent(renderer);
    }
    
    return 0;
}
