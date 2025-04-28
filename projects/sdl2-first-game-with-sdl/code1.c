#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdio.h>

SDL_Window* window;
SDL_Renderer* renderer;

// The place our shrek texture will go
SDL_Texture* shrek_texture;

bool load_textures() {

    // Loading our shrek texture
	shrek_texture = IMG_LoadTexture(renderer, "./resources/shrek.png");
	SDL_SetTextureScaleMode(shrek_texture, SDL_SCALEMODE_NEAREST);

	return true;
}

int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("main", 800, 600, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, NULL);
	SDL_SetRenderScale(renderer, 1, 1);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // load texture function
    load_textures();

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_EVENT_QUIT) running = false;
        }

        // put the shrek texture on the renderer
        SDL_FRect position = {0, 0, 800, 600};
        SDL_RenderTexture(renderer, shrek_texture, NULL, &position);

        SDL_RenderPresent(renderer);
    }
    
    return 0;
}
