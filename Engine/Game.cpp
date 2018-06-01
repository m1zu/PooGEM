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
	std::mt19937 rng;
	std::uniform_int_distribution<int> distX(0, gfx.ScreenWidth - Poo::width);
	std::uniform_int_distribution<int> distY(0, gfx.ScreenHeight - Poo::height);
	std::uniform_int_distribution<int> distVx(0, 3);
	std::uniform_int_distribution<int> distVy(0, 3);
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
	if (wnd.kbd.KeyIsPressed(VK_RETURN))
		gameIsStarted = true;

	if (gameIsStarted) {
		controlCharacter();
		processPoos();
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
			redRec.Draw(gfx);
			dude.Draw(gfx);
			for (int i = 0; i < nPoos; ++i)
			{
				if (!poo[i].IsEaten()) poo[i].draw(gfx);
			}
		}
	}
	else
		pix.drawStart(320, 200);
}

void Game::controlCharacter()
{
	const int left = wnd.kbd.KeyIsPressed(VK_LEFT);
	const int right = wnd.kbd.KeyIsPressed(VK_RIGHT);
	const int up = wnd.kbd.KeyIsPressed(VK_UP);
	const int down = wnd.kbd.KeyIsPressed(VK_DOWN);
	dude.Control(up, down, left, right);
}

void Game::processPoos() {
	for (int i = 0; i < nPoos; ++i) {
		poo[i].update(dude);
	}
}

void Game::testGameOver() {
	for (int i = 0; i < nPoos; ++i)
		if (poo[i].IsEaten())
			gameIsOver = true;
}