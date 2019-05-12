#include "Simon.h"
#include <time.h>
#include <iostream>

Simon::Simon()
{
}


Simon::~Simon()
{
	delete memory;
}


void Simon::GenButtons()
{
	for (int i = 0; i < 4; i++)
		button[i] = new Button(i);
}


void Simon::GenSeries()
{
	srand(time(NULL));

	for (int i = 0; i < level; i++)
		memory->PushBack(rand() % 4);
}
