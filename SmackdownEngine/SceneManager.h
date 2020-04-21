#pragma once


	enum SCENE
	{
		SPLASH,
		MENU,
		GAME,
		RESULTS

	};

	class SceneManager
	{
	public:
	void addScene(int i, SCENE scene);
	void changeScene(SCENE scene);
	SCENE getScene(int i);
};