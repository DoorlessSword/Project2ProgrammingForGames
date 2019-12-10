#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook();
	Rook(double worldPosX, double worldPosY);
	~Rook();

	//void move(double dist, int movTyp, int movDirection);
	void move();

private:
	const int SIDE_LENGTH = 2;
};

