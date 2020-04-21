#pragma once

class Input
{
public:
	bool R();
	bool A();
	bool S();
	bool D();
	bool W();
	bool left();
	bool right();
	bool down();
	bool up();
	bool esc();
	bool enter();
	bool space();

private:
	bool enterKeyPressed = false;
	bool enterKeyReleased = true;
};

