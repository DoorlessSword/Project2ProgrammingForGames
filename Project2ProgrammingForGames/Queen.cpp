#include "Queen.h"
#include <stdlib.h>
#include <time.h>
#include <random>

Queen::Queen()
{
}

Queen::Queen(double worldPosX, double worldPosY) : Piece(worldPosX, worldPosY)
{
	worldPositionX = worldPosX;
	worldPositionY = worldPosY;
	shape = CIRCLE;
}

Queen::~Queen()
{
}

void Queen::move()
{
	std::random_device rd;
	std::mt19937 seed(rd());
	std::uniform_real_distribution<> distr(0.0, 1.0);	//rand between 0 and 1
	std::uniform_int_distribution<> moveDistr(0, 3);
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
	//horizontal
	else if (moveType == 2) {
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
	else if (moveType == 3) {
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
