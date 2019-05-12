#include "TitleScreen.h"


TitleScreen::TitleScreen()
{
	//delete playButton;
}


TitleScreen::~TitleScreen()
{
}


void TitleScreen::DrawScreen(Renderer2D * r2d, Font * font)
{
	playButton = new Button("Play", 640, 180, 120, 50);

	playButton->Draw(r2d, font);
}