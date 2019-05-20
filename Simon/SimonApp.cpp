#include "SimonApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>

SimonApp::SimonApp()
{
}

SimonApp::~SimonApp()
{
}

bool SimonApp::startup()
{	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/ARCADE.ttf", 32);
	big_font = new aie::Font("../bin/font/consolas_bold.ttf", 128);
	
	title = new TitleScreen();
	play = new PlayState();
	autopilot = new AutoState();
	pause = new PauseState();
	hiScore = new LeaderBoard();

	title->GetStates(title, autopilot, play, pause, hiScore);
	play->GetStates(title, autopilot, play, pause, hiScore);
	autopilot->GetStates(title, autopilot, play, pause, hiScore);
	pause->GetStates(title, autopilot, play, pause, hiScore);

	autopilot->simon = play->simon;
	pause->simon = play->simon;

	currentState = title;

	return true;
}

void SimonApp::shutdown()
{
	delete m_font;
	delete big_font;
	delete m_2dRenderer;

	delete title;
	delete play;
	delete autopilot;
	delete pause;
	delete hiScore;
}

void SimonApp::update(float deltaTime)
{
	// input example
	aie::Input* input = aie::Input::getInstance();

	// updates the state of the game
	currentState->Update(&currentState, deltaTime);

	// exit the application
	if (currentState->quitGame)
		quit();
}

void SimonApp::draw()
{
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	//m_2dRenderer->drawSprite(m_croissant, 50 + i * xInc, 50 + j * yInc, xInc, yInc, 0, 0, 0, 0);
	//m_2dRenderer->drawSprite(simon->button[0]->colour, 100, 100);
	
	currentState->Draw(m_2dRenderer, m_font, big_font);
	
	// output some text, uses the last used colour
	//m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}