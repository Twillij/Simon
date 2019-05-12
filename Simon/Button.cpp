#include "Button.h"


Button::Button()
{
}


Button::Button(int b)
{
	clickable.width = 256;
	clickable.height = 256;
	
	switch (b)
	{
	case 0:
		colour = new Texture("../bin/textures/blue.png");
		litColour = new Texture("../bin/textures/blue_lit.png");
		clickable.posX = 768;
		clickable.posY = 512;
		break;

	case 1:
		colour = new Texture("../bin/textures/green.png");
		litColour = new Texture("../bin/textures/green_lit.png");
		clickable.posX = 768;
		clickable.posY = 256;
		break;

	case 2:
		colour = new Texture("../bin/textures/red.png");
		litColour = new Texture("../bin/textures/red_lit.png");
		clickable.posX = 512;
		clickable.posY = 256;
		break;

	case 3:
		colour = new Texture("../bin/textures/yellow.png");
		litColour = new Texture("../bin/textures/yellow_lit.png");
		clickable.posX = 512;
		clickable.posY = 512;
		break;

	default:
		break;
	}
}

Button::Button(const char * a_text, float x, float y, float width, float height)
{
	strcpy_s(text, 20, a_text); // store the text that will appear on the button

	clickable.posX = x;
	clickable.posY = y;
	clickable.width = width;
	clickable.height = height;
}


Button::~Button()
{
	//delete colour;
	//delete litColour;
}


void Button::Draw(Renderer2D * r2d, Font* a_font)
{
	// draw a coloured box for the button background
	r2d->setRenderColour(0.0f, 0.5f, 0.7f, 1.0f);
	r2d->drawBox(clickable.posX, clickable.posY, clickable.width, clickable.height);
	r2d->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	// calculating the centred text position
	float textWidth = a_font->getStringWidth(text);
	float textHeight = a_font->getStringHeight(text);
	float centredPosX = clickable.posX - (textWidth * 0.5f) + 2;
	float centredPosY = clickable.posY - (textHeight * 0.5f) + 2;

	r2d->drawText(a_font, text, centredPosX, centredPosY);
}


void Button::GetMousePos()
{
	Input* input = Input::getInstance();
	
	cursor.width = 1;
	cursor.height = 1;
	cursor.posX = input->getMouseX();
	cursor.posY = input->getMouseY();
}


bool Button::AABBCollision()
{
	float left = clickable.posX - (clickable.width * 0.5);
	float right = clickable.posX + (clickable.width * 0.5);
	float bot = clickable.posY - (clickable.height * 0.5);
	float top = clickable.posY + (clickable.height * 0.5);

	GetMousePos();

	if (cursor.posX > left && cursor.posX < right && cursor.posY > bot && cursor.posY < top)
	{
		//mouseOver = true;
		return true;
	}

	//mouseOver = false;
	return false;
}