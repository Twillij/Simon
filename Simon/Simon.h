#pragma once
#include "Button.h"
#include "SequenceArray.h"
#include <vector>

using namespace std;

class Simon
{
public:
	Simon();
	~Simon();

	bool playMode = false; // true if it's the player's turn
	bool wrong = false;
	int life = 3;
	char lifeIndicator[10];

	int level = 0; // set back to 0 later
	char levelIndicator[10];

	float timer = 1;

	Button* button[4]; // holds 4 coloured buttons that flashes
	Button* sequenceButton;

	SequenceArray* memory; // stores the sequences as integers
	int currentSequence = 0; // tracks the current sequence in the memory
	char sequenceIndicator[10];
	int wrongInput;

	void GenButtons(); // generates the 4 coloured buttons

	void GenSeries(); // generates random sequence

	void CheckInput(int correct, int input); // checks user input against sequence

	void Reset();
};