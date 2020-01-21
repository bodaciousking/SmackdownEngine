#pragma once
class vec2
{
public:
	vec2(double x0 = 0.0, double y0 = 0.0)
		: _x(x0), _y(y0)
	{}
	vec2(const vec2 &v)
		: _x(v._x), _y(v._y)
	{}
	/*
	bool operator==(const vec2 &v) const
	{
		return (v[0] == v[1]);
	}
	*/
	bool operator==(const vec2 &v) const
	{
		return (_x == v._x && _y == v._y);
	}
	bool operator!=(const vec2 &v)
	{
		return !(*this == v);
	}
	double operator[](int i) const
	{
		return(i == 0 ? _x : _y);
	}
	double & operator[](int i)
	{
		return(i == 0 ? _x : _y);
	}
	double get_x()
	{
		return _x;
	}
	double get_y()
	{
		return _y;
	}
	vec2 operator+() const  //positive of
	{
		return *this;
	}
	vec2 operator+(const vec2 &v) const
	{
		return vec2(_x + v._x, _y + v._y);
	}
	vec2 & operator+=(const vec2 &v)
	{
		_x += v._x;
		_y += v._y;
		return *this;
	}
	vec2 operator-(const vec2 &v) const
	{
		return *this + -v;
	}
	vec2 & operator-=(const vec2 &v)
	{
		_x -= v._x;
		_y -= v._y;
		return *this;
	}
	vec2 operator-() const  //negative of
	{
		return vec2(-_x, -_y);
	}
	vec2 operator*(const double c) const
	{
		return vec2(_x * c, _y * c);
	}
	vec2 & operator*=(double c)
	{
		_x *= c;
		_y *= c;
		return *this;
	}
	vec2 operator/(const double c) const
	{
		return vec2(_x / c, _y / c);
	}
	vec2 & operator/=(const double c)
	{
		*this = *this / c;
		return *this;
	}

private:
	double _x, _y;
};

