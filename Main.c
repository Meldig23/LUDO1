#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    int x;
    int y;

} Token;//coordinates of tokens are stored

typedef struct {
    Token tokens[4];

} Player;//stores an array of token types of each player

void drawRectangle(SDL_Renderer* renderer, int x, int y, int width, int height)//fn to draw rect
{
    SDL_Rect rect = { x, y, width, height };
    SDL_RenderFillRect(renderer, &rect);
}

void drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius)//fn to draw a circle using points
{


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

void drawnumberondice(SDL_Renderer* renderer, int dicenumber) //fn to print the dots on the dice using the above circle fn
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    if (dicenumber == 1) {

        drawCircle(renderer, 560, 405, 8);
    }
    else if (dicenumber == 2) {

        drawCircle(renderer, 552, 393, 6);
        drawCircle(renderer, 568, 413, 6);
    }
    else if (dicenumber == 3) {

        drawCircle(renderer, 560 - 15, 405 - 15, 6);
        drawCircle(renderer, 535 + 25, 380 + 25, 6);
        drawCircle(renderer, 560 + 15, 405 + 15, 6);
    }
    else if (dicenumber == 4) {

        drawCircle(renderer, 560 - 12, 405 - 12, 6);
        drawCircle(renderer, 560 - 12, 405 + 12, 6);
        drawCircle(renderer, 560 + 12, 405 - 12, 6);
        drawCircle(renderer, 560 + 12, 405 + 12, 6);
    }
    else if (dicenumber == 5) {
        drawCircle(renderer, 560 - 13, 405 - 13, 6);
        drawCircle(renderer, 560 - 13, 405 + 13, 6);
        drawCircle(renderer, 560 + 13, 405 - 13, 6);
        drawCircle(renderer, 560 + 13, 405 + 13, 6);
        drawCircle(renderer, 560, 405, 6);
    }
    else if (dicenumber == 6) {

        drawCircle(renderer, 560 - 13, 405 - 15, 6);
        drawCircle(renderer, 560 - 13, 405 + 15, 6);
        drawCircle(renderer, 560 - 13, 405, 6);
        drawCircle(renderer, 560 + 13, 405 - 15, 6);
        drawCircle(renderer, 560 + 13, 405 + 15, 6);
        drawCircle(renderer, 560 + 13, 405, 6);
    }
}

