#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Simon.h"
#include "TitleScreen.h"
#include "PlayState.h"
#include "PauseState.h"
#include "LeaderBoard.h"

class SimonApp : public aie::Application {
public:

	SimonApp();
	virtual ~SimonApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	//Simon s;

	GameState* currentState;
	TitleScreen* title;
	PlayState* play;
	PauseState* pause;
	LeaderBoard* hiScore;

	Button* testb;
};