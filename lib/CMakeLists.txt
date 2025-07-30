add_library(ElevatorLibrary SHARED
        Button.cpp
        Building.cpp
        ElevatorFloor.cpp
)

target_include_directories(ElevatorLibrary PUBLIC ${PROJECT_SOURCE_DIR}/include)
