#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdio.h>
// #include <windows.h>
#include <time.h> // to get the current time
#include <unistd.h> // for usleep() -> control_fps function

SDL_Window* window;
SDL_Renderer* renderer;

SDL_Texture* car_texture;

bool load_textures() {

	car_texture = IMG_LoadTexture(renderer, "./resources/car.png");
	SDL_SetTextureScaleMode(car_texture, SDL_SCALEMODE_NEAREST);

	return true;
}

// These variables help us calculate delta time
clock_t previous_time = 0; // stores the time from the last frame
float dt; // will hold the final delta time in seconds

// Function to calculate delta time
// Returns how many seconds passed since the last frame
// Call this once per frame before any movement updates
float get_delta_time() {
    clock_t current_time = clock(); // gives us the number of CPU clock ticks since the program started
    float delta_time = (float)(current_time - previous_time) / CLOCKS_PER_SEC;
	// CLOCKS_PER_SEC is a constant that tells us how many ticks are in one second
	// dividing the difference in ticks by CLOCKS_PER_SEC, we get the time passed between frames (the delta time)
    previous_time = current_time; // save the current time to previous_time so that next frame we can compare it again
    return delta_time;
}

// Function to control the framerate manually
// It delays the next frame until the correct frame time has passed
// keeps your game from running too fast
void control_fps(float target_fps) {
	// Calculate how long each frame should take (in seconds)
	float frame_duration = 1.0f / target_fps;

	// Get the current time at the end of the frame
	clock_t now = clock();

	// Calculate how much time has passed since the frame started
	float elapsed = (float)(now - previous_time) / CLOCKS_PER_SEC;

	// Find out how much time is left to wait to match the desired frame duration
	float remaining_time = frame_duration - elapsed;

	// If the frame finished faster than the desired duration, sleep for the remaining time
	if (remaining_time > 0) {
		// Convert seconds to microseconds and sleep (pause) for that duration
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

    // initialize the car's x variable
    float x = 0;

    bool running = true;
    SDL_Event event;
    while (running) {
        
        dt = get_delta_time();    // get how long the last frame took (at start of the frame)

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_EVENT_QUIT) running = false;
        }

        // clear the renderer
        SDL_RenderClear(renderer);
        
        // update the x position (in the game loop)
        x+=25*dt;; // also can be written as x = x + (1*dt);

        // update the FRect size and add the x variable
        SDL_FRect position = {x, 0, 80, 60};

        SDL_RenderTexture(renderer, car_texture, NULL, &position);

        SDL_RenderPresent(renderer);
        control_fps(120.0f);      // limit FPS to 120 (at end of the frame)
    }
    
    return 0;
}
