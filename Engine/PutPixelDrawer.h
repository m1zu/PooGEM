#pragma once

#include "Graphics.h"

class PutPixelDrawer
{
public:
	PutPixelDrawer(Graphics& gfx);
	~PutPixelDrawer();

	void drawStart(const int x, const int y);
	void drawGameOver(const int x, const int y);

private:
	Graphics & gfx;
};

