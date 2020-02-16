#include "SmackdownEngine.h"
#include "Input.h"

bool Input::space()
{

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		return true;
	}

}

bool Input::A()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input::D()
{
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input::W()
{
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input::S()
{
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input::left()
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		return true;
	}
	else
	{
		return false;
	}
}



bool Input::right()
{

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		return true;
	}
	else
	{
		return false;
	}
}



bool Input::up()
{
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input::down()
{
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input::enter()
{
	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		return true;
	}
}

bool Input::esc()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		return true;
	}
}