#pragma once
#ifndef GAMEOBJECv_H
#define GAMEOBJECv_H

#pragma once
#include <vector>
#include <list>
#include <iterator>
#include <string>

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Texture.hpp>


#include "Vector2.h"
#include "BaseComponent.h"
#include "TransformComponent.h"
#include "RenderComponent.h"

class GameObject
{
private:
	GameObject* v_Parent;
	std::vector<GameObject*> v_Children;

	sf::Text text;
	sf::Font font;

	sf::Texture v_Texture;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::IntRect rect[10];
	sf::Clock Clock;
	float seconds;

	float left[10]; 
	float top[10];
	float width[10];
	float height[10];

	sf::Transform identityMatrix;
	sf::Transform worldTransform;

	float xScale;
	float yScale;
	float xPos;
	float yPos;

public:
	TransformComponent* v_Transform;
	RenderComponent* v_Render;

	int v_ID;

	GameObject() {}
	GameObject(int objID, sf::Texture texture, bool isKinematic, sf::Vector2f pos) : v_ID(objID), v_Parent(NULL), v_Texture(texture)
	{
		v_Transform = new TransformComponent();
		v_Transform-> v_Position = pos;
		v_Render = new RenderComponent(v_Transform, v_Texture);
		v_Render->Start();
	}

	void SetParent(GameObject& parent);
	void AddChild(GameObject* child);

	void Start();
	void Update(sf::Time deltaTime);


	void setFont(std::string _string);
	sf::Text getText();
	void setString(std::string _string, int size, sf::Color c);




	sf::Color color;
	void setSprite(sf::Texture Texture);
	sf::Sprite getSprite();
	void setTexture(std::string url);
	sf::Texture getTexture();
	void saveTextureRect(int i, float _left, float _top, float _width, float _height);
	void setTextureRect(int i);
	sf::IntRect getTextureRect(int i);

	void setScale(float x, float y);
	float getScale();
	float getScaleX();
	float getScaleY();

	void setPosition(float x, float y);
	float getPositionX();
	float getPositionY();
	void pinOrigin();
	void animate(int i, float start, float end, float x, bool repeat);
	float getTime();
	void resetClock();
	void move(float speedX, float speedY, bool animated);
	sf::FloatRect getCollisionBox();
	bool collided(sf::FloatRect otherBox);

	

};

#endif