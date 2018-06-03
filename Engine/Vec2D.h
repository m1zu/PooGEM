#pragma once


class Vec2D {
public:
	Vec2D() = default;
	Vec2D(const float x, const float y);
	
	Vec2D operator+(const Vec2D& rhs);
	Vec2D& operator+=(const Vec2D& rhs);
	Vec2D operator-(const Vec2D& rhs);
	Vec2D operator-=(const Vec2D& rhs);
	Vec2D operator*(const float rhs);
	Vec2D& operator*=(const float rhs);
	
	float GetLengthSq();
	float GetLength();
	Vec2D GetNormalized();
	Vec2D& Normalize();



private:
	float x;
	float y;
};