#include "circle.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CIRCLE_COUNT 100

Color random_color(){
	Color c;
	c.r = rand() % 255;
	c.g = rand() % 255;
	c.b = rand() % 255;
	return c;
}

int is_point_in_circle(int mx, int my, Circle* c){
	double dx = mx - c->x;
	double dy = my - c->y;
	return dx*dx + dy*dy <= c->radius * c->radius;
}

int main(int argc, char* argv[])
{	
	SDL_Init(SDL_INIT_VIDEO);
	srand(time(NULL));

	Screen sc;
	sc.width=1366;
	sc.height=720;
	sc.window = SDL_CreateWindow(
		"Circle drawing",
		SDL_WINDOWPOS_CENTERED,
    	SDL_WINDOWPOS_CENTERED,
		sc.width,
		sc.height,
		0
	);

	//renderer
	sc.renderer = SDL_CreateRenderer(sc.window, -1, SDL_RENDERER_ACCELERATED);

	Circle circles[MAX_CIRCLE_COUNT];
	int circle_count = 0;

	MODE mode = MODE_STEP_COUNT;
	int dragging = -1;
	
	//program
	int running = 1;
	SDL_Event event;

	while (running)
	{	
		while (SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT){
				running = 0;
			}

			if(event.type == SDL_KEYDOWN){
				 printf("KEYDOWN: %d\n", event.key.keysym.sym);
				 printf("mode = %d\n", mode);
				switch(event.key.keysym.sym){
					case SDLK_1: mode = MODE_STEP_COUNT; break;
					case SDLK_2: mode = MODE_ANGLE_STEP; break;
					case SDLK_3: mode = MODE_MAX_SEGMENT; break;
				}
			}

			if(event.type == SDL_MOUSEBUTTONDOWN){
				int mx = event.button.x;
				int my = event.button.y;

				int clicked_on_circle = 0;

				for (int i = 0; i < circle_count; i++)
				{
					if(is_point_in_circle(mx, my, &circles[i])){
						dragging = i;
						clicked_on_circle = 1;
						break;
					}
				}
				
				if(!clicked_on_circle && circle_count < MAX_CIRCLE_COUNT){
					set_circle_data(
						&circles[circle_count],
						mx,
						my,
						30 + (rand() % 100),
						random_color(),
						50,
						0.01,
						5
					);
					circle_count++;
				}	
			}
			
			if(event.type == SDL_MOUSEBUTTONUP){
				dragging = -1;
			}

			if(event.type == SDL_MOUSEMOTION && dragging != -1){
				circles[dragging].x = event.motion.x;
				circles[dragging].y = event.motion.y;
			}
		}
		
		SDL_SetRenderDrawColor(sc.renderer, 0, 62, 74, 255 );
		SDL_RenderClear(sc.renderer);

		int mx, my;
		SDL_GetMouseState(&mx, &my);

		for (int i = 0; i < circle_count; i++)
		{
			draw_circle(&sc, &circles[i], mode);

			if(is_point_in_circle(mx, my, &circles[i])){
				SDL_SetRenderDrawColor(sc.renderer, 255, 0, 0, 255);

				Point p1 = {circles[i].x - 10, circles[i].y};
				Point p2 = {circles[i].x + 10, circles[i].y};
				SDL_RenderDrawLine(sc.renderer, p1.x, p1.y, p2.x, p2.y);

				Point p3 = {circles[i].x , circles[i].y - 10};
				Point p4 = {circles[i].x, circles[i].y + 10};
				SDL_RenderDrawLine(sc.renderer, p3.x, p3.y, p4.x, p4.y);

			}
		}
		
		SDL_RenderPresent(sc.renderer);
	}
	SDL_DestroyRenderer(sc.renderer);
	SDL_DestroyWindow(sc.window);
	SDL_Quit();

	return 0;
}
