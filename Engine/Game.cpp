/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	pix( gfx )
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> distX(0.0f, float(gfx.ScreenWidth) - Poo::width);
	std::uniform_real_distribution<float> distY(0.0f, float(gfx.ScreenHeight) - Poo::height);
	std::uniform_real_distribution<float> distVx(-180.0f, 180.0f);
	std::uniform_real_distribution<float> distVy(-180.0f, 180.0f);
	for (int i = 0; i < nPoos; ++i) {
		poo[i].Init(distX(rng), distY(rng), distVx(rng), distVy(rng));
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = frameTimer.Mark();
	if (wnd.kbd.KeyIsPressed(VK_RETURN))
		gameIsStarted = true;

	if (gameIsStarted) {
		controlCharacter(dt);
		processPoos(dt);
		redRec.Update(dude);
		testGameOver();
	}
}

void Game::ComposeFrame()
{	
	if (gameIsStarted)
	{
		if (gameIsOver)
			pix.drawGameOver(320, 240);
		else {
			dude.Draw(gfx);
			for (int i = 0; i < nPoos; ++i)
			{
				if (!poo[i].IsEaten()) poo[i].draw(gfx);
			}
			gfx.drawCircle(30, 30, 60, Colors::Gray);
			gfx.drawCircle(750, 300, 80, Colors::Gray);
			gfx.drawCircle(200, 500, 30, Colors::Gray);
			redRec.Draw(gfx);
		}
	}
	else
		pix.drawStart(320, 200);
}

void Game::controlCharacter(const float dt)
{
	const int left = wnd.kbd.KeyIsPressed(VK_LEFT);
	const int right = wnd.kbd.KeyIsPressed(VK_RIGHT);
	const int up = wnd.kbd.KeyIsPressed(VK_UP);
	const int down = wnd.kbd.KeyIsPressed(VK_DOWN);
	dude.Control(up, down, left, right, dt);
}

void Game::processPoos(const float dt) {
	for (int i = 0; i < nPoos; ++i) {
		poo[i].update(dude, dt);
	}
}

void Game::testGameOver() {
	for (int i = 0; i < nPoos; ++i)
		if (poo[i].IsEaten())
			gameIsOver = true;
}