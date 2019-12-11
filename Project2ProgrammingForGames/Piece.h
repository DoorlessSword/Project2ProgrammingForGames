#pragma once
#include "Shape.h"
#include <string>

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
	virtual ~Piece();

	//virtual void move(double dist, int movTyp, int movDirection) = 0;
	virtual void move() = 0;
	
	Shape getShape() const {
		return shape;
	}
	double getWorldPositionX() const {
		return worldPositionX;
	}
	double getWorldPositionY() const {
		return worldPositionY;
	}
	
	virtual int getSize() const = 0;
	
	virtual std::string getType() = 0;
};

