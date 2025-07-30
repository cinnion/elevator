//
// Created by cinnion on 7/23/25.
//
#include "ElevatorFloor.h"
#include "Button.h"

ElevatorFloor::ElevatorFloor(std::string label, int height) {
    this->label = label;
    this->height = height;
}

std::string ElevatorFloor::getLabel() {
    return this->label;
}

int ElevatorFloor::getHeight() {
    return this->height;
}

bool ElevatorFloor::isPressed() {
    return this->button.isPressed();
}

void ElevatorFloor::press() {
    this->button.press();
}

void ElevatorFloor::stop() {
    this->button.clear();
}
