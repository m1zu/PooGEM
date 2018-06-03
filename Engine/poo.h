#pragma once

#include "Dude.h"
#include "Graphics.h"
#include "Vec2D.h"

class Poo
{
public:
	Poo();

	void Init(const Vec2D& pos_in, const Vec2D& vel_in);
	void update(const Dude& dude, const float dt);
	bool IsEaten() const;
	void draw(Graphics& gfx);

private:
	void testCollision(const Dude& dude);

public:
	static constexpr float width = 24;
	static constexpr float height = 24;

private:
	Vec2D position;
	Vec2D velocity;
	bool isEaten = false;
	bool initialized = false;
};

