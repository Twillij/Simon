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
	Button* quitButton;

	void Update(GameState** currentState, float deltaTime);

	void Draw(Renderer2D * r2d, Font * font, Font * big_font);

	void GetStates(GameState* titleScreen, GameState* autoState, GameState* playState, GameState* pauseState, GameState* leaderBoard);
};