#include "PauseState.h"

PauseState::PauseState()
{
}

PauseState::~PauseState()
{
}

void PauseState::Update(GameState ** currentState, float deltaTime)
{
}

void PauseState::Draw(Renderer2D * r2d, Font * font)
{
}

void PauseState::GetStates(GameState * titleScreen, GameState * autoState, GameState * playState, GameState * pauseState, GameState * leaderBoard)
{
	title = titleScreen;
	play = playState;
	autopilot = autoState;
}
