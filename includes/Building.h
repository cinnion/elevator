//
// Created by cinnion on 7/24/25.
//

#ifndef BUILDING_H
#define BUILDING_H

#include <map>
#include <string>
#include <json/json.h>

#include "ElevatorFloor.h"

class Building {
private:

public:
    Building(Json::Value& floor_json);

    std::map<std::string, ElevatorFloor *> building_floors;
    std::map<int, std::string>     building_floors_map;
};

#endif //BUILDING_H
