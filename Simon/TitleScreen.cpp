#include "TitleScreen.h"


TitleScreen::TitleScreen()
{
	playButton = new Button("Play", 640, 180, 120, 50);
	scoreButton = new Button("Hi-Score", 640, 90, 120, 50);
}

TitleScreen::~TitleScreen()
{
	delete playButton;
	delete scoreButton;
}

void TitleScreen::Update(GameState** currentState)
{
	Input* input = input->getInstance();
	
	if (playButton->AABBCollision())
		if (input->wasMouseButtonPressed(0))
			*currentState = play;

	if (scoreButton->AABBCollision())
		if (input->wasMouseButtonPressed(0))
			*currentState = hiScore;
}

void TitleScreen::Draw(Renderer2D * r2d, Font * font)
{
	playButton->Draw(r2d, font);
	scoreButton->Draw(r2d, font);
}

void TitleScreen::GetStates(GameState * titleScreen, GameState * playState, GameState * pauseState, GameState * leaderBoard)
{
	play = playState;
	hiScore = leaderBoard;
}
