#pragma once
#include "GameState.h"
#include "Simon.h"

class PlayState : public GameState
{
public:
	PlayState();
	~PlayState();
	
	GameState* title;
	GameState* autopilot;
	GameState* pause;
	GameState* gameloss;

	void Update(GameState** currentState, float deltaTime);

	void Draw(Renderer2D * r2d, Font * font, Font * big_font);

	void GetStates(GameState* titleScreen, GameState* autoState, GameState* playState, GameState* pauseState, GameState* leaderBoard);
};