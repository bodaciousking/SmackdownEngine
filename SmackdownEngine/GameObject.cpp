#include "GameObject.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;



void GameObject::Start()
{
	for (std::vector<GameObject*>::iterator i = v_Children.begin(); i != v_Children.end(); i++)
	{
		(*i)->Start();
	}
}


void GameObject::Update(sf::Time deltaTime)
{
	if (v_Parent)
	{
		worldTransform = v_Parent->worldTransform * v_Transform->transformMatrix;
	}

	else
	{
		worldTransform = v_Transform->transformMatrix;
	}

	v_Transform->Update();
	v_Render->UpdatePosition();
	for (std::vector<GameObject*>::iterator i = v_Children.begin(); i != v_Children.end(); i++)
	{
		(*i)->Update(deltaTime);
	}
}



void GameObject::SetParent(GameObject& parent)
{
	v_Parent = &parent;
}

void GameObject::AddChild(GameObject* child)
{
	v_Children.push_back(child);
}

void GameObject::setFont(std::string _string)
{
	font.loadFromFile(_string);
	text.setFont(font);
}

sf::Text GameObject::getText()
{
	return text;
}

void GameObject::setString(std::string _string, int size, sf::Color c)
{
	text.setString(_string);
	text.setCharacterSize(size);
	text.setFillColor(c);
}

void GameObject::setSprite(sf::Texture Texture)
{
	sprite.setTexture(Texture);

}

sf::Sprite GameObject::getSprite()
{
	return sprite;
}

void GameObject::setTexture(std::string url)
{
	texture.loadFromFile(url);
	sprite.setTexture(texture);
}

sf::Texture GameObject::getTexture()
{
	return texture;
}

void GameObject::saveTextureRect(int i, float _left, float _top, float _width, float _height)
{
	//left[i] = _left; top[i] = _top; width[i] = _width; height[i] = _height;
	//sf::IntRect r(left[i], top[i], width[i], height[i]);
	sf::IntRect r(_left, _top, _width, _height);
	rect[i] = r;

}

void GameObject::setTextureRect(int i)
{
		sprite.setTextureRect(rect[i]);
}


sf::IntRect GameObject::getTextureRect(int i)
{
	return rect[i];
}

void GameObject::setScale(float x, float y)
{
	xScale = x;
	yScale = y;
	sprite.setScale(xScale, yScale);
}

float GameObject::getScale()
{
	return xScale, yScale;
}

float GameObject::getScaleX()
{
	return xScale;
}

float GameObject::getScaleY()
{
	return yScale;
}

void GameObject::setPosition(float x, float y)
{
	xPos = x;
	yPos = y;
	sprite.setPosition(x, y);
	text.setPosition(x,y);
}

float GameObject::getPositionX()
{
	return sprite.getPosition().x;
}

float GameObject::getPositionY()
{
	return sprite.getPosition().y;
}

void GameObject::pinOrigin()
{
	sprite.setOrigin(sprite.getLocalBounds().width/2, 0);
}


void GameObject::animate(int i, float start, float end, float x, bool repeat)
{
	


	seconds = Clock.getElapsedTime().asSeconds();

	if (seconds >= 0.1f)
	{
		if (rect[i].left >= end && repeat == true)
			rect[i].left = start;
		else if (rect[i].left >= end && repeat == false)
			rect[i].left = end;
		else
			rect[i].left += x;

		Clock.restart();
	}

	sprite.setTextureRect(rect[i]);
}

float GameObject::getTime()
{
	return seconds;
}

void GameObject::resetClock()
{
	Clock.restart();
}

void GameObject::move(float speedX, float speedY, bool animated)
{
	sf::Clock _Clock;
	float _seconds;
	_seconds = _Clock.getElapsedTime().asSeconds();
	if (animated == true)
	{
		if (seconds >= 0.1f)
		{
			sprite.setPosition(sprite.getPosition().x + speedX, sprite.getPosition().y + speedY);
			_Clock.restart();
		}
	}

	else
		sprite.setPosition(sprite.getPosition().x + speedX, sprite.getPosition().y + speedY);		
}

sf::FloatRect GameObject::getCollisionBox()
{
	return sprite.getGlobalBounds();
}

bool GameObject::collided(sf::FloatRect otherBox)
{
	if(sprite.getGlobalBounds().intersects(otherBox))
		return true;
	else
		return false;
}

