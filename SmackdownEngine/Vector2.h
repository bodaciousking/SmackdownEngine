#pragma once

struct Vector2
{
public:
	Vector2() : x(0.0f), y(0.0f) {}
	Vector2(float _x, float _y) : x(_x), y(_y){}

	float x, y;

	static float Dot(Vector2 v1, Vector2 v2) // has to be normalized
	{
		return ((v1.x*v2.x) + (v1.y * v2.y));
	}

	//Operators with other vectors
	Vector2 operator+(const Vector2& v) const 
	{
		return Vector2(x + v.x, y + v.y); 
	}
	Vector2 operator-(const Vector2& v) const 
	{ 
		return Vector2(x - v.x, y - v.y); 
	}
	Vector2 operator+=(const Vector2& v) const
	{
		float X = x + v.x, Y = v.y;
		return Vector2(X, Y);
	}
	Vector2 operator-=(const Vector2& v) const
	{
		float X = x - v.x, Y = y - v.y;
		return Vector2(X, Y);
	}
	Vector2 operator*(const Vector2& v) const 
	{
		return Vector2(x * v.x, y * v.y); 
	}
	Vector2 operator/(const Vector2& v) const
	{ 
		return Vector2(x / v.x, y / v.y); 
	}
	Vector2 operator*=(const Vector2& v) const
	{
		float X = x, Y = y;
		return Vector2(X *= v.x, Y *= v.y);
	}
	Vector2 operator/=(const Vector2& v) const
	{
		float X = x, Y = y;
		return Vector2(X /= v.x, Y /= v.y);
	}

	//Operators with floats
	Vector2 operator*(const float& f) const
	{ 
		return Vector2(x * f, y * f); 
	}
	Vector2 operator/(const float& f) const 
	{
		return Vector2(x * f, y * f);
	}

	//Comparisons
	bool operator==(const Vector2& v) const 
	{ 
		return (x == v.x && y == v.y); 
	}
	bool operator!=(const Vector2& v) const 
	{ 
		return !operator==(v); 
	}

};