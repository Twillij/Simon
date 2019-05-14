#pragma once
#include "GameState.h"
class PauseState : public GameState
{
public:
	PauseState();
	~PauseState();
	
	GameState* title;
	GameState* play;
	GameState* autopilot;
	
	void Update(GameState** currentState, float deltaTime);

	void Draw(Renderer2D* r2d, Font* font);

	void GetStates(GameState* titleScreen, GameState* autoState, GameState* playState, GameState* pauseState, GameState* leaderBoard);
};