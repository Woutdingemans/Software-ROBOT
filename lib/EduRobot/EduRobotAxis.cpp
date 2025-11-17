
#include "EduRobotAxis.h"

EduRobotAxis::EduRobotAxis(int stepP, int dirP, int enaP, int homeP,
                           long minP, long maxP, bool dirHigh, int delayMicros) {
    stepPin = stepP;
    dirPin = dirP;
    enaPin = enaP;
    homePin = homeP;
    minPos = minP;
    maxPos = maxP;
    dirPosIsHigh = dirHigh;
    stepDelayMicros = delayMicros;
    pos = 0;
}

void EduRobotAxis::enable(bool en) {
    digitalWrite(enaPin, en ? HIGH : LOW);
}

bool EduRobotAxis::homeActive() {
    return digitalRead(homePin) == HIGH; // NC switch
}

void EduRobotAxis::step(int dirSign) {
    bool dirLevel = dirPosIsHigh ? (dirSign > 0) : (dirSign < 0);
    digitalWrite(dirPin, dirLevel ? HIGH : LOW);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelayMicros);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelayMicros);
    pos += (dirSign > 0 ? 1 : -1);
}

void EduRobotAxis::moveRelative(long steps) {
    int dir = steps >= 0 ? 1 : -1;
    long count = labs(steps);
    for (long i = 0; i < count; i++) {
        long nextPos = pos + (dir > 0 ? 1 : -1);
        if (nextPos < minPos || nextPos > maxPos) break;
        step(dir);
    }
}

void EduRobotAxis::moveTo(long target) {
    if (target < minPos || target > maxPos) return;
    moveRelative(target - pos);
}

void EduRobotAxis::home() {
    enable(true);
    for (int i = 0; i < 2000 && homeActive(); i++) step(+1);
    while (!homeActive()) step(-1);
    for (int i = 0; i < 1000; i++) step(+1);
    delay(5);
    int old = stepDelayMicros;
    stepDelayMicros = 1200;
    while (!homeActive()) step(-1);
    pos = 0;
    for (int i = 0; i < 500; i++) step(+1);
    pos = 0;
    stepDelayMicros = old;
}
