#include "PauseState.h"
#include <Application.h>
#include "SimonApp.h"

PauseState::PauseState()
{
	resumeButton = new Button("Resume", 640, 420, 250, 50);
	titleButton = new Button("Return to Title", 640, 360, 250, 50);
	quitButton = new Button("Quit Game", 640, 300, 250, 50);
}

PauseState::~PauseState()
{
	delete resumeButton;
	delete titleButton;
	delete quitButton;
}

void PauseState::Update(GameState ** currentState, float deltaTime)
{
	Input* input = input->getInstance();
	
	if (input->wasKeyReleased(INPUT_KEY_ESCAPE))
		*currentState = play;

	if (resumeButton->AABBCollision())
	{
		if (input->wasMouseButtonPressed(0))
		{
			simon->Reset();
			*currentState = play;
		}
	}
	else if (titleButton->AABBCollision())
	{
		if (input->wasMouseButtonPressed(0))
			*currentState = title;
	}
	else if (quitButton->AABBCollision())
	{
		if (input->wasMouseButtonPressed(0))
			quitGame = true;
	}
}

void PauseState::Draw(Renderer2D * r2d, Font * font)
{
	resumeButton->Draw(r2d, font);
	titleButton->Draw(r2d, font);
	quitButton->Draw(r2d, font);
}

void PauseState::GetStates(GameState * titleScreen, GameState * autoState, GameState * playState, GameState * pauseState, GameState * leaderBoard)
{
	title = titleScreen;
	play = playState;
	autopilot = autoState;
}
