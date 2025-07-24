//
// Created by cinnion on 7/23/25.
//
#include "../includes/ElevatorFloor.h"

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
    return this->pressed.load((std::memory_order_acquire));
}

void ElevatorFloor::press() {
    return this->pressed.store(true, std::memory_order_release);
}

void ElevatorFloor::stop() {
    return this->pressed.store(false, std::memory_order_release);
}

