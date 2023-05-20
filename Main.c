
#include <SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define BOARD_SIZE 15
#define TILE_SIZE (SCREEN_HEIGHT / BOARD_SIZE)
void drawRectangle(SDL_Renderer* renderer, int x, int y, int width, int height) {
    SDL_Rect rect = { x, y, width, height };
    SDL_RenderFillRect(renderer, &rect);
}
void drawCircle(SDL_Renderer * renderer,int centerX, int centerY) {
    int radius = 13;

    for (int y = -radius; y <= radius; ++y) {
        for (int x = -radius; x <= radius; ++x) {
            if (x * x + y * y <= radius * radius) {
                SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
            }
        }
    }
}
int max(int a, int b, int c) {
    if (a > b && a > c) {
        return a;
    }
    else if (b > c && b > a) {
        return b;
    }
    else {
        return c;
    }
    
}
int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    }
    else if (b < c && b < a) {
        return b;
    }
    else {
        return c;
    }

}


void renderBoard(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);

    SDL_RenderDrawLine(renderer, 0, 480, 480, 480);
    SDL_RenderDrawLine(renderer, 480, 0, 480, 480);
    
    SDL_RenderDrawLine(renderer, 192, 0, 192, 480);
    SDL_RenderDrawLine(renderer, 288 ,0, 288, 480);
    SDL_RenderDrawLine(renderer, 0, 192, 480, 192);
    SDL_RenderDrawLine(renderer, 0, 288, 480, 288);

    SDL_RenderDrawLine(renderer, 224,0,224 ,192);
    SDL_RenderDrawLine(renderer, 256, 0, 256, 192);
    SDL_RenderDrawLine(renderer, 224, 288, 224, 480);
    SDL_RenderDrawLine(renderer, 256, 288, 256, 480);
    
    SDL_RenderDrawLine(renderer, 0, 224, 192, 224);
    SDL_RenderDrawLine(renderer, 0, 256, 192, 256);
    SDL_RenderDrawLine(renderer, 288, 224, 480, 224);
    SDL_RenderDrawLine(renderer, 288, 256, 480, 256);

    for (int i = 1; i <= 5; i++) { SDL_RenderDrawLine(renderer, 32*i, 192, 32*i, 288); }
    for (int i = 10; i <= 15; i++) { SDL_RenderDrawLine(renderer, 32 * i, 192, 32 * i, 288); }
    for (int i = 1; i <= 5; i++) { SDL_RenderDrawLine(renderer, 192,32*i,288,32*i); }
    for (int i = 10; i <= 15; i++) { SDL_RenderDrawLine(renderer, 192, 32 * i, 288, 32 * i); }


    SDL_RenderDrawLine(renderer, 192, 192, 288, 288);
    SDL_RenderDrawLine(renderer, 192, 288, 288, 192);

    //Red Squares
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
   
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
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    drawRectangle(renderer, 32, 320, 48, 48);
    drawRectangle(renderer, 32, 400, 48, 48);
    drawRectangle(renderer, 112, 320, 48, 48);
    drawRectangle(renderer, 112, 400, 48, 48);

    //Yellow rectangle
    SDL_SetRenderDrawColor(renderer, 255, 224, 19, 255);
    drawRectangle(renderer, 320, 320, 48, 48);
    drawRectangle(renderer, 320, 400, 48, 48);
    drawRectangle(renderer, 400, 400, 48, 48);
    drawRectangle(renderer, 400, 320, 48, 48);
    // Red token
    SDL_SetRenderDrawColor(renderer, 160, 0, 20, 255);
    
    drawCircle(renderer, 32 + 48 / 2,32 + 48 / 2);
    drawCircle(renderer, 32 + 48 / 2, 112 + 48 / 2);
    drawCircle(renderer, 112 + 48 / 2, 32 + 48 / 2);
    drawCircle(renderer, 112 + 48 / 2, 112 + 48 / 2);

    //Triangles
    //Red Triangle
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (int x = 0; x <= 640; x++) {
        for (int y = 0; y <= 480; y++) {
            if (x > 192 && y > x && (x + y) < 480)
                SDL_RenderDrawPoint(renderer, x, y);
        }
    }

    //Blue triangle
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    for (int x = 0; x <= 640; x++) {
        for (int y = 0; y <= 480; y++) {
            if (y > 192 && x > y && (x + y) < 480)
                SDL_RenderDrawPoint(renderer, x, y);
        }
    }
    //Yellow triangle
    SDL_SetRenderDrawColor(renderer, 255,224 ,19, 255);
    for (int x = 0; x <= 640; x++) {
        for (int y = 0; y <= 480; y++) {
            if (x < 288 && y < x && (x + y) > 480)
                SDL_RenderDrawPoint(renderer, x, y);
        }
    }
    //Green triangle
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (int x = 0; x <= 640; x++) {
        for (int y = 0; y <= 480; y++) {
            if (y < 288 && y > x && (x + y) > 480)
                SDL_RenderDrawPoint(renderer, x, y);
        }
    }

    SDL_RenderPresent(renderer);
}

int main() {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Ludo Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;
    int quit = 0;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
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
