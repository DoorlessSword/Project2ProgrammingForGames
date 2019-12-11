#pragma once
#include "Piece.h"

/*
Author: Patrick Lindley
Student No: 170461106
*/

class Rook : public Piece
{
public:
	Rook();
	Rook(double worldPosX, double worldPosY);

	void move();

	int getSize() const {
		return SIDE_LENGTH;
	}

	std::string getType() {
		return "Rook";
	}

private:
	const int SIDE_LENGTH = 2;
};