void renderBoard(SDL_Renderer* renderer, Player players[4], int dicenumber, int playerturn)//the different components of the board are drawn using different parts of the fn 
{


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);//Black background
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    drawRectangle(renderer, 535, 380, 50, 50);//Dice

    drawnumberondice(renderer, dicenumber);

    //colour for player turn
    if (playerturn == 0) {
        SDL_SetRenderDrawColor(renderer, 236, 70, 50, 255);//red
    }
    if (playerturn == 1) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);//blue
    }
    if (playerturn == 2) {
        SDL_SetRenderDrawColor(renderer, 255, 224, 19, 255); // yellow
    }
    if (playerturn == 3) {
        SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);//green
    }

    drawRectangle(renderer, 535, 50, 50, 50);//rectangle for player turn
    //entry line red
    SDL_SetRenderDrawColor(renderer, 204, 0, 0, 255);
    drawRectangle(renderer, 32, 192, 32, 32);//single box

    drawRectangle(renderer, 32, 224, 160, 32);//long box
    //entry line blue
    SDL_SetRenderDrawColor(renderer, 0, 0, 128, 255);
    drawRectangle(renderer, 224, 32, 32, 160);//long box
    drawRectangle(renderer, 256, 32, 32, 32);//single box
    //entry line yellow
    SDL_SetRenderDrawColor(renderer, 193, 150, 19, 255);
    drawRectangle(renderer, 288, 224, 160, 32);//long box
    drawRectangle(renderer, 416, 256, 32, 32);//single box
    //entry line green
    SDL_SetRenderDrawColor(renderer, 0, 85, 27, 255);
    drawRectangle(renderer, 224, 288, 32, 160);//long line
    drawRectangle(renderer, 192, 416, 32, 32);//single box

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color

    //remainig lines to complete the board 
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
    SDL_SetRenderDrawColor(renderer, 204, 0, 0, 255);
    drawRectangle(renderer, 32, 32, 48, 48);
    drawRectangle(renderer, 32, 112, 48, 48);
    drawRectangle(renderer, 112, 112, 48, 48);
    drawRectangle(renderer, 112, 32, 48, 48);

    //Blue Squares
    SDL_SetRenderDrawColor(renderer, 0, 0, 128, 255);
    drawRectangle(renderer, 320, 32, 48, 48);
    drawRectangle(renderer, 400, 32, 48, 48);
    drawRectangle(renderer, 320, 112, 48, 48);
    drawRectangle(renderer, 400, 112, 48, 48);

    //Green squares   
    SDL_SetRenderDrawColor(renderer, 0, 85, 27, 255);
    drawRectangle(renderer, 32, 320, 48, 48);
    drawRectangle(renderer, 32, 400, 48, 48);
    drawRectangle(renderer, 112, 320, 48, 48);
    drawRectangle(renderer, 112, 400, 48, 48);

    //Yellow squares
    SDL_SetRenderDrawColor(renderer, 193, 150, 19, 255);
    drawRectangle(renderer, 320, 320, 48, 48);
    drawRectangle(renderer, 320, 400, 48, 48);
    drawRectangle(renderer, 400, 400, 48, 48);
    drawRectangle(renderer, 400, 320, 48, 48);

    //Triangles
    //Red Triangle
    SDL_SetRenderDrawColor(renderer, 204, 0, 0, 255);
    for (int x = 0; x <= 640; x++) {
        for (int y = 0; y <= 480; y++) {
            if (x > 192 && y > x && (x + y) < 480)
                SDL_RenderDrawPoint(renderer, x, y);
        }
    }

    //Blue triangle
    SDL_SetRenderDrawColor(renderer, 0, 0, 128, 255);
    for (int x = 0; x <= 640; x++) {
        for (int y = 0; y <= 480; y++) {
            if (y > 192 && x > y && (x + y) < 480)
                SDL_RenderDrawPoint(renderer, x, y);
        }
    }
    //Yellow triangle
    SDL_SetRenderDrawColor(renderer, 193, 150, 19, 255);
    for (int x = 0; x <= 640; x++) {
        for (int y = 0; y <= 480; y++) {
            if (x < 288 && y < x && (x + y) > 480)
                SDL_RenderDrawPoint(renderer, x, y);
        }
    }
    //Green triangle
    SDL_SetRenderDrawColor(renderer, 0, 85, 27, 255);
    for (int x = 0; x <= 640; x++) {
        for (int y = 0; y <= 480; y++) {
            if (y < 288 && y > x && (x + y) > 480)
                SDL_RenderDrawPoint(renderer, x, y);
        }
    }

    //tokens

    for (int i = 0; i < 4; i++) {
        if (i == 0) SDL_SetRenderDrawColor(renderer, 236, 70, 50, 255);//red
        else if (i == 1) SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);//blue
        else if (i == 2) SDL_SetRenderDrawColor(renderer, 255, 224, 19, 255); // yellow
        else if (i == 3) SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);//green
        for (int j = 0; j < 4; j++) {
            drawCircle(renderer, players[i].tokens[j].x, players[i].tokens[j].y, 13);
        }
    }






    SDL_RenderPresent(renderer);
    if (checkwin(players, playerturn) == 4) {// winner colour declaration

        SDL_Delay(500);
        if (playerturn == 0) {
            SDL_SetRenderDrawColor(renderer, 236, 70, 50, 255);//red
        }
        if (playerturn == 1) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);//blue
        }
        if (playerturn == 2) {
            SDL_SetRenderDrawColor(renderer, 255, 224, 19, 255); // yellow
        }
        if (playerturn == 3) {
            SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);//green
        }

        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }
}

