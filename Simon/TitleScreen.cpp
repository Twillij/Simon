#include "TitleScreen.h"


TitleScreen::TitleScreen()
{
	playButton = new Button("Play", 640, 240, 250, 50);
	scoreButton = new Button("Coming Soon", 640, 180, 250, 50);
	quitButton = new Button("Quit Game", 640, 120, 250, 50);
}

TitleScreen::~TitleScreen()
{
	delete playButton;
	delete scoreButton;
	delete quitButton;
}

void TitleScreen::Update(GameState ** currentState, float deltaTime)
{
	Input* input = input->getInstance();
	
	if (playButton->AABBCollision())
	{
		if (input->wasMouseButtonPressed(0))
		{
			*currentState = play;
		}
	}
	else if (scoreButton->AABBCollision())
	{
		if (input->wasMouseButtonPressed(0))
			scoreButton->changeText("SOON TM");
	}
	else if (quitButton->AABBCollision())
	{
		if (input->wasMouseButtonPressed(0))
			quitGame = true;
	}
}

void TitleScreen::Draw(Renderer2D * r2d, Font * font, Font * big_font)
{
	r2d->setRenderColour(0.8f, 0.8f, 0.0f);
	r2d->drawText(big_font, "The Simon Game", 180, 480);

	playButton->Draw(r2d, font);
	scoreButton->Draw(r2d, font);
	quitButton->Draw(r2d, font);
}

void TitleScreen::GetStates(GameState * titleScreen, GameState * autoState, GameState * playState, GameState * pauseState, GameState * leaderBoard)
{
	play = playState;
	hiScore = leaderBoard;
}
