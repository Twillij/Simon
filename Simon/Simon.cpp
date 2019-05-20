#include "Simon.h"
#include <time.h>
#include <iostream>

Simon::Simon()
{
	memory = new SequenceArray();
	GenButtons();
	sequenceButton = new Button("Start Level", 640, 75, 250, 50);
}

Simon::~Simon()
{
	delete memory;
	delete sequenceButton;

	for (int i = 0; i < 4; ++i)
	{
		delete button[i]->colour;
		delete button[i]->litColour;
		delete button[i];
	}
}

void Simon::GenButtons()
{
	for (int i = 0; i < 4; i++)
		button[i] = new Button(i);
}

void Simon::GenSeries()
{
	srand(time(NULL));

	memory->Clear();

	for (int i = 0; i < level; i++)
		memory->PushBack(rand() % 4);
}

void Simon::CheckInput(int correct, int input)
{
	if (input == correct)
		currentSequence++;
	else
	{
		life--;
		wrong = true;
		playMode = false;
		sequenceButton->changeText("Restart Level");

		for (int i = 0; i < 4; ++i)
			button[i]->flash = false;
	}
}

void Simon::Reset()
{
	playMode = false;
	wrong = false;
	level = 0;
	life = 3;
	timer = 1;
	memory->Clear();
	currentSequence = 0;
	sequenceButton->changeText("Start Level");

	for (int i = 0; i < 4; ++i)
		button[i]->flash = false;
}