int rolldice() {//returns a random no for dice
    srand(time(NULL));
    return rand() % 6 + 1;
}

void movetokenfrominitial(Token* token, int player) {//fn to move the token from the home box to the respective start
    if (player == 0) {//red
        token->x = 48;
        token->y = 208;
    }
    else if (player == 1) {//blue
        token->x = 272;
        token->y = 48;
    }
    else if (player == 2) {//yellow
        token->x = 432;
        token->y = 272;
    }
    else if (player == 3) {//green
        token->x = 208;
        token->y = 432;
    }
}

void moveToken(Token* token, int player, int dicenumber, int tokenno) {//moving the tokens throughout the board
    while (dicenumber != 0) {
        if ((token->x > 0 && token->x < 192 && token->y > 192 + 32 && token->y < 192 + 64) && (player == 0)) {

            token->x += 32;
            dicenumber--;
            if (token->x > 192) {
                token->x = 480 + 32;
                token->y = 192 + 35 * tokenno;
                break;
            }

        }
        else if ((token->y > 0 && token->y < 192 && token->x > 192 + 32 && token->x < 192 + 64) && (player == 1)) {

            token->y += 32;
            dicenumber--;
            if (token->y > 192) {
                token->x = 480 + 64;
                token->y = 192 + 35 * tokenno;
                break;
            }
        }
        else if ((token->y > 192 + 32 && token->y < 192 + 64 && token->x > 288 && token->x < 480) && (player == 2)) {

            token->x -= 32;
            dicenumber--;
            if (token->x < 288) {
                token->x = 480 + 96;
                token->y = 192 + 35 * tokenno;
                break;
            }
        }
        else if ((token->y > 288 && token->y < 480 && token->x > 192 + 32 && token->x < 192 + 64) && (player == 3)) {

            token->y -= 32;
            dicenumber--;
            if (token->y < 288) {
                token->x = 480 + 128;
                token->y = 192 + 35 * tokenno;
                break;
            }
        }
        else if (((token->x > 0 && token->x < 32 * 5) || (token->x > 288 && token->x < 480 - 32)) && (token->y > 192 && token->y < 192 + 32)) {
            token->x += 32;
            dicenumber--;
        }
        else if (((token->x > 32 && token->x < 32 * 6) || (token->x > 288 + 32 && token->x < 480)) && (token->y > 192 + 64 && token->y < 192 + 96)) {
            token->x -= 32;
            dicenumber--;

        }
        else if (((token->y > 32 && token->y < 192) || (token->y > 288 + 32 && token->y < 480)) && (token->x > 192 && token->x < 192 + 32)) {
            token->y -= 32;
            dicenumber--;

        }
        else if (((token->y > 0 && token->y < 192 - 32) || (token->y > 288 && token->y < 480 - 32)) && (token->x > 192 + 64 && token->x < 192 + 32 + 64)) {
            token->y += 32;
            dicenumber--;

        }
        else if ((token->x > 192 && token->x < 192 + 64) && (token->y > 0 & token->y < 32)) {
            token->x += 32;
            dicenumber--;
        }
        else if ((token->x > 192 + 32 && token->x < 192 + 96) && (token->y > 480 - 32 && token->y < 480)) {
            token->x -= 32;
            dicenumber--;
        }
        else if ((token->y > 192 + 32 && token->y < 192 + 96) && (token->x > 0 && token->x < 32)) {
            token->y -= 32;
            dicenumber--;
        }
        else if ((token->y > 192 && token->y < 192 + 64) && (token->x > 480 - 32 && token->x < 480)) {
            token->y += 32;
            dicenumber--;
        }
        else if (token->x == 32 * 5 + 16 && token->y == 192 + 16) {
            token->y -= 32;
            token->x += 32;
            dicenumber--;
        }
        else if (token->x == 288 - 16 && token->y == 192 - 16) {
            token->y += 32;
            token->x += 32;
            dicenumber--;
        }
        else if (token->x == 288 + 16 && token->y == 288 - 16) {
            token->y += 32;
            token->x -= 32;
            dicenumber--;
        }
        else if (token->x == 192 + 16 && token->y == 288 + 16) {
            token->y -= 32;
            token->x -= 32;
            dicenumber--;
        }
        else {
            break;
        }
    }

}

