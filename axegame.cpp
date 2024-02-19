#include "raylib.h"
#include "axegame.h"
int main()
{
    /// Window Initialization
    int windowWidth = 1200;
    int windowHeight = 600;
    Color BGColor = RED;
    InitWindow(windowWidth, windowHeight, "AxeGame");

    /// Circle initialization variables

    int circleCenterX = windowWidth/2;
    int circleCenterY = windowHeight/2;
    int circleRadius = 30;
    Color circleColor = BLUE;

    /// Circle Movement variables
    int circleHorizontalSpeed = 20;
    int circleVerticalSpeed = 20;

    int previousValX = 0;
    int previousValY = 0;

    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BGColor);
        DrawCircle(circleCenterX, circleCenterY, circleRadius, circleColor);
        //float deltaTime = GetFrameTime();
        previousValX = circleCenterX;
        previousValY = circleCenterY;
        MoveCircle(circleCenterX, 
        circleHorizontalSpeed, 
        circleCenterY, 
        circleVerticalSpeed);
        LimitCircleMovement(circleCenterX, 
        circleRadius, 
        windowWidth, 
        previousValX, 
        circleCenterY, 
        windowHeight, 
        previousValY);

        EndDrawing();
    }
}

void MoveCircle(int &circleCenterX, 
int circleHorizontalSpeed, 
int &circleCenterY, 
int circleVerticalSpeed)
{
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        circleCenterX -= (circleHorizontalSpeed);
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        circleCenterX += (circleHorizontalSpeed);
    }

    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        circleCenterY -= (circleVerticalSpeed);
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        circleCenterY += (circleVerticalSpeed);
    }

}
void LimitCircleMovement(int &circleCenterX, int circleRadius, int MaxHorizontalDistance, int &previousXVal, int &circleCenterY, int MaxVerticalDistance, int &previousYVal)
{
    if (circleCenterX <= circleRadius || circleCenterX >= (MaxHorizontalDistance - circleRadius))
    {
        circleCenterX = previousXVal;
    }
    if (circleCenterY <= circleRadius || circleCenterY >= (MaxVerticalDistance - circleRadius))
    {
        circleCenterY = previousYVal;
    }
}
// Vector2Int GetWindowMiddle(int x, int y)
// {
//     return Vector2Int((int)(((float)x)/2), (int)(((float)y)/2));
// }

// struct Vector2Int
// {
//     Vector2Int(int x, int y)
//     {
//         this->x = x;
//         this->y = y;
//     }
//     int x;
//     int y;
// };