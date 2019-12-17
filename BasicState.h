#pragma once
class BasicState
{
public:
	BasicState();
	virtual void enter();
	virtual void exit();
	virtual void update();
	virtual void render();
};

