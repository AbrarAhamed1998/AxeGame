#pragma once
void MoveCircle(int &circleCenterX, int circleHorizontalSpeed, int &circleCenterY, int circleVerticalSpeed);

void LimitCircleMovement(int &circleCenterX, int circleRadius, int MaxHorizontalDistance, int &previousXVal, int &circleCenterY, int MaxVerticalDistance, int &previousYVal);