void nextplayerturn(int* playerturn) {//deciding who plays next
    *playerturn = *playerturn + 1;
    *playerturn = *playerturn % 4;
}

int checkCollision(Player players[4], Token* token, int playerturn) {// killing 
    int counter = 0;
    //safe homes
    if (token->x == 48 && token->y == 208) {
        counter -= 1;

    }
    else if (token->x == 272 && token->y == 48) {
        counter -= 1;

    }
    else if (token->x == 432 && token->y == 272) {
        counter -= 1;

    }
    else if (token->x == 208 && token->y == 432) {
        counter -= 1;


    }
    //killing
    if (counter >= 0) {
        for (int l = 0; l < 4; l++) {
            Player* otherPlayer = &players[l];
            if (l != playerturn) {


                for (int m = 0; m < 4; m++) {
                    Token* otherToken = &otherPlayer->tokens[m];
                    //printf("Other Player %d Token %d\n", l, m);
                    //printf("Entered loop %d Otherplayer token %d\n", token->x,otherToken->x);
                    if (otherToken->x == token->x && otherToken->y == token->y) {
                        otherToken->x = 56 + (l > 0 && l < 3) * 288 + 80 * (m % 2);
                        otherToken->y = 56 + 288 * (l > 1) + 80 * (m > 1);
                        counter += 1;
                    }
                }

            }

        }
    }
    if (counter <= 0) return 0;
    else return 1;
}
int checkwin(Player players[], int playerturn) {//checking if a player has won
    int c = 0;
    for (int j = 0; j < 4; j++) {
        if (players[playerturn].tokens[j].x == 512 + 32 * playerturn && players[playerturn].tokens[j].y == 192 + 35 * j) c += 1;
    }
    return c;
}


