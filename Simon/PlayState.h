#pragma once
#include "GameState.h"
#include "Simon.h"

class PlayState : public GameState
{
public:
	PlayState();
	~PlayState();

	Simon* simon;

	GameState* pause;

	void Update();

	void Draw(Renderer2D* r2d, Font* font);

	void GetStates(GameState* titleScreen, GameState* playState, GameState* pauseState, GameState* leaderBoard);
};

