#pragma once
#include "GameState.h"
#include "Simon.h"

class PlayState : public GameState
{
public:
	PlayState();
	~PlayState();

	char level[10];
	char correctSequence[20];

	GameState* title;
	GameState* autopilot;
	GameState* pause;

	Button* sequenceButton;

	void Update(GameState** currentState, float deltaTime);

	void Draw(Renderer2D* r2d, Font* font);

	void GetStates(GameState* titleScreen, GameState* autoState, GameState* playState, GameState* pauseState, GameState* leaderBoard);
};

