#include "SmackdownEngine.h"

Input input;
SmackdownEngine engine;

int main()
{
	while (engine.v_Window.isOpen())
	{
		//Welcome to our engine! here you can start a new scene and fill it with gameobjects and whatever else you can imagine as long as its within our very tight constraints!


		engine.v_SplashTexture.loadFromFile("../Assets/Splash.jpg");
		engine.v_SplashSprite.setTexture(engine.v_SplashTexture);


		engine.v_Window.clear(Color::Black);
		engine.v_Window.draw(engine.v_SplashSprite);















		engine.v_Window.display();

		if (input.esc())
			engine.v_Window.close();
	}

	return EXIT_SUCCESS;
}