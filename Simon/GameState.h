#pragma once
#include "Simon.h"
#include <Font.h>
#include <Renderer2D.h>

using namespace aie;

class GameState
{
public:
	GameState();
	~GameState();

	Simon* simon;

	bool quitGame = false;

	virtual void Update(GameState** currentState, float deltaTime);

	virtual void Draw(Renderer2D* r2d, Font* font, Font* big_font);

	virtual void GetStates(GameState* titleScreen, GameState* autoState, GameState* playState, GameState* pauseState, GameState* leaderBoard);
};