#include "SimonApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>

SimonApp::SimonApp() {

}

SimonApp::~SimonApp() {

}

bool SimonApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/ARCADE.ttf", 32);
	
	ts = new TitleScreen();
	currentState = ts;
	s.GenButtons();
	s.GenSeries();
	//s.memory->Print();

	return true;
}

void SimonApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;

	delete ts;
}

void SimonApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// currentState->update();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void SimonApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	//m_2dRenderer->drawSprite(m_croissant, 50 + i * xInc, 50 + j * yInc, xInc, yInc, 0, 0, 0, 0);
	//m_2dRenderer->drawSprite(simon->button[0]->colour, 100, 100);
	
	ts->DrawScreen(m_2dRenderer, m_font);

	/*m_2dRenderer->drawSprite(s.button[0]->colour, 768, 512);
	m_2dRenderer->drawSprite(s.button[1]->colour, 768, 256);
	m_2dRenderer->drawSprite(s.button[2]->colour, 512, 256);
	m_2dRenderer->drawSprite(s.button[3]->colour, 512, 512);

	if (s.button[0]->AABBCollision())
		m_2dRenderer->drawSprite(s.button[0]->litColour, 768, 512);
	else if (s.button[1]->AABBCollision())
		m_2dRenderer->drawSprite(s.button[1]->litColour, 768, 256);
	else if (s.button[2]->AABBCollision())
		m_2dRenderer->drawSprite(s.button[2]->litColour, 512, 256);
	else if (s.button[3]->AABBCollision())
		m_2dRenderer->drawSprite(s.button[3]->litColour, 512, 512);*/
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}