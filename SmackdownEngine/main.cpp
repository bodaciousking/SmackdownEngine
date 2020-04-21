#include "SmackdownEngine.h"
#include "GameObject.h"
#include "Audio.h"


Input input;
SmackdownEngine engine;
GameObject player;
GameObject menu;
GameObject game;
GameObject results;
GameObject text;
GameObject mainText;
GameObject resultsText;

SCENE scene = SPLASH;

GameObject apple;
GameObject banana;
GameObject melon;

Audio bgMusic;
Audio slash;
Audio swing;

bool collApple = false;
bool collBanana = false;
bool collMelon = false;

int score;
int maxFruits = 10;

int GAME_STATE;

void setScore(int i)
{
	score = i + 1;
}

int getScore()
{
	return score;
}

void reset()
{
	score = 0;
	player.setPosition(500,500);
	apple.setPosition(700, -500);
	banana.setPosition(1200, -700);
	melon.setPosition(1900, -900);
}

void collResolution()
{
	slash.playSound(100, false);
	setScore(score);
	if (score >= 10)
		score = 10;
}

int main()
{
	
	engine.CheckSystemReqs();

	text.setFont("../Assets/SIXTY.ttf");
	mainText.setFont("../Assets/SIXTY.ttf");
	resultsText.setFont("../Assets/SIXTY.ttf");

	bgMusic.setTrack("../Assets/Yakuza.wav");
	bgMusic.playMusic(50, true);

	slash.setBuffer("../Assets/slash.wav");

	apple.setTexture("../Assets/apple.png");
	apple.setScale(0.5, 0.5);
	apple.setPosition(700,500);

	banana.setTexture("../Assets/banana.png");
	banana.setScale(1, 1);

	melon.setTexture("../Assets/melon.png");
	melon.setScale(0.25, 0.25);

	player.saveTextureRect(0, 20, 50, 46, 75);
	player.saveTextureRect(1, 10, 120, 65, 75);
	


	while (engine.isRunning())
	{

		//engine.Start();
		engine.clearWindow();
		if (input.esc())
			engine.close();

		switch (GAME_STATE)
		{
		case SPLASH:
			scene = SPLASH;

			//v_Window.clear(Color::Black);
			engine.clearWindow();
			menu.setTexture("../Assets/splash.jpg");
			menu.setScale(3, 3);
			mainText.setString("Press Enter to continue", 75, text.color.Green);
			mainText.setPosition(700, 1000);
			engine.draw(menu.getSprite());
			engine.draw(mainText.getText());
			reset();

			if (input.enter())
			{
				GAME_STATE = GAME;
			}
			break;

		case GAME:
			scene = GAME;

			text.setString("You have slashed through " + engine.intToString(getScore()) + " out of " + engine.intToString(maxFruits) + " Fruits!", 100, text.color.Green);

			if (collApple == false)
				engine.draw(apple.getSprite());
			if (collBanana == false)
				engine.draw(banana.getSprite());
			if (collMelon == false)
				engine.draw(melon.getSprite());

			engine.draw(text.getText());

			player.pinOrigin();
			float speed;

			engine.draw(player.getSprite());
			apple.move(0, 20, false);
			banana.move(0, 20, false);
			melon.move(0, 20, false);

			if (apple.getPositionY() >= 1500)
				apple.setPosition(700, -500);
			if (banana.getPositionY() >= 1500)
				banana.setPosition(1200, -700);
			if (melon.getPositionY() >= 1500)
				melon.setPosition(1900, -900);

			if (input.right() || input.left() || input.A() || input.D())
			{
				player.setTexture("../Assets/Ninja Run.png");

				player.setScale(10, 10);
				player.animate(0, 20, 170, 50, true);
				player.move(speed, 0, true);
			}

			if (input.right() || input.D())
			{
				player.setScale(10, 10);
				speed = 150;
			}
			else if (input.left() || input.A())
			{
				player.setScale(-10, 10);
				speed = -150;
			}

			else if (input.space())
			{
				player.setScale(11, 11);
				player.setTexture("../Assets/Ninja Attack.png");

				player.animate(1, 10, 360, 70, true);

				if (player.collided(apple.getCollisionBox()) == true)
				{
					apple.setPosition(700, -500);
					collResolution();
				}
				if (player.collided(banana.getCollisionBox()) == true)
				{
					banana.setPosition(1200, -500);
					collResolution();
				}
				if (player.collided(melon.getCollisionBox()) == true)
				{
					melon.setPosition(1900, -500);
					collResolution();
				}
			}

			else {
				player.setScale(11, 11);
				player.setTexture("../Assets/Ninja Attack.png");
				player.animate(1, 10, 10, 0, true);
			}


			if (score >= 10)
				GAME_STATE = RESULTS;
			else if(input.R())
				GAME_STATE = SPLASH;

			break;

		case RESULTS:
			scene = RESULTS;
			engine.clearWindow();
			results.setTexture("../Assets/Results.jpg");
			results.setScale(3.5,3.5);
			resultsText.setString("Your wrath was show towards 10 out of " + engine.intToString(maxFruits) + " Fruits!\n              Press Enter to Restart Level!", 75, text.color.Blue);
			resultsText.setPosition(700, 1000);
			engine.draw(results.getSprite());
			engine.draw(resultsText.getText());

			reset();
			if (input.enter())
				GAME_STATE = GAME;
			else if (input.R())
				GAME_STATE = SPLASH;
			break;

		default:
			break;
		}

		engine.displayWindow();
}

	

	return EXIT_SUCCESS;
}

