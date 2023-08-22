cmake_minimum_required(VERSION 3.8)
project(AlexPetrucci_ICTPRG302)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("libs/SFML-2.6.0")


add_executable(${PROJECT_NAME} main.cpp "Game.h" "config.h" "Game.cpp"   "State.h"  "StartState.h" "StartState.cpp" "ResourceManager.h" "ResourceManager.cpp" "State.cpp" "PlayState.h" "PlayState.cpp" "Player.h" "Player.cpp" "utils.h" "utils.cpp" "PauseState.h" "PauseState.cpp" "Bullet.h" "Bullet.cpp" "Asteroid.h" "Asteroid.cpp" "RNG.h" "RNG.cpp" "EndState.h" "EndState.cpp") 
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

if (WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND "${CMAKE_CURRENT_SOURCE_DIR}\\postBuild.bat"
    )
endif()