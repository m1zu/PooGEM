#pragma once

#include "Dude.h"
#include "Graphics.h"

class Poo
{
public:
	Poo();

	void Init(const float in_x, const float in_y, const float in_vx, const float in_vy);
	void update(const Dude& dude, const float dt);
	bool IsEaten() const;
	void draw(Graphics& gfx);

private:
	void testCollision(const Dude& dude);

public:
	static constexpr float width = 24;
	static constexpr float height = 24;

private:
	float x, y;
	float vx, vy;
	bool isEaten = false;
	bool initialized = false;
};

