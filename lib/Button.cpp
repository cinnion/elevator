//
// Created by cinnion on 7/30/25.
//

#include "Button.h"

bool Button::isPressed() {
    return this->pressed.load((std::memory_order_acquire));
}

void Button::press() {
    return this->pressed.store(true, std::memory_order_release);
}

void Button::clear() {
    return this->pressed.store(false, std::memory_order_release);
}