#include "raylib.h"
#include "axegame.h"

int main()
{
    /// Window Initialization
    int windowWidth = 1200;
    int windowHeight = 600;
    Color BGColor = WHITE;
    InitWindow(windowWidth, windowHeight, "AxeGame");

    int windowCenterX = windowWidth/2;
    int windowCenterY = windowHeight/2;
    /// Circle initialization variables

    int circleCenterX = windowCenterX;
    int circleCenterY = windowCenterY;
    int circleRadius = 30;
    Color circleColor = BLUE;

    //int left_circleEdge{circleCenterX-circleRadius};
    //int right_circleEdge{circleCenterX+circleRadius};
    //int up_circleEdge{circleCenterY-circleRadius};
    //int bottom_circleEdge{circleCenterY+circleRadius}; 

    int axePosX = 600;
    int axePosY = 0;
    int axeWidth = 50;
    int axeHeight = 50;

    //int left_axeEdge{axePosX - (axeWidth/2)};
    //int right_axeEdge{axePosX + (axeWidth/2)};
    //int up_axeEdge{axePosY - (axeHeight/2)};
    //int low_axeEdge{axePosY + (axeHeight/2)};

    //rectanglePosX -= rectangleWidth/2;
    Color rectangleColor = RED;

    int axeVerticalDirection = 10;

    /// Circle Movement variables
    int circleHorizontalSpeed = 20;
    int circleVerticalSpeed = 20;

    //int previousValX = 0;
    //int previousValY = 0;

    bool collisionWithAxe = false;

    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BGColor);

        if(collisionWithAxe)
        {
            DrawText("GAME OVER!!", windowCenterX, windowCenterY, 100, RED);
        }
        else
        {
            #pragma region CIRCLE SETUP

        DrawCircle(circleCenterX, circleCenterY, circleRadius, circleColor);
        //float deltaTime = GetFrameTime();
        //previousValX = circleCenterX;
        //previousValY = circleCenterY;
        MoveCircleAcrossAxis(circleCenterX, 
        circleHorizontalSpeed, 
        XInput(), 
        !LimitMovementAcrossAxis(circleCenterX + (XInput() * circleHorizontalSpeed) , circleRadius, windowWidth));

        MoveCircleAcrossAxis(circleCenterY,
        circleVerticalSpeed,
        YInput(),
        !LimitMovementAcrossAxis(circleCenterY + (YInput() * circleVerticalSpeed) , circleRadius, windowHeight));
        

        #pragma endregion

        #pragma region AXE SETUP

        DrawRectangle(axePosX, axePosY, axeWidth, axeHeight, rectangleColor);

        PatrollingAxe(axePosY, axeVerticalDirection, windowHeight, axeHeight);

        #pragma endregion

        }
        EndDrawing();
    }
}

void PatrollingAxe(int &axePosY, int &axeVerticalDirection, int windowHeight, int axeHeight)
{
    axePosY += axeVerticalDirection;
    if (LimitMovementAcrossAxis(axePosY, 0, windowHeight - axeHeight))
    {
        axeVerticalDirection *= -1;
    }
}

void MoveCircleAcrossAxis(int &axisValue, 
int speed, int inputDirection, bool canMove)
{
    if(canMove)
    {
        axisValue += inputDirection * (speed);
    }
}

int XInput()
{
    if((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)))
    {
        return -1;
    }
    else if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        return 1;
    }
    else
    {
        return 0;
    } 
}

int YInput()
{
    if((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)))
    {
        return -1;
    }
    else if(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        return 1;
    }
    else
    {
        return 0;
    } 
}


bool LimitMovementAcrossAxis(int predictiveValue, int minOffsetValue, int MaxValueOfAxis)
{
    if (predictiveValue <= minOffsetValue || predictiveValue >= (MaxValueOfAxis - minOffsetValue))
    {
        return true;
    }
    return false;
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