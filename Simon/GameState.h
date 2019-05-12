#pragma once
#include "Button.h"
#include <Font.h>
#include <Renderer2D.h>

using namespace aie;

class GameState
{
public:
	GameState();
	~GameState();

	void DrawScreen();

	void Update(Button* b); // go to gamestate* next
};