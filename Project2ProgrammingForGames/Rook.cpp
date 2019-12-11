#include "Rook.h"
#include <time.h>
#include <stdlib.h>
#include <random>

/*
Author: Patrick Lindley
Student No: 170461106
*/

Rook::Rook()
{
}

Rook::Rook(double worldPosX, double worldPosY)
{
	worldPositionX = worldPosX;
	worldPositionY = worldPosY;
	shape = SQUARE;
}

void Rook::move()
{
	std::random_device rd;
	std::mt19937 seed(rd());
	std::uniform_real_distribution<> distr(0.0, 1.0);	//rand between 0 and 1
	std::uniform_int_distribution<> moveDistr(0, 1);
	std::uniform_int_distribution<> dirDistr(0, 1);

	double distance = distr(seed);
	int moveType = moveDistr(seed);
	int direction = dirDistr(seed);

	//horizontal
	if (moveType == 0) {
		//move right
		if (direction == 0) {
			if (distance + worldPositionX > 10) {
				move();
			}
			else {
				worldPositionX += distance;
			}
		}
		//move left
		else if (direction == 1) {
			if (worldPositionX - distance < 0) {
				move();
			}
			else {
				worldPositionX -= distance;
			}
		}
	}
	//vertical
	else if (moveType == 1) {
		//move up
		if (direction == 0) {
			if (distance + worldPositionY > 10) {
				move();
			}
			else {
				worldPositionY += distance;
			}
		}
		//move down
		else if (direction == 1) {
			if (worldPositionY - distance < 0) {
				move();
			}
			else {
				worldPositionY -= distance;
			}
		}
	}
}