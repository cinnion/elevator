add_library(ElevatorLibrary SHARED ElevatorFloor.cpp)

target_include_directories(ElevatorLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)