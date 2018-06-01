#pragma once

#include "Graphics.h"

class RedRectBar
{
public:
	RedRectBar();
	~RedRectBar();

	void Increment();
	void Draw(Graphics& gfx, int colorCounter) const;

private:
	static constexpr int segmentWidth = 20;
	static constexpr int segmentHeight = 20;
	int x = Graphics::ScreenWidth - 30;
	int y = Graphics::ScreenHeight - 30;
	int barOmeter = 0;
};

