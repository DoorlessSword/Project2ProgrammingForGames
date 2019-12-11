#pragma once
#include "Piece.h"

/*
Author: Patrick Lindley
Student No: 170461106
*/

class Bishop : public Piece
{
public:
	Bishop();
	Bishop(double worldPosX, double worldPosY);

	void move();

	int getSize() const {
		return RADIUS;
	}

	std::string getType() {
		return "Bishop";
	}

private:
	const int RADIUS = 1;

};

