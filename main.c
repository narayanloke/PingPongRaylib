#include <raylib.h>
#include "ball.h"
#include "player.h"

int player1X=0;
int player1Y=0;

int player2X=0;
int player2Y=0;


int ballX=0;
int ballY=0;


int playerHeight=30;
int playerWidth=10;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    player2X=10;
    player1X=screenWidth-20;

    player2Y=(screenHeight/2)-playerHeight;
    player1Y=(screenHeight/2)-playerHeight;

    InitWindow(screenWidth, screenHeight, "Raylib [C] Example");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if(IsKeyDown(87)) //Key Code 87 is the letter W on keyboard
        {
            if(player2Y>0)
            {
                player2Y=player2Y-1;
            }
        }

        if(IsKeyDown(83))
        {
            if(player2Y<(screenHeight-playerHeight))
            {
                player2Y=player2Y+1;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);
        drawPlayerAtPos(player1X,player1Y,playerWidth,playerHeight,RED);
        drawPlayerAtPos(player2X,player2Y,playerWidth,playerHeight,RED);



        EndDrawing();
    }

    CloseWindow();
    return 0;
}
