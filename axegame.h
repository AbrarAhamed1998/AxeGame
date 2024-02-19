#pragma once
void PatrollingAxe(int &axePosY, int &axeVerticalDirection, int windowHeight, int axeHeight);

int XInput();

int YInput();

bool LimitMovementAcrossAxis(int currentvalue, int minOffsetValue, int MaxValueOfAxis);

void MoveCircleAcrossAxis(int &axisValue, int speed, int inputDirection, bool canMove);