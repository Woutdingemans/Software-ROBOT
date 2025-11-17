
#ifndef EDU_ROBOT_ROBOT_H
#define EDU_ROBOT_ROBOT_H

#include "EduRobotAxis.h"

class EduRobotRobot {
public:
    EduRobotAxis *X;
    EduRobotAxis *Y;
    EduRobotAxis *Z;

    int safePin;

    EduRobotRobot(EduRobotAxis *x, EduRobotAxis *y, EduRobotAxis *z, int safetyPin);

    bool isSafe();
    void homeAll();
};

#endif
