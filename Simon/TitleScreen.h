#pragma once
#include "GameState.h"

class TitleScreen : public GameState
{
public:
	TitleScreen();
	~TitleScreen();
	
	GameState* play;
	GameState* hiScore;

	Button* playButton;
	Button* scoreButton;

	void Update(GameState** currentState);

	void Draw(Renderer2D* r2d, Font* font);

	void GetStates(GameState* titleScreen, GameState* playState, GameState* pauseState, GameState* leaderBoard);
};