#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop();
	Bishop(double worldPosX, double worldPosY);
	~Bishop();

	//void move(double dist, int movTyp, int movDirection);
	void move();

private:
	const int RADIUS = 1;

};

