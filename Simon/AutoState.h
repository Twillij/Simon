#pragma once
#include "GameState.h"

class AutoState : public GameState
{
public:
	AutoState();
	~AutoState();

	bool ready = false;

	GameState* play;
	Button* phase;

	void Update(GameState** currentState, float deltaTime);

	void Draw(Renderer2D* r2d, Font* font);

	void GetStates(GameState* titleScreen, GameState* autoState, GameState* playState, GameState* pauseState, GameState* leaderBoard);
};

