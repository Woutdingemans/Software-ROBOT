#include <Arduino.h>
#include "EduRobotAxis.h"
#include "EduRobotRobot.h"

// Axis definitions
EduRobotAxis axisX(2,5,8,22, 0,20000, true, 600);
EduRobotAxis axisY(3,6,9,23, 0,20000, true, 600);
EduRobotAxis axisZ(4,7,10,24, 0,10000, true, 600);

EduRobotRobot robot(&axisX, &axisY, &axisZ, 25);

void setup() {
    Serial.begin(115200);

    pinMode(2,OUTPUT); pinMode(5,OUTPUT); pinMode(8,OUTPUT); pinMode(22,INPUT_PULLUP);
    pinMode(3,OUTPUT); pinMode(6,OUTPUT); pinMode(9,OUTPUT); pinMode(23,INPUT_PULLUP);
    pinMode(4,OUTPUT); pinMode(7,OUTPUT); pinMode(10,OUTPUT); pinMode(24,INPUT_PULLUP);

    pinMode(25,INPUT_PULLUP);

    axisX.enable(true);
    axisY.enable(true);
    axisZ.enable(true);

    Serial.println("EduRobot Basic Demo Ready");
}

void loop() {
    if (Serial.available()) {
        char c = Serial.read();
        if (c == 'h') robot.homeAll();
        if (c == 'x') axisX.moveRelative(Serial.parseInt());
        if (c == 'y') axisY.moveRelative(Serial.parseInt());
        if (c == 'z') axisZ.moveRelative(Serial.parseInt());
    }
}


