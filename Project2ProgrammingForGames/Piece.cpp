#include "Piece.h"
#include <iostream>

Piece::Piece()
{
	worldPositionX = 0;
	worldPositionY = 0;
}

Piece::Piece(double worldPosX, double worldPosY)
{
	worldPositionX = worldPosX;
	worldPositionY = worldPosY;
}

Piece::~Piece()
{
}

Piece::Piece(const Piece&)
{

}

const Shape Piece::getShape()
{
	return shape;
}

const double Piece::getWorldPositionX()
{
	return worldPositionX;
}

const double Piece::getWorldPositionY()
{
	return worldPositionY;
}
