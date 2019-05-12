#pragma once
#include "Button.h"
#include <Font.h>
#include <Renderer2D.h>

using namespace aie;

class GameState
{
public:
	GameState();
	~GameState();

	virtual void Update(GameState** currentState);

	virtual void Draw(Renderer2D* r2d, Font* font);

	virtual void GetStates(GameState* titleScreen, GameState* playState, GameState* pauseState, GameState* leaderBoard);
};