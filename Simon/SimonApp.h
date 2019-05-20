#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Simon.h"
#include "TitleScreen.h"
#include "PlayState.h"
#include "AutoState.h"
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

	Renderer2D*		m_2dRenderer;
	Font*			m_font;
	Font*			big_font;

	GameState*		currentState;
	TitleScreen*	title;
	PlayState*		play;
	AutoState*		autopilot;
	PauseState*		pause;
	LeaderBoard*	hiScore;
};