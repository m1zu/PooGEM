#include "RedRectBar.h"



RedRectBar::RedRectBar()
{
}


RedRectBar::~RedRectBar()
{
}

void RedRectBar::Increment()
{
	if (barOmeter < 20)
		barOmeter += 1;
}

void RedRectBar::Draw(Graphics& gfx, int colorCounter) const
{
	for (int c = 0; c < barOmeter; ++c)
		for (int i = x; i < x + segmentWidth; ++i)
			for (int j = y - c * segmentHeight; j < y + segmentHeight - c * segmentHeight; ++j)
				if (i == x
					|| i == x + segmentWidth - 1
					|| j == y - (barOmeter-1) * segmentHeight
					|| j == y + segmentWidth -1)

					gfx.PutPixel(i, j, 255, 255, 255);
				else
					gfx.PutPixel(i, j, 255, colorCounter / 2, colorCounter / 2);
}
