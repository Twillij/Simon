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
	bool lose = false;

	int level = 2; // set back to 0 later

	float timer = 2;

	Button* button[4]; // holds 4 coloured buttons that flashes

	SequenceArray* memory; // stores the sequences as integers
	int currentSequence; // tracks the current sequence in the memory

	void GenButtons(); // generates the 4 coloured buttons

	void GenSeries(); // generates random sequence

	void CheckInput(int correct, int input); // checks user input against sequence

	void Replay(); // replays the sequence
};