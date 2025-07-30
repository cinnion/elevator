//
// Created by cinnion on 7/30/25.
//

#ifndef BUTTON_H
#define BUTTON_H

#include <atomic>

class Button {
public:
    bool                        isPressed();
    void                        press();
    void                        clear();

protected:
    std::atomic_bool            pressed{false};
};



#endif //BUTTON_H
