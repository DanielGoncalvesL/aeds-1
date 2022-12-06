cmake_minimum_required(VERSION 3.0.0)
project(teste VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(teste src/segregation.cpp src/generateMatrix.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(teste SDL2main SDL2)
