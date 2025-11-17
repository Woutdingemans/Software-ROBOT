
#ifndef EDU_ROBOT_AXIS_H
#define EDU_ROBOT_AXIS_H

#include <Arduino.h>

class EduRobotAxis {
public:
    int stepPin;
    int dirPin;
    int enaPin;
    int homePin;
    long pos;
    long minPos;
    long maxPos;
    bool dirPosIsHigh;
    int stepDelayMicros;

    EduRobotAxis(int stepP, int dirP, int enaP, int homeP,
                 long minP, long maxP, bool dirHigh, int delayMicros);

    void enable(bool en);
    void step(int dirSign);
    bool homeActive();
    void moveRelative(long steps);
    void moveTo(long target);
    void home();
};

#endif