int main(int* argc, char* argv[])
{
    SDL_Window* window = NULL;// initialising window 
    SDL_Renderer* renderer = NULL;// initialising renderer



    SDL_Init(SDL_INIT_VIDEO);


    window = SDL_CreateWindow("Ludo Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);//creating window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);//creating renderer

    // Initialize SDL_ttf
    TTF_Init();
    // Load a font
    TTF_Font* font = TTF_OpenFont("E:/LBRITE.ttf", 100);
    if (font == NULL) {
        // Error handling
        SDL_Log("Failed to load font: %s", TTF_GetError());
        return 1;
    }

    // Create a color for the text (white in this case)
    SDL_Color textColor = { 255, 255, 255, 255 };

    // Create a surface from the font and text
    SDL_Surface* surface = TTF_RenderText_Solid(font, "LUDO", textColor);

    // Create a texture from the surface`

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    // Clear the renderer
    SDL_RenderClear(renderer);
    SDL_Rect rect = { 220, 200, 220, 80 };
    // Render the texture on the screen
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    // Update the screen
    SDL_RenderPresent(renderer);

    // Delay to show the text for a few seconds
    SDL_Delay(6000);



    Player players[4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            players[i].tokens[j].x = 56 + (i > 0 && i < 3) * 288 + 80 * (j % 2);
            players[i].tokens[j].y = 56 + 288 * (i > 1) + 80 * (j > 1);

        }
    }


    //initialising all the parameters to 0

    SDL_Event event = { 0 };
    int quit = 0;
    int dicenumber = 0;
    int playerturn = 0;
    double angle = 0;
    Token diceposition = { 535,380 };
    int c = 0;
    int skipturn = 0;
    while (!quit)//while the game has not stopped
    {


        while (SDL_PollEvent(&event))
        {

            if (event.type == SDL_QUIT)
            {
                quit = 1;//stop game
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {// game continues
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;//gets the coordinates of the clicked token 
                    int y = event.button.y;
                    int i = playerturn;

                    if (x >= diceposition.x && x <= diceposition.x + 50 && y >= diceposition.y && y <= diceposition.y + 50 && dicenumber == 0) {

                        printf("Player %d turn\n", playerturn + 1);
                        dicenumber = rolldice();

                        printf("%d\n", dicenumber);

                        for (int j = 0; j < 4; j++) {//checks if the token are in the home box
                            if ((players[i].tokens[j].x == 56 + (i > 0 && i < 3) * 288 + 80 * (j % 2) && players[i].tokens[j].y == 56 + 288 * (i > 1) + 80 * (j > 1)) || (players[i].tokens[j].x == 512 + 32 * i && players[i].tokens[j].y == 192 + 35 * j)) {
                                c += 1;
                            }

                        }
                        if (c == 4 && dicenumber != 6) {// skips turn in the beggning if we dont get 6
                            nextplayerturn(&playerturn);


                            skipturn = 1;
                            c = 0;
                        }
                        else {
                            skipturn = 0;
                        }

                    }




                    for (int j = 0; j < 4; j++) {

                        Token* token = &players[i].tokens[j];
                        if (dicenumber != 0) {
                            if (pow(x - token->x, 2) + pow(y - token->y, 2) <= 13 * 13) {

                                if (players[i].tokens[j].x == 56 + (i > 0 && i < 3) * 288 + 80 * (j % 2) && players[i].tokens[j].y == 56 + 288 * (i > 1) + 80 * (j > 1)) {
                                    if (dicenumber == 6) {
                                        movetokenfrominitial(token, i);//bring out the token
                                        dicenumber = 0;
                                    }


                                    c = 0;
                                }
                                else {
                                    int start1 = checkwin(players, playerturn);
                                    moveToken(token, i, dicenumber, j);
                                    int end1 = checkwin(players, playerturn);
                                    //printf("Start z%d end %d", start1, end1);
                                    if (end1 == 4) {

                                        break;

                                    }
                                    if (end1 - start1 == 0) {
                                        if (!(checkCollision(players, token, playerturn))) {
                                            if (dicenumber != 6) {
                                                nextplayerturn(&playerturn);
                                            }
                                        }
                                    }

                                    dicenumber = 0;
                                    c = 0;

                                }


                                break;
                            }

                        }

                    }




                }




            }
        }

        
        renderBoard(renderer, players, dicenumber, playerturn);//render the board
        if (skipturn == 1) {
            dicenumber = 0;
            SDL_Delay(300);
        }
        if (checkwin(players, playerturn) == 4) break;//if player wins stop


    }

    TTF_Font* font1 = TTF_OpenFont("E:/LBRITE.ttf", 200);
    //post game destroying
    SDL_Color textColor1 = { 0, 0, 0, 255 };

    // Create a surface from the font and text
    SDL_Surface* surface1 = TTF_RenderText_Solid(font1, "WINNER", textColor1);

    // Create a texture from the surface`

    SDL_Texture* texture1 = SDL_CreateTextureFromSurface(renderer, surface1);

    // Clear the renderer
    SDL_RenderClear(renderer);
    SDL_Rect rect1 = { 220, 200, 220, 80 };
    // Render the texture on the screen
    SDL_RenderCopy(renderer, texture1, NULL, &rect1);

    // Update the screen
    SDL_RenderPresent(renderer);

    // Delay to show the text for a few seconds
    SDL_Delay(3000);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;

}
