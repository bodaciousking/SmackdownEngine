#include "SmackdownEngine.h"

Input input;
SmackdownEngine engine;

int main()
{
	
	engine.CheckSystemReqs();
	while (engine.v_Window.isOpen())
	{
		engine.Start();



		if (input.esc())
			engine.v_Window.close();
	}

	return EXIT_SUCCESS;
}