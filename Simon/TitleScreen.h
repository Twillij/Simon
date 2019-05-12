#pragma once
#include "GameState.h"

class TitleScreen : public GameState
{
public:
	TitleScreen();
	~TitleScreen();

	Button* playButton;

	void DrawScreen(Renderer2D* r2d, Font* font);
};

