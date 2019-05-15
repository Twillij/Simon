#include "Simon.h"
#include <time.h>
#include <iostream>

Simon::Simon()
{
	memory = new SequenceArray();
	GenButtons();
}

Simon::~Simon()
{
	delete memory;

	//delete[] button;

	for (int i = 0; i < 4; ++i)
		delete button[i];
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
		lose = true;
}

void Simon::Reset()
{
	playMode = false;
	lose = false;
	level = 1;
	timer = 1.5;
	memory->Clear();
	currentSequence = 0;

	for (int i = 0; i < 4; ++i)
		button[i]->flash = false;
}
