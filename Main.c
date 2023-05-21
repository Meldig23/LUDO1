#include <SDL.h>

void drawRectangle(SDL_Renderer* renderer, int x, int y, int width, int height)
{
    SDL_Rect rect = { x, y, width, height };
    SDL_RenderFillRect(renderer, &rect);
}

void drawCircle(SDL_Renderer* renderer, int centerX, int centerY)
{
    int radius = 13;

    for (int y = -radius; y <= radius; ++y) 
    {
        for (int x = -radius; x <= radius; ++x) 
        {
            if (x * x + y * y <= radius * radius) 
            {
                SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
            }
        }
    }
}

void renderBoard(SDL_Renderer* renderer) 
{
    //entry line red
    SDL_SetRenderDrawColor(renderer, 128, 0, 0, 255);
    drawRectangle(renderer, 32, 192, 32, 32);//single box
    drawRectangle(renderer, 32, 224, 160, 32);//long box
    //entry line blue
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    drawRectangle(renderer, 224, 32, 32, 160);//long box
    drawRectangle(renderer, 256, 32, 32, 32);//single box
    //entry line yellow
    SDL_SetRenderDrawColor(renderer, 255, 102, 19, 255);
    drawRectangle(renderer, 288, 224, 160, 32);//long box
    drawRectangle(renderer, 416, 256, 32, 32);//single box
    //entry line green
    SDL_SetRenderDrawColor(renderer, 0, 51, 0, 255);
    drawRectangle(renderer, 224, 288, 32, 160);//long line
    drawRectangle(renderer, 192, 416, 32, 32);//single box

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color

    SDL_RenderDrawLine(renderer, 480, 0, 480, 480);

    SDL_RenderDrawLine(renderer, 192, 0, 192, 480);
    SDL_RenderDrawLine(renderer, 288, 0, 288, 480);
    SDL_RenderDrawLine(renderer, 0, 192, 480, 192);
    SDL_RenderDrawLine(renderer, 0, 288, 480, 288);

    SDL_RenderDrawLine(renderer, 224, 0, 224, 192);
    SDL_RenderDrawLine(renderer, 256, 0, 256, 192);
    SDL_RenderDrawLine(renderer, 224, 288, 224, 480);
    SDL_RenderDrawLine(renderer, 256, 288, 256, 480);

    SDL_RenderDrawLine(renderer, 0, 224, 192, 224);
    SDL_RenderDrawLine(renderer, 0, 256, 192, 256);
    SDL_RenderDrawLine(renderer, 288, 224, 480, 224);
    SDL_RenderDrawLine(renderer, 288, 256, 480, 256);

    for (int i = 1; i <= 5; i++) { SDL_RenderDrawLine(renderer, 32 * i, 192, 32 * i, 288); }
    for (int i = 10; i <= 15; i++) { SDL_RenderDrawLine(renderer, 32 * i, 192, 32 * i, 288); }
    for (int i = 1; i <= 5; i++) { SDL_RenderDrawLine(renderer, 192, 32 * i, 288, 32 * i); }
    for (int i = 10; i <= 15; i++) { SDL_RenderDrawLine(renderer, 192, 32 * i, 288, 32 * i); }

    //triaangles at centre
    SDL_RenderDrawLine(renderer, 192, 192, 288, 288);
    SDL_RenderDrawLine(renderer, 192, 288, 288, 192);

    //Red Squares
    SDL_SetRenderDrawColor(renderer, 128, 0, 0, 255);
    drawRectangle(renderer, 32, 32, 48, 48);
    drawRectangle(renderer, 32, 112, 48, 48);
    drawRectangle(renderer, 112, 112, 48, 48);
    drawRectangle(renderer, 112, 32, 48, 48);
  
    //Blue Squares
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    drawRectangle(renderer, 320, 32, 48, 48);
    drawRectangle(renderer, 400, 32, 48, 48);
    drawRectangle(renderer, 320, 112, 48, 48);
    drawRectangle(renderer, 400, 112, 48, 48);
    
    //Green rectangle   
    SDL_SetRenderDrawColor(renderer, 0, 51, 0, 255);
    drawRectangle(renderer, 32, 320, 48, 48);
    drawRectangle(renderer, 32, 400, 48, 48);
    drawRectangle(renderer, 112, 320, 48, 48);
    drawRectangle(renderer, 112, 400, 48, 48);
    
    //Yellow rectangle
    SDL_SetRenderDrawColor(renderer, 255, 102, 19, 255);
    drawRectangle(renderer, 320, 320, 48, 48);
    drawRectangle(renderer, 320, 400, 48, 48);
    drawRectangle(renderer, 400, 400, 48, 48);
    drawRectangle(renderer, 400, 320, 48, 48);
    
    // Render your Ludo board here

    SDL_RenderPresent(renderer);
}

int main()
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Ludo Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;
    int quit = 0;

    while (!quit) 
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
        }

        renderBoard(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
