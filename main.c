#include <raylib.h>
#include "ball.h"
#include "player.h"

int player1X=0;
int player1Y=0;

int player2X=0;
int player2Y=0;


int ballX=0;
int ballY=0;
int ballRadius=30;
Color ballColor=GREEN;


int playerHeight=200;
int playerWidth=20;
Color playerColor=RED;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    player2X=10;
    player1X=screenWidth-20;

    player2Y=(screenHeight/2)-playerHeight;
    player1Y=(screenHeight/2)-playerHeight;


    ballX=(screenWidth/2)-ballRadius;
    ballY=(screenHeight/2)-ballRadius;


    InitWindow(screenWidth, screenHeight, "PingPong");

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

        if(IsKeyDown(83)) //Key Code 83 is the letter S on keyboard
        {
            if(player2Y<(screenHeight-playerHeight))
            {
                player2Y=player2Y+1;
            }
        }


        if(IsKeyDown(KEY_UP)) //Key Code for Up Arrow key on keyboard
        {
            if(player1Y>0)
            {
                player1Y=player1Y-1;
            }
        }

        if(IsKeyDown(KEY_DOWN))  //Key Code for Down Arrow key on keyboard
        {
            if(player1Y<(screenHeight-playerHeight))
            {
                player1Y=player1Y+1;
            }
        }




        BeginDrawing();
        ClearBackground(BLACK);
        drawPlayerAtPos(player1X,player1Y,playerWidth,playerHeight,playerColor);
        drawPlayerAtPos(player2X,player2Y,playerWidth,playerHeight,playerColor);

        drawBallAtPos(ballX,ballY,ballRadius,ballColor);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
