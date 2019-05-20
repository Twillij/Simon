#include "AutoState.h"


AutoState::AutoState()
{
	//phase = new Button("Sequence Phase", 640, 360, 1280, 50);
}

AutoState::~AutoState()
{
	//delete phase;
}

void AutoState::Update(GameState ** currentState, float deltaTime)
{
	if (simon->life <= 0)
	{
		if (simon->timer <= 0)
		{
			simon->Reset();
			*currentState = title;
		}

		simon->timer -= deltaTime;
		return;
	}
	
	int colour = simon->memory->getArray()[simon->currentSequence];
	
	snprintf(simon->levelIndicator, 10, "Level: %i", simon->level);

	if (simon->timer > 0.2)
		simon->button[colour]->flash = true;
	else
		simon->button[colour]->flash = false;

	if (simon->timer <= 0)
	{
		simon->currentSequence++;

		simon->timer = 1;

		if (simon->currentSequence == simon->level && !simon->life == 0)
		{
			simon->currentSequence = 0;
			simon->playMode = true;
			*currentState = play;
		}
	}

	simon->timer -= deltaTime;
	//cout << simon->timer << endl;
}

void AutoState::Draw(Renderer2D * r2d, Font * font, Font * big_font)
{	
	r2d->drawText(font, simon->levelIndicator, 0, 690);
	
	r2d->drawSprite(simon->button[0]->colour, simon->button[0]->clickable.posX, simon->button[0]->clickable.posY);
	r2d->drawSprite(simon->button[1]->colour, simon->button[1]->clickable.posX, simon->button[1]->clickable.posY);
	r2d->drawSprite(simon->button[2]->colour, simon->button[2]->clickable.posX, simon->button[2]->clickable.posY);
	r2d->drawSprite(simon->button[3]->colour, simon->button[3]->clickable.posX, simon->button[3]->clickable.posY);

	if (simon->button[0]->flash)
		r2d->drawSprite(simon->button[0]->litColour, simon->button[0]->clickable.posX, simon->button[0]->clickable.posY);
	else if (simon->button[1]->flash)
		r2d->drawSprite(simon->button[1]->litColour, simon->button[1]->clickable.posX, simon->button[1]->clickable.posY);
	else if (simon->button[2]->flash)
		r2d->drawSprite(simon->button[2]->litColour, simon->button[2]->clickable.posX, simon->button[2]->clickable.posY);
	else if (simon->button[3]->flash)
		r2d->drawSprite(simon->button[3]->litColour, simon->button[3]->clickable.posX, simon->button[3]->clickable.posY);

	if (simon->life == 0)
	{
		r2d->drawText(big_font, "Oops!", 480, 480);
		r2d->drawText(big_font, "You lose.", 330, 240);
	}
}

void AutoState::GetStates(GameState * titleScreen, GameState * autoState, GameState * playState, GameState * pauseState, GameState * leaderBoard)
{
	title = titleScreen;
	play = playState;
}
