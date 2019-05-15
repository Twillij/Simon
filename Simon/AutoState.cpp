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
	int colour = simon->memory->getArray()[simon->currentSequence];
	
	if (simon->timer > 0.3)
		simon->button[colour]->flash = true;
	else
		simon->button[colour]->flash = false;

	if (simon->timer <= 0)
	{
		simon->currentSequence++;
		simon->timer = 1.5;

		if (simon->currentSequence == simon->level)
		{
			simon->currentSequence = 0;
			simon->playMode = true;
			*currentState = play;
		}
	}

	simon->timer -= deltaTime;
	//cout << simon->timer << endl;
}

void AutoState::Draw(Renderer2D * r2d, Font * font)
{	
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
}

void AutoState::GetStates(GameState * titleScreen, GameState * autoState, GameState * playState, GameState * pauseState, GameState * leaderBoard)
{
	play = playState;
}
