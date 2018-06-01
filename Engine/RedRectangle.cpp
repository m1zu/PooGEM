#include "RedRectangle.h"
#include "Colors.h"


RedRectangle::RedRectangle()
	:
	rng(rd()),
	xDist(0, Graphics::ScreenWidth - width - 20),
	yDist(0, Graphics::ScreenHeight - height)
{
	x = xDist(rng);
	y = yDist(rng);
}

void RedRectangle::Update(const Dude & dude)
{
	if (x + width - 1 > dude.GetX()
		&& x < dude.GetX() + dude.width - 1
		&& y + height - 1 > dude.GetY()
		&& y < dude.GetY() + dude.height - 1)
	{
		x = xDist(rng);
		y = yDist(rng);
		bar.Increment();
	}

	if (colorCounter > 255 - 2 * std::abs(colorStep)
		|| colorCounter < 2 * std::abs(colorStep))
		colorStep *= (-1);
	colorCounter += colorStep;
}

void RedRectangle::Draw(Graphics & gfx) const
{
	for (int i = x; i < x + width; ++i)
		for (int j = y; j < y + height; ++j)
			gfx.PutPixel(i, j, 255, colorCounter, colorCounter);
	bar.Draw(gfx, colorCounter);
}
