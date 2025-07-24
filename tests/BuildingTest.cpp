//
// Created by cinnion on 7/24/25.
//
#include <iostream>
#include <fstream>
#include <unistd.h>

#include <gtest/gtest.h>

#include "../includes/Building.h"

class BuildingFixture : public ::testing::Test {
protected:
    void SetUp() override {
        char                        buffer[256];

        if (getcwd(buffer, sizeof(buffer)) != nullptr) {
            std::cout << "CWD: " << buffer << std::endl;
        }

        std::ifstream configfile("../config.json");

        if (!configfile.is_open()) {
            GTEST_SKIP() << "Could not open config.json";
        }

        configfile >> config_;
    }

    Json::Value                 config_;
};

TEST_F(BuildingFixture, testFloorsLoaded) {
    // Arrange/act
    Building b(config_["Floors"]);

    // Assert
    EXPECT_EQ(b.building_floors.size(), 9);
    EXPECT_EQ(b.building_floors_map.size(), 9);

    EXPECT_EQ(b.building_floors_map.at(-30), "L3");
    EXPECT_EQ(b.building_floors.at("L3")->getLabel(), "L3");
    EXPECT_EQ(b.building_floors.at(b.building_floors_map.begin()->second)->getLabel(), "L3");

    EXPECT_EQ(b.building_floors_map.at(40), "5");
    EXPECT_EQ(b.building_floors.at("5")->getLabel(), "5");
    EXPECT_EQ(b.building_floors.at(b.building_floors_map.rbegin()->second)->getLabel(), "5");
}

TEST_F(BuildingFixture, testFloorsLoadedOrderCorrect) {
    // Arrange/act
    Building b(config_["Floors"]);

    // Assert
    EXPECT_EQ(b.building_floors_map.begin()->first, -30);
    EXPECT_EQ(b.building_floors_map.begin()->second, "L3");
    EXPECT_EQ(b.building_floors_map.rbegin()->first, 40);
    EXPECT_EQ(b.building_floors_map.rbegin()->second, "5");
}