#include <raylib.h>
#include "ball.h"
#include "player.h"

int player1X=0;
int player1Y=0;

int player2X=0;
int player2Y=0;

int player2Point=0;
int player1Point=0;

int ballX=0;
int ballY=0;
int ballRadius=20;
Color ballColor=GREEN;

int ballXincr=2;
int ballYincr=2;


int playerHeight=100;
int playerWidth=20;
Color playerColor=RED;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    player2X=10;
    player1X=screenWidth-playerWidth;

    player2Y=(screenHeight/2)-(playerHeight/2);
    player1Y=(screenHeight/2)-(playerHeight/2);


    ballX=(screenWidth/2);
    ballY=(screenHeight/2);


    InitWindow(screenWidth, screenHeight, "PingPong");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if(IsKeyDown(87)) //Key Code 87 is the letter W on keyboard
        {
            if(player2Y>0)
            {
                player2Y=player2Y-2;
            }
        }

        if(IsKeyDown(83)) //Key Code 83 is the letter S on keyboard
        {
            if(player2Y<(screenHeight-playerHeight))
            {
                player2Y=player2Y+2;
            }
        }


        if(IsKeyDown(KEY_UP)) //Key Code for Up Arrow key on keyboard
        {
            if(player1Y>0)
            {
                player1Y=player1Y-2;
            }
        }

        if(IsKeyDown(KEY_DOWN))  //Key Code for Down Arrow key on keyboard
        {
            if(player1Y<(screenHeight-playerHeight))
            {
                player1Y=player1Y+2;
            }
        }

        if(IsKeyDown(90))      //Key Code for z
        {
            player1Point=0;
            player2Point=0;
            ballXincr=2;
            ballYincr=2;
        }



        BeginDrawing();
        ClearBackground(BLACK);
        DrawLine(screenWidth/2,0,screenWidth/2,screenHeight,YELLOW);
        drawPlayerAtPos(player1X,player1Y,playerWidth,playerHeight,playerColor);
        drawPlayerAtPos(player2X,player2Y,playerWidth,playerHeight,playerColor);

        drawBallAtPos(ballX,ballY,ballRadius,ballColor);



        if(CheckCollisionCircleRec((Vector2){ballX,ballY},ballRadius,(Rectangle){player1X,player1Y,playerWidth,playerHeight}))
        {
            ballXincr=-2;

        }

        if(CheckCollisionCircleRec((Vector2){ballX,ballY},ballRadius,(Rectangle){player2X,player2Y,playerWidth,playerHeight}))
        {
            ballXincr=2;

        }

        if(CheckCollisionCircleLine((Vector2){ballX,ballY},ballRadius,(Vector2){0,0},(Vector2){0,screenHeight}))
        {
            player2Point+=1;
            ballX=screenWidth/2;
            ballY=screenHeight/2;
        }


        if(CheckCollisionCircleLine((Vector2){ballX,ballY},ballRadius,(Vector2){screenWidth,0},(Vector2){screenWidth,screenHeight}))
        {
            player1Point+=1;
            ballX=screenWidth/2;
            ballY=screenHeight/2;
        }


        if(ballY>=screenHeight)
        {
            ballYincr=-2;
        }
        if(ballY<=0)
        {
            ballYincr=2;
        }


        ballX=ballX+ballXincr;
        ballY=ballY+ballYincr;

        DrawText(TextFormat("%i", player1Point),100,50,20,RED);
        DrawText(TextFormat("%i", player2Point),(screenWidth-100),50,20,RED);


        if(player1Point==10)
        {
            ballX=screenWidth/2;
            ballY=screenHeight/2;
            ballXincr=0;
            ballYincr=0;
            DrawText(TextFormat("Player 1 Won. Press Z to restart."),(screenWidth/2)-200,(screenHeight/2)-100,30,RED);
        }


        if(player2Point==10)
        {
            ballX=screenWidth/2;
            ballY=screenHeight/2;
            ballXincr=0;
            ballYincr=0;
            DrawText(TextFormat("Player 2 Won. Press Z to restart."),(screenWidth/2)-200,(screenHeight/2)-100,30,RED);
        }



        EndDrawing();
    }

    CloseWindow();
    return 0;
}
