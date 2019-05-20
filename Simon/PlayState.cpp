#include "PlayState.h"


PlayState::PlayState()
{
	simon = new Simon();
}

PlayState::~PlayState()
{
	delete simon;
}

void PlayState::Update(GameState ** currentState, float deltaTime)
{
	Input* input = input->getInstance();

	if (input->wasKeyReleased(INPUT_KEY_ESCAPE))
		*currentState = pause;

	snprintf(simon->levelIndicator, 10, "Level: %i", simon->level);
	snprintf(simon->sequenceIndicator, 10, "(%i/%i)", simon->currentSequence, simon->level);
	snprintf(simon->lifeIndicator, 10, "Life: %i", simon->life);

	if (simon->sequenceButton->AABBCollision())
		if (input->wasMouseButtonPressed(0))
		{
			if (simon->level == 0)
				simon->sequenceButton->changeText("Next Level");
			
			if (simon->wrong)
			{
				simon->wrong = false;
				simon->level--;
			}

			simon->level++;
			simon->GenSeries();
			simon->currentSequence = 0;
			*currentState = autopilot;
		}
	
	if (!simon->playMode)
		return;

	if (simon->button[0]->AABBCollision())
	{
		if (input->wasMouseButtonPressed(0))
		{
			simon->CheckInput(simon->memory->getArray()[simon->currentSequence], 0);
		}
	}
	else if (simon->button[1]->AABBCollision())
	{
		if (input->wasMouseButtonPressed(0))
		{
			simon->CheckInput(simon->memory->getArray()[simon->currentSequence], 1);
		}
	}
	else if (simon->button[2]->AABBCollision())
	{
		if (input->wasMouseButtonPressed(0))
		{
			simon->CheckInput(simon->memory->getArray()[simon->currentSequence], 2);
		}
	}
	else if (simon->button[3]->AABBCollision())
	{
		if (input->wasMouseButtonPressed(0))
		{
			simon->CheckInput(simon->memory->getArray()[simon->currentSequence], 3);
		}
	}

	if (simon->life == 0)
	{
		simon->timer = 3;
		*currentState = autopilot;
	}

	if (simon->currentSequence >= simon->level)
	{
		simon->playMode = false;

		for (int i = 0; i < 4; ++i)
			simon->button[i]->flash = false;
	}
}

void PlayState::Draw(Renderer2D * r2d, Font * font, Font * big_font)
{
	r2d->drawSprite(simon->button[0]->colour, simon->button[0]->clickable.posX, simon->button[0]->clickable.posY);
	r2d->drawSprite(simon->button[1]->colour, simon->button[1]->clickable.posX, simon->button[1]->clickable.posY);
	r2d->drawSprite(simon->button[2]->colour, simon->button[2]->clickable.posX, simon->button[2]->clickable.posY);
	r2d->drawSprite(simon->button[3]->colour, simon->button[3]->clickable.posX, simon->button[3]->clickable.posY);

	r2d->drawText(font, simon->levelIndicator, 0, 690);
	r2d->drawText(font, "Press ESC to pause", 0, 0);

	if (simon->currentSequence == simon->level && simon->level != 0)
	{
		r2d->drawText(big_font, "Level Clear!", 240, 360);
	}

	if (simon->wrong)
	{
		r2d->drawText(big_font, "Try again!", 300, 360);
	}

	if (!simon->playMode)
	{
		simon->sequenceButton->Draw(r2d, font);
		return;
	}
	
	if (simon->button[0]->flash)
		r2d->drawSprite(simon->button[0]->litColour, simon->button[0]->clickable.posX, simon->button[0]->clickable.posY);
	else if (simon->button[1]->flash)
		r2d->drawSprite(simon->button[1]->litColour, simon->button[1]->clickable.posX, simon->button[1]->clickable.posY);
	else if (simon->button[2]->flash)
		r2d->drawSprite(simon->button[2]->litColour, simon->button[2]->clickable.posX, simon->button[2]->clickable.posY);
	else if (simon->button[3]->flash)
		r2d->drawSprite(simon->button[3]->litColour, simon->button[3]->clickable.posX, simon->button[3]->clickable.posY);

	r2d->drawText(font, "Sequence", 128, 375);
	r2d->drawText(font, simon->sequenceIndicator, 128, 345);

	r2d->drawText(font, simon->lifeIndicator, 1020, 360);
}

void PlayState::GetStates(GameState * titleScreen, GameState * autoState, GameState * playState, GameState * pauseState, GameState * leaderBoard)
{
	title = titleScreen;
	autopilot = autoState;
	pause = pauseState;
}
