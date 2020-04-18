#include "Rectangle.h"

void Rectangle::Draw(bool withColor)
{
	// set foreground color and fill color
	if (withColor)
	{
		setcolor(outlineColor->colorValue);

		if (isFill)
		{
			setfillcolor(fillColor->colorValue);
		}
		else
		{
			setfillcolor(0xFFFFFF);
		} // end of if
	}
	else
	{
		setcolor(0xCCCCCC);
		setfillcolor(0xDDDDDD);
	} // end of if

	if (isFill)
	{
		bar(coords[0].x,
			coords[0].y,
			coords[1].x,
			coords[1].y);
	}
	else
	{
		rectangle(coords[0].x,
			coords[0].y,
			coords[1].x,
			coords[1].y);
	}
}

Rectangle::Rectangle()
{
	rectangleCount++;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2) : Rectangle()
{
	shapeType                = SHAPE::shape_rectangle;
	isFill                   = false;
	outlineColor->colorValue = RandColor();
	coords[0].x              = x1;
	coords[0].y              = y1;
	coords[1].x              = x2;
	coords[1].y              = y2;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2, color_t outlineColor) : Rectangle()
{
	shapeType                      = SHAPE::shape_rectangle;
	isFill                         = false;
	this->outlineColor->colorValue = outlineColor;
	coords[0].x                    = x1;
	coords[0].y                    = y1;
	coords[1].x                    = x2;
	coords[1].y                    = y2;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2, color_t outlineColor, color_t fillColor) : Rectangle()
{
	shapeType                      = SHAPE::shape_rectangle;
	isFill                         = true;
	this->outlineColor->colorValue = outlineColor;
	this->fillColor->colorValue    = fillColor;
	coords[0].x                    = x1;
	coords[0].y                    = y1;
	coords[1].x                    = x2;
	coords[1].y                    = y2;
}

Rectangle::~Rectangle()
{
	rectangleCount--;
}