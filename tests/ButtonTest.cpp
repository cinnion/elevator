//
// Created by cinnion on 7/30/25.
//
#include <gtest/gtest.h>

#include "Button.h"
#include "../include/Button.h"

class ButtonFixture : public ::testing::Test {
protected:
    void SetUp() override {
    }

    Button                      button;
};

TEST_F(ButtonFixture, ButtonDefaultsToUnpressed) {
    // Assert
    EXPECT_FALSE(this->button.isPressed());
}

TEST_F(ButtonFixture, PressingMakesTrue) {
    // Arrange/Act
    this->button.press();

    // Assert
    EXPECT_TRUE(this->button.isPressed());
}

TEST_F(ButtonFixture, ClearingSetsBackToFalse) {
    // Arrange
    this->button.press();

    // Act
    this->button.clear();

    // Assert
    EXPECT_FALSE(this->button.isPressed());
}