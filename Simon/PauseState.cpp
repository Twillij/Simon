#include "PauseState.h"

PauseState::PauseState()
{
	resumeButton = new Button("Resume", 640, 420, 120, 50);
	quitButton = new Button("Quit", 640, 300, 120, 50);
}

PauseState::~PauseState()
{
}

void PauseState::Update(GameState ** currentState, float deltaTime)
{
	Input* input = input->getInstance();
	
	if (input->wasKeyReleased(INPUT_KEY_ESCAPE))
		*currentState = play;

	if (resumeButton->AABBCollision())
		if (input->wasMouseButtonPressed(0))
			*currentState = play;

	//if quit

}

void PauseState::Draw(Renderer2D * r2d, Font * font)
{
	resumeButton->Draw(r2d, font);
	quitButton->Draw(r2d, font);
}

void PauseState::GetStates(GameState * titleScreen, GameState * autoState, GameState * playState, GameState * pauseState, GameState * leaderBoard)
{
	title = titleScreen;
	play = playState;
	autopilot = autoState;
}
