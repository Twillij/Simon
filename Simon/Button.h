#pragma once
#include <Font.h>
#include <Input.h>
#include <Renderer2D.h>
#include <Texture.h>
#include <string>
#include <iostream>

using namespace std;
using namespace aie;

class Button
{
public:
	Button();
	Button(int b);
	Button(char* text, float x, float y, float width, float height);
	~Button();

	struct Rectangle
	{
		int posX;
		int posY;
		int width;
		int height;
	};

	char text[20]; // text for the button

	bool flash = false; // true if the button is supposed to be flashing

	Texture* colour; // the colour for the button
	Texture* litColour; // lit up colour for the button

	Rectangle cursor; // a 1x1 grid at the mouse position
	Rectangle clickable; // clickable area for the button

	void Draw(Renderer2D* r2d, Font* a_font);

	void GetMousePos(); // retrieves mouse position

	bool AABBCollision(); // checks if the mouse is hovering over the button

	void changeText(char * a_text);
};