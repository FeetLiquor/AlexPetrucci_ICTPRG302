cmake_minimum_required(VERSION 3.8)
project(AlexPetrucci_ICTPRG302)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("libs/SFML-2.6.0")

add_executable(AlexPetrucci_ICTPRG302 main.cpp)

target_link_libraries(AlexPetrucci_ICTPRG302 sfml-graphics sfml-window sfml-system)