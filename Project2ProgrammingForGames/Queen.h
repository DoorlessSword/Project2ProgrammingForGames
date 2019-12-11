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

	int getSize() const {
		return RADIUS;
	}

	std::string getType() {
		return "Queen";
	}

private:
	const int RADIUS = 1;

};

