#include "Vec2D.h"
#include "cmath"

Vec2D::Vec2D(const float x, const float y)
	:
	x(x),
	y(y)
{
}

Vec2D Vec2D::operator+(const Vec2D & rhs)
{
	return Vec2D(x + rhs.x, y + rhs.y);
}

Vec2D& Vec2D::operator+=(const Vec2D & rhs)
{
	return *this = *this + rhs;
}

Vec2D Vec2D::operator-(const Vec2D & rhs)
{
	return Vec2D(x - rhs.x, y - rhs.y);
}

Vec2D Vec2D::operator-=(const Vec2D & rhs)
{
	return *this = *this - rhs;
}

Vec2D Vec2D::operator*(const float rhs)
{
	return Vec2D(x*rhs, y*rhs);
}

Vec2D & Vec2D::operator*=(const float rhs)
{
	return *this = *this * rhs;
}

float Vec2D::GetLengthSq()
{
	return x*x+y*y;
}

float Vec2D::GetLength()
{
	return std::sqrt(GetLengthSq());
}

Vec2D Vec2D::GetNormalized()
{
	const float len = GetLength();
	return Vec2D(x/len, y/len);
}

Vec2D & Vec2D::Normalize()
{
	return *this = *this * (1/GetLength());
}

