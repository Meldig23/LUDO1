#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Token;

typedef struct {
    Token tokens[4];
    
} Player;

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

void renderBoard(SDL_Renderer* renderer, Player players[4])
{   
    

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);//Black background
    SDL_RenderClear(renderer);
    
    //entry line red
    SDL_SetRenderDrawColor(renderer, 255, 12, 12, 255);
    drawRectangle(renderer, 32, 192, 32, 32);//single box
    drawRectangle(renderer, 32, 224, 160, 32);//long box
    //entry line blue
    SDL_SetRenderDrawColor(renderer, 50, 10, 255, 255);
    drawRectangle(renderer, 224, 32, 32, 160);//long box
    drawRectangle(renderer, 256, 32, 32, 32);//single box
    //entry line yellow
    SDL_SetRenderDrawColor(renderer, 255, 224, 19, 255);
    drawRectangle(renderer, 288, 224, 160, 32);//long box
    drawRectangle(renderer, 416, 256, 32, 32);//single box
    //entry line green
    SDL_SetRenderDrawColor(renderer, 50, 255, 10, 255);
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
    SDL_SetRenderDrawColor(renderer, 255, 12, 12, 255);
    drawRectangle(renderer, 32, 32, 48, 48);
    drawRectangle(renderer, 32, 112, 48, 48);
    drawRectangle(renderer, 112, 112, 48, 48);
    drawRectangle(renderer, 112, 32, 48, 48);

    //Blue Squares
    SDL_SetRenderDrawColor(renderer, 50, 10, 255, 255);
    drawRectangle(renderer, 320, 32, 48, 48);
    drawRectangle(renderer, 400, 32, 48, 48);
    drawRectangle(renderer, 320, 112, 48, 48);
    drawRectangle(renderer, 400, 112, 48, 48);

    //Green squares   
    SDL_SetRenderDrawColor(renderer, 50, 255, 10, 255);
    drawRectangle(renderer, 32, 320, 48, 48);
    drawRectangle(renderer, 32, 400, 48, 48);
    drawRectangle(renderer, 112, 320, 48, 48);
    drawRectangle(renderer, 112, 400, 48, 48);

    //Yellow squares
    SDL_SetRenderDrawColor(renderer, 255, 224, 19, 255);
    drawRectangle(renderer, 320, 320, 48, 48);
    drawRectangle(renderer, 320, 400, 48, 48);
    drawRectangle(renderer, 400, 400, 48, 48);
    drawRectangle(renderer, 400, 320, 48, 48);

    //Triangles
    //Red Triangle
    SDL_SetRenderDrawColor(renderer, 255, 12, 12, 255);
    for (int x = 0; x <= 640; x++) {
        for (int y = 0; y <= 480; y++) {
            if (x > 192 && y > x && (x + y) < 480)
                SDL_RenderDrawPoint(renderer, x, y);
        }
    }

    //Blue triangle
    SDL_SetRenderDrawColor(renderer, 50, 10, 255, 255);
    for (int x = 0; x <= 640; x++) {
        for (int y = 0; y <= 480; y++) {
            if (y > 192 && x > y && (x + y) < 480)
                SDL_RenderDrawPoint(renderer, x, y);
        }
    }
    //Yellow triangle
    SDL_SetRenderDrawColor(renderer, 255, 224, 19, 255);
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

    // Red token
    
    for (int i = 0; i < 4; i++) {
        if (i == 0) SDL_SetRenderDrawColor(renderer, 160, 0, 20, 255);
        if (i==1) SDL_SetRenderDrawColor(renderer, 50, 10, 150, 255);
        if (i==2) SDL_SetRenderDrawColor(renderer, 178, 255, 102, 255);
        if (i==3) SDL_SetRenderDrawColor(renderer, 255, 255, 153, 255);
        for (int j = 0; j < 4; j++) {
            drawCircle(renderer, players[i].tokens[j].x, players[i].tokens[j].y);
        }
    }
    
    


    

    SDL_RenderPresent(renderer);
}

int rolldice() {
    return rand() % 6 + 1;
}

void movetokenfrominitial(Token *token,int player) {
    if (player == 0) {
        token->x =48 ;
        token->y =208 ;
    } else if (player == 1) {
        token->x =272 ;
        token->y = 48;
    }else if (player == 2) {
        token->x =208 ;
        token->y =432 ;
    }else if (player == 3) {
        token->x =432 ;
        token->y =272 ;
    }
}
void moveToken(Token* token,int player,int dicenumber) {
    
    
        if (((token->x > 0 && token->x < 32 * 5) || (token->x > 288 && token->x < 480 - 32)) && (token->y > 192 && token->y < 192 + 32)) {
            token->x += 32;
            dicenumber--;
        }
    

    
    
}


int main(int* argc,char * argv[])
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;



    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Ludo Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    
    Player players[4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            players[i].tokens[j].x = 56+(i % 2) * 288 + 80 * (j % 2);
            players[i].tokens[j].y = 56+288*(i>1)+ 80*(j>1); 
        }
    }
    

    
    SDL_Event event = { 0 };
    int quit = 0;
    int dicenumber=0;
    while (!quit)
    {

        while (SDL_PollEvent(&event))
        {
            if (1) {
                srand(time(NULL));
                dicenumber = rolldice();
            }
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    for (int i = 0; i < 4; i++) {
                        for (int j = 0; j < 4; j++) {
                            Token* token = &players[i].tokens[j];
                            if (pow(x - token->x, 2) + pow(y - token->y, 2) <= 13*13) {
                                printf("%d", dicenumber);
                                if (players[i].tokens[j].x == 56 + (i % 2) * 288 + 80 * (j % 2) && players[i].tokens[j].y == 56 + 288 * (i > 1) + 80 * (j > 1) && dicenumber==6) {
                                    movetokenfrominitial(token,i);
                                }
                                else {
                                    moveToken(token, i, dicenumber);
                                }
                            }
                                
                            
                        }
                    }

                    
                }




            }
        }

        renderBoard(renderer, players);
    }

    

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;

}

