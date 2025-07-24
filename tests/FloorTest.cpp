#include <gtest/gtest.h>

#include "../includes/ElevatorFloor.h"

class FloorFixture : public ::testing::Test {
protected:
    void SetUp() override {

    }

    std::string floor_label = "L3";

    ElevatorFloor floor{"L3", -30};
};

TEST_F(FloorFixture, testLabel)
{
    EXPECT_EQ(floor.getLabel(),"L3");
}

TEST_F(FloorFixture, testHeight) {
    EXPECT_EQ(floor.getHeight(), -30);
}
