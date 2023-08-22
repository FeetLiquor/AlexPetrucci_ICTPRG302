cmake_minimum_required(VERSION 3.8)
project(AlexPetrucci_ICTPRG302)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("libs/SFML-2.6.0")


add_executable(AlexPetrucci_ICTPRG302 main.cpp "Game.h" "config.h" "Game.cpp"   "State.h"  "StartState.h" "StartState.cpp" "ResourceManager.h" "ResourceManager.cpp" "State.cpp" "PlayState.h" "PlayState.cpp" "Player.h" "Player.cpp" "utils.h" "utils.cpp" "PauseState.h" "PauseState.cpp" "Bullet.h" "Bullet.cpp" "Asteroid.h" "Asteroid.cpp" "RNG.h" "RNG.cpp" "EndState.h" "EndState.cpp")

target_link_libraries(AlexPetrucci_ICTPRG302 sfml-graphics sfml-window sfml-system)

add_custom_command(TARGET AlexPetrucci_ICTPRG302 POST_BUILD
    COMMAND "${CMAKE_CURRENT_SOURCE_DIR}\\postBuild.bat"
)