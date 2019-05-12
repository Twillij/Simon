#include "PlayState.h"


PlayState::PlayState()
{
	simon = new Simon();
}


PlayState::~PlayState()
{
	delete simon;
}

void PlayState::Update()
{
}

void PlayState::Draw(Renderer2D * r2d, Font * font)
{
	if (simon->button)

	r2d->drawSprite(simon->button[0]->colour, 768, 512);
	r2d->drawSprite(simon->button[1]->colour, 768, 256);
	r2d->drawSprite(simon->button[2]->colour, 512, 256);
	r2d->drawSprite(simon->button[3]->colour, 512, 512);

	if (simon->button[0]->AABBCollision())
		r2d->drawSprite(simon->button[0]->litColour, 768, 512);
	else if (simon->button[1]->AABBCollision())
		r2d->drawSprite(simon->button[1]->litColour, 768, 256);
	else if (simon->button[2]->AABBCollision())
		r2d->drawSprite(simon->button[2]->litColour, 512, 256);
	else if (simon->button[3]->AABBCollision())
		r2d->drawSprite(simon->button[3]->litColour, 512, 512);
}

void PlayState::GetStates(GameState * titleScreen, GameState * playState, GameState * pauseState, GameState * leaderBoard)
{
	pause = pauseState;
}
