#include "StartState.h"
#include "PlayState.h"
#include "PauseState.h"
#include "EndState.h"


State* State::start = new StartState;
State* State::play = new PlayState;
State* State::pause = new PauseState;
State* State::end = new EndState;
State* State::current = State::start;