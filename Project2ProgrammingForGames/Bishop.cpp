#include "Bishop.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <random>

Bishop::Bishop()
{
}

Bishop::Bishop(double worldPosX, double worldPosY)
{
	worldPositionX = worldPosX;
	worldPositionY = worldPosY;
	shape = CIRCLE;
}

Bishop::~Bishop()
{
}

void Bishop::move()
{

	std::random_device rd;
	std::mt19937 seed(rd());
	std::uniform_real_distribution<> distr(0.0, 1.0);	//rand between 0 and 1
	std::uniform_int_distribution<> moveDistr(0, 1);
	std::uniform_int_distribution<> dirDistr(0, 1);

	double distance = distr(seed);
	int moveType = moveDistr(seed);
	int direction = dirDistr(seed);

	//diagonal bottom left-top right movement
	if (moveType == 0) {
		//move bottom to top
		if (direction == 0) {
			if (distance + worldPositionX > 10 || distance + worldPositionY > 10) {
				move();
			}
			else {
				worldPositionX += distance / std::sqrt(2);
				worldPositionY += distance / std::sqrt(2);
			}
		}
		//move top to bottom
		else if (direction == 1) {
			if (worldPositionX - distance < 0 || worldPositionY - distance < 0) {
				move();
			}
			else {
				worldPositionX -= distance / std::sqrt(2);
				worldPositionY -= distance / std::sqrt(2);
			}
		}
	}
	//diagonal bottom right-top left movement
	else if (moveType == 1) {
		//move bottom to top
		if (direction == 0) {
			if (worldPositionX - distance < 0 || distance + worldPositionY > 10) {
				move();
			}
			else {
				worldPositionX -= distance / std::sqrt(2);
				worldPositionY += distance / std::sqrt(2);
			}
		}
		//move top to bottom
		else if (direction == 1) {
			if (worldPositionX + distance > 10 || worldPositionY - distance < 0) {
				move();
			}
			else {
				worldPositionX += distance / std::sqrt(2);
				worldPositionY -= distance / std::sqrt(2);
			}
		}
	}
}

