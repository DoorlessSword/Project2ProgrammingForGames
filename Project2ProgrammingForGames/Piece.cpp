#include "Piece.h"
#include <iostream>

/*
Author: Patrick Lindley
Student No: 170461106
*/

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