#pragma once

#include "Dude.h"
#include "Graphics.h"

class Poo
{
public:
	Poo();

	void Init(int in_x, int in_y, int in_vx, int in_vy);
	void update(const Dude& dude);
	bool IsEaten() const;
	void draw(Graphics& gfx);

private:
	void testCollision(const Dude& dude);

public:
	static constexpr int width = 24;
	static constexpr int height = 24;

private:
	int x, y;
	int vx, vy;
	bool isEaten = false;
	bool initialized;
};

