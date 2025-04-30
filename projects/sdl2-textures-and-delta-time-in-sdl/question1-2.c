#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

SDL_Window* window;
SDL_Renderer* renderer;

SDL_Texture* car_texture1;
SDL_Texture* car_texture2;

bool load_textures() {

	car_texture1 = IMG_LoadTexture(renderer, "./resources/car1.png");
	SDL_SetTextureScaleMode(car_texture1, SDL_SCALEMODE_NEAREST);

    car_texture2 = IMG_LoadTexture(renderer, "./resources/car2.png");
	SDL_SetTextureScaleMode(car_texture2, SDL_SCALEMODE_NEAREST);

	return true;
}

clock_t previous_time = 0;
float dt;

float get_delta_time() {
    clock_t current_time = clock();
    float delta_time = (float)(current_time - previous_time) / CLOCKS_PER_SEC;
    previous_time = current_time;
    return delta_time;
}

void control_fps(float target_fps) {
	float frame_duration = 1.0f / target_fps;
	clock_t now = clock();
	float elapsed = (float)(now - previous_time) / CLOCKS_PER_SEC;
	float remaining_time = frame_duration - elapsed;
	if (remaining_time > 0) {
		usleep((useconds_t)(remaining_time * 1000000.0f));
	}
}

int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("main", 800, 600, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, NULL);
	SDL_SetRenderScale(renderer, 1, 1);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    load_textures();

    // initialize both car's x variable
    float x1 = 0;
    float x2 = 0;

    bool running = true;
    SDL_Event event;
    while (running) {
        
        dt = get_delta_time();

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_EVENT_QUIT) running = false;
        }

        SDL_RenderClear(renderer);
        
        x1+=25*dt;
        x2+=40*dt;

        // update the FRect size and add the x variable
        SDL_FRect position1 = {x1, 0, 80, 60};
        SDL_FRect position2 = {x2, 150, 80, 60};

        SDL_RenderTexture(renderer, car_texture1, NULL, &position1);
        SDL_RenderTexture(renderer, car_texture2, NULL, &position2);

        SDL_RenderPresent(renderer);
        control_fps(120.0f);
    }
    
    return 0;
}
