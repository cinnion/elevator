add_library(ElevatorLibrary SHARED ElevatorFloor.cpp
        Building.cpp)

target_include_directories(ElevatorLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)