#pragma once

#include "Graphics.h"
#include "Dude.h"
#include "RedRectBar.h"
#include <random>

class RedRectangle
{
public:
	RedRectangle();

	void Update(const Dude& dude);
	void Draw(Graphics& gfx) const;

private:
	static constexpr int width = 20;
	static constexpr int height = 20;
	int x;
	int y;
	int colorStep = 6;
	int colorCounter = 50;

	RedRectBar bar;

	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
};

