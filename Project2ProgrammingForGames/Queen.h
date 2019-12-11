#pragma once
#include "Piece.h"

/*
Author: Patrick Lindley
Student No: 170461106
*/

class Queen : public Piece
{
public:
	Queen();
	Queen(double worldPosX, double worldPosY);

	void move();

	int getSize() const {
		return RADIUS;
	}

	std::string getType() {
		return "Queen";
	}

private:
	const int RADIUS = 1;

};

