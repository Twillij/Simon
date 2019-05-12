#pragma once
#include "Button.h"
#include "LinkedList.h"
#include <vector>

using namespace std;

class Simon
{
public:
	Simon();
	~Simon();

	Button* button[4]; // holds 4 coloured buttons that flashes

	int level = 5; // set back to 0 later

	LinkedList* memory = new LinkedList(); // memorises the sequence as integers

	void GenButtons(); // generates the 4 coloured buttons

	void GenSeries(); // generates random sequence

	void Replay(); // replays the sequence
};