#pragma once
#include <Font.h>
#include <Input.h>
#include <Renderer2D.h>
#include <Texture.h>
#include <string>

using namespace aie;

class Button
{
public:
	Button();
	Button(int b);
	Button(const char* text, float x, float y, float width, float height);
	~Button();

	struct Rectangle
	{
		int posX;
		int posY;
		int width;
		int height;
	};

	char text[20];

	//bool mouseOver = false;

	Texture* colour; // the colour for the button
	Texture* litColour; // lit up colour for the button

	Rectangle cursor;
	Rectangle clickable;

	void Draw(Renderer2D* r2d, Font* a_font);

	void GetMousePos();

	bool AABBCollision();

	void LightUp(); // lights up the buttons
};