#pragma once
#include "Shape.h"
#include "Direction.h"

class Piece
{
protected:
	double worldPositionX;
	double worldPositionY;
	Shape shape;

public:
	//Constructors
	Piece();
	Piece(double worldPosX, double worldPosY);
	~Piece();
	Piece(const Piece&);

	virtual void move(double distance, Direction direction);
	
	const Shape getShape();
	const double getWorldPositionX();
	const double getWorldPositionY();
};

