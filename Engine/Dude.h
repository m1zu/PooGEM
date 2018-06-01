#pragma once

#include "Graphics.h"


class Dude
{
public:
	Dude();

	void Control(const int up, const int down, const int left, const int right);
	void ClampToScreen();
	void Draw(Graphics& gfx) const;

	int GetX() const;
	int GetY() const;

public:
	static constexpr int width = 20;
	static constexpr int height = 20;

private:
	int x = 390;
	int y = 290;
};

