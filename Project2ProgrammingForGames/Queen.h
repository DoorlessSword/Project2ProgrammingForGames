#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen();
	Queen(double worldPosX, double worldPosY);
	~Queen();

	//void move(double dist, int movTyp, int movDirection);
	void move();

private:
	const int RADIUS = 1;

};

