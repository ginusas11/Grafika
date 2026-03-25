#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_COUNT 100

typedef struct{
    Uint8 r, g, b;
} Color;

typedef struct{
    int startX;
    int startY;
    int endX;
    int endY;
    Color color;
} Line;

int main(int argc, char *argv[]){

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
      "Line drawer",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      1000, 800,
      0
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Line lines[MAX_LINE_COUNT];
    int lineCount = 0;

   bool running = true;
   SDL_Event event;

   int clickCount = 0;
   int tempX, tempY;

   bool clickedOnPalette = false;

   Color currentColor = {255,255,255};

   Color paletteColors[3] = {
        {255, 0, 0}, //red
        {0,255,0},  //green
        {0,0,255}   //blue
    };

    SDL_Rect paletteRects[3] = {
        {10,10,30,30},
        {50,10,30,30},
        {90,10,30,30},
    };

    


   while(running){
        while(SDL_PollEvent(&event)){
           if(event.type == SDL_QUIT){
            running = false;
           }

           if(event.type == SDL_MOUSEBUTTONDOWN){
                int x = event.button.x;
                int y = event.button.y;
                /*
                printf("x: %d, y: %d", x, y);
                */
                clickedOnPalette = false;

                for (int i = 0; i < 3; i++) {
                    if (x >= paletteRects[i].x && x <= paletteRects[i].x + paletteRects[i].w
                    && y >= paletteRects[i].y && y <= paletteRects[i].y + paletteRects[i].h) {
                            currentColor = paletteColors[i];
                            printf("Color changed!\n");
                            clickedOnPalette = true;
                            clickCount=0;
                            break;
                    }
                }
            if(!clickedOnPalette){
                if(clickCount == 0){
                    tempX=x;
                    tempY=y;
                    clickCount=1;
                } else {
                    if(lineCount < MAX_LINE_COUNT){
                        lines[lineCount].startX = tempX;
                        lines[lineCount].startY = tempY;
                        lines[lineCount].endX = x;
                        lines[lineCount].endY = y;
                        lines[lineCount].color = currentColor;
                        lineCount++;
                        clickCount=0;
                        printf("lineCount = %d\n", lineCount);

                    }
                    
                }
            }
                
           } 
        }

        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);

        for(int i = 0; i < 3; i++){
            SDL_SetRenderDrawColor(renderer, paletteColors[i].r, paletteColors[i].g, paletteColors[i].b, 255);
            SDL_RenderFillRect(renderer, &paletteRects[i]);
        }

        for(int i = 0; i < lineCount; i++){
            SDL_SetRenderDrawColor(renderer, lines[i].color.r, lines[i].color.g, lines[i].color.b, 255);
            SDL_Rect r;
            r.x = (lines[i].startX < lines[i].endX) ? lines[i].startX : lines[i].endX;
            r.y = (lines[i].startY < lines[i].endY) ? lines[i].startY : lines[i].endY;
            r.w = abs(lines[i].endX - lines[i].startX);
            r.h = abs(lines[i].endY - lines[i].startY);
            if(r.w < 10){r.w=10;};
            if(r.h < 10){r.h=10;};
            printf("w=%d h=%d\n", r.w, r.h);

            SDL_RenderDrawRect(renderer, &r);
            SDL_RenderFillRect(renderer, &r);

        }
        SDL_RenderPresent(renderer);

   }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}