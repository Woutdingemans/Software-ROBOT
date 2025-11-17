
#include "EduRobotRobot.h"
#include <Arduino.h>

EduRobotRobot::EduRobotRobot(EduRobotAxis *x, EduRobotAxis *y, EduRobotAxis *z, int safetyPin) {
    X = x;
    Y = y;
    Z = z;
    safePin = safetyPin;
}

bool EduRobotRobot::isSafe() {
    return digitalRead(safePin) == LOW; // NC safety
}

void EduRobotRobot::homeAll() {
    if (!isSafe()) return;
    X->home();
    Y->home();
    Z->home();
}
