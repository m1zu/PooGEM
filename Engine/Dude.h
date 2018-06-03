#pragma once

#include "Graphics.h"
#include "Vec2D.h"


class Dude
{
public:
	Dude();

	void ControlKeyboard(const int up, const int down, const int left, const int right, const float dt);
	void ControlMouse(const Vec2D& pointerPos, const float dt);
	void ClampToScreen();
	void Draw(Graphics& gfx) const;

	float GetX() const;
	float GetY() const;

public:
	static constexpr float width = 20.0f;
	static constexpr float height = 20.0f;
	static constexpr float velocity = 120.0f;

private:
	Vec2D position;
};

