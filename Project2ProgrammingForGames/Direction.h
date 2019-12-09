#pragma once
#include <iostream>

enum class Direction {
	NW, N, NE, E, SE, S, SW, W
};

std::string direction(Direction dir) {
	switch (dir) {
	case Direction::NW:
		return "NW";
	case Direction::N:
		return "N";
	case Direction::NE:
		return "NE";
	case Direction::E:
		return "E";
	case Direction::SE:
		return "SE";
	case Direction::S:
		return "S";
	case Direction::SW:
		return "SW";
	case Direction::W:
		return "W";
	}
}