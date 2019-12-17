#pragma once
#include "BasicState.h"
#include <unordered_map>
#include <string>

class StateMachine
{
	std::unordered_map <std::string, BasicState*> states;
	BasicState* current;
public:
	StateMachine();
	void change(std::string);
	void update();
	void render();
	~StateMachine();
};
