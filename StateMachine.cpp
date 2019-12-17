#include "StateMachine.h"
#include "assert.h"

StateMachine::StateMachine() {
	states["basic"] = new BasicState();
	current = states["basic"];
}

void StateMachine::change(std::string newStateName) {
	current->exit();
	assert(states[newStateName] != nullptr);
	current = states[newStateName];
	current->enter();
}

void StateMachine::update() {
	current->update();
}

void StateMachine::render() {
	current->render();
}

StateMachine::~StateMachine() {
	for (auto state : states)
		delete state.second;
}
