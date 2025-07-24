//
// Created by cinnion on 7/23/25.
//

#ifndef FLOOR_H
#define FLOOR_H

#include <string>
#include <atomic>

class ElevatorFloor {
public:
    explicit ElevatorFloor(std::string label, int height);

    std::string                 getLabel();
    int                         getHeight();

    bool                        isPressed();
    void                        press();
    void                        stop();

protected:
    int                         height;
    std::string                 label;
    std::atomic_bool            pressed{false};
};

#endif //FLOOR_H
