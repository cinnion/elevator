//
// Created by cinnion on 7/24/25.
//
#include "Building.h"

Building::Building(Json::Value &floor_json) {
    Json::Value::Members members = floor_json.getMemberNames();
    for (std::string &memberName: members) {
        int height = std::atoi(floor_json[memberName]["height"].asCString());
        ElevatorFloor *newfloor = new ElevatorFloor(memberName, height);
        building_floors.emplace(memberName, newfloor);
        building_floors_map[height] = memberName;
    }
}
