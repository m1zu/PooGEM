#pragma once

#include "Graphics.h"


class Dude
{
public:
	Dude();

	void Control(const int up, const int down, const int left, const int right, const float dt);
	void ClampToScreen();
	void Draw(Graphics& gfx) const;

	float GetX() const;
	float GetY() const;

public:
	static constexpr float width = 20.0f;
	static constexpr float height = 20.0f;

private:
	float x = 390.0f;
	float y = 290.0f;
};

