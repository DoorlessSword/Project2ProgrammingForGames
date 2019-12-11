#include "Bishop.h"
#include "Piece.h"
#include "Queen.h"
#include "Rook.h"
#include <vector>
#include <iostream>

int rookScore = 0;
int bishopScore = 0;
int queenScore = 0;

void collisionCheck(std::vector<Piece*> pieces, int j, bool& toBeDeleted, int& indexToBeDeleted) {
	int k = j;
	for (int i = 0; i < pieces.size(); ++i) {
		if (pieces[k] != pieces[i]) {
			//collision detection
			//square square
			if (pieces[k]->getShape() == SQUARE && pieces[i]->getShape() == SQUARE) {
				if ((pieces[k]->getWorldPositionX() - 1) < (pieces[i]->getWorldPositionX() - 1) + pieces[i]->getSize()
					&& (pieces[k]->getWorldPositionX() - 1) + pieces[k]->getSize() > (pieces[i]->getWorldPositionX() - 1)
					&& (pieces[k]->getWorldPositionY() - 1) < (pieces[i]->getWorldPositionY() - 1) + pieces[i]->getSize()
					&& (pieces[k]->getWorldPositionY() - 1) + pieces[k]->getSize() > (pieces[i]->getWorldPositionY() - 1)) {

					//collision detected
					//add to score for piece[k]
					//remove pieces[i] from pieces
					std::cout << "!!Collision detected between " << pieces[k]->getType()
						<< " (" << pieces[k]->getWorldPositionX() << ", " << pieces[k]->getWorldPositionY() << ")"
						<< " and " << pieces[i]->getType() << " (" << pieces[i]->getWorldPositionX() << ", "
						<< pieces[i]->getWorldPositionY() << ")!!" << std::endl;

					toBeDeleted = true;
					indexToBeDeleted = i;
					++rookScore;
				}

			}
			//circle circle
			else if (pieces[k]->getShape() == CIRCLE && pieces[i]->getShape() == CIRCLE) {
				double dx = pieces[k]->getWorldPositionX() - pieces[i]->getWorldPositionX();
				double dy = pieces[k]->getWorldPositionY() - pieces[i]->getWorldPositionY();
				double distance = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));

				if (distance < ((double)pieces[k]->getSize() + (double)pieces[i]->getSize())) {
					//collision detected
					//add to score for piece[k]
					//remove pieces[i] from pieces
					std::cout << "!!Collision detected between " << pieces[k]->getType()
						<< " (" << pieces[k]->getWorldPositionX() << ", " << pieces[k]->getWorldPositionY() << ")"
						<< " and " << pieces[i]->getType() << " (" << pieces[i]->getWorldPositionX() << ", "
						<< pieces[i]->getWorldPositionY() << ")!!" << std::endl;

					toBeDeleted = true;
					indexToBeDeleted = i;
					if (pieces[k]->getType() == "Queen") {
						++queenScore;
					}
					else {
						++bishopScore;
					}
				}
			}

			//circle square
			//k = circle
			//i = square
			//modified and expanded upon method presented by http://www.jeffreythompson.org/collision-detection/circle-rect.php
			else if (pieces[k]->getShape() == CIRCLE && pieces[i]->getShape() == SQUARE) {
				double testX = pieces[k]->getWorldPositionX();	//circleX pos
				double testY = pieces[k]->getWorldPositionY();	//circleY pos

				if (pieces[k]->getWorldPositionX() < pieces[i]->getWorldPositionX() - 1) {
					testX = pieces[i]->getWorldPositionX();
				}
				else if (pieces[k]->getWorldPositionX() > pieces[i]->getWorldPositionX() + pieces[i]->getSize() / 2) {
					testX = pieces[i]->getWorldPositionX() + pieces[i]->getSize() / 2;
				}
				if (pieces[k]->getWorldPositionY() < pieces[i]->getWorldPositionY()) {
					testY = pieces[i]->getWorldPositionY();
				}
				else if (pieces[k]->getWorldPositionY() > pieces[i]->getWorldPositionY() + pieces[i]->getSize() / 2) {
					testY = pieces[i]->getWorldPositionY() + pieces[i]->getSize() / 2;
				}

				double distX = pieces[k]->getWorldPositionX() - testX;
				double distY = pieces[k]->getWorldPositionY() - testY;
				double distance = std::sqrt(std::pow(distX, 2) + std::pow(distY, 2));

				if (distance <= pieces[k]->getSize()) {
					//collision
					std::cout << "!!Collision detected between " << pieces[k]->getType()
						<< " (" << pieces[k]->getWorldPositionX() << ", " << pieces[k]->getWorldPositionY() << ")"
						<< " and " << pieces[i]->getType() << " (" << pieces[i]->getWorldPositionX() << ", "
						<< pieces[i]->getWorldPositionY() << ")!!" << std::endl;

					toBeDeleted = true;
					indexToBeDeleted = i;
					if (pieces[k]->getType() == "Queen") {
						++queenScore;
					}
					else {
						++bishopScore;
					}
				}
			}
			//square circle
			else if (pieces[k]->getShape() == SQUARE && pieces[i]->getShape() == CIRCLE) {
				double testX = pieces[i]->getWorldPositionX();	//circleX pos
				double testY = pieces[i]->getWorldPositionY();	//circleY pos

				if (pieces[i]->getWorldPositionX() < pieces[k]->getWorldPositionX() - 1) {
					testX = pieces[k]->getWorldPositionX();
				}
				else if (pieces[i]->getWorldPositionX() > pieces[k]->getWorldPositionX() + pieces[k]->getSize() / 2) {
					testX = pieces[k]->getWorldPositionX() + pieces[k]->getSize() / 2;
				}
				if (pieces[i]->getWorldPositionY() < pieces[k]->getWorldPositionY()) {
					testY = pieces[k]->getWorldPositionY();
				}
				else if (pieces[i]->getWorldPositionY() > pieces[k]->getWorldPositionY() + pieces[k]->getSize() / 2) {
					testY = pieces[k]->getWorldPositionY() + pieces[k]->getSize() / 2;
				}

				double distX = pieces[i]->getWorldPositionX() - testX;
				double distY = pieces[i]->getWorldPositionY() - testY;
				double distance = std::sqrt(std::pow(distX, 2) + std::pow(distY, 2));

				if (distance <= pieces[i]->getSize()) {
					//collision
					std::cout << "!!Collision detected between " << pieces[k]->getType()
						<< " (" << pieces[k]->getWorldPositionX() << ", " << pieces[k]->getWorldPositionY() << ")"
						<< " and " << pieces[i]->getType() << " (" << pieces[i]->getWorldPositionX() << ", "
						<< pieces[i]->getWorldPositionY() << ")!!" << std::endl;

					toBeDeleted = true;
					indexToBeDeleted = i;
					if (pieces[k]->getType() == "Rook") {
						++rookScore;
					}
				}
			}
		}
	}
}

int main() {
	Queen* q1 = new Queen(0, 0);
	Queen* q2 = new Queen(10, 10);

	Rook* r1 = new Rook(5, 0);
	Rook* r2 = new Rook(5, 10);

	Bishop* b1 = new Bishop(10, 0);
	Bishop* b2 = new Bishop(0, 10);

	std::vector<Piece*> pieces;
	pieces.push_back(q1);
	pieces.push_back(q2);
	pieces.push_back(r1);
	pieces.push_back(r2);
	pieces.push_back(b1);
	pieces.push_back(b2);

	/* TESTING SQUARE SQUARE
	std::vector<Piece*> pieces;
	Rook* r1 = new Rook(0, 0);
	Rook* r2 = new Rook(2, 2);
	Rook* r3 = new Rook(0, 2);
	pieces.push_back(r1);
	pieces.push_back(r2);
	pieces.push_back(r3);
	*/

	bool toBeDeleted = false;
	int indexToBeDeleted = 0;
	int noMoves = 0;

	for (int i = 0; i < pieces.size(); ++i) {
		std::cout << pieces[i]->getType() << " starting position is ("
			<< pieces[i]->getWorldPositionX() << ", "
			<< pieces[i]->getWorldPositionY() << ")" << std::endl;
	}

	std::cout << std::endl << "********** GAME START **********" << std::endl;

	while(pieces.size() > 1) {
		for (int j = 0; j < pieces.size(); ++j) {
			pieces[j]->move();
			collisionCheck(pieces, j, toBeDeleted, indexToBeDeleted);
			if (toBeDeleted) {
				std::cout << pieces[indexToBeDeleted]->getType() << " is destroyed" << std::endl;;
				/*std::cout << pieces[j]->getType() << " position is ("
					<< pieces[j]->getWorldPositionX() << ", "
					<< pieces[j]->getWorldPositionY() << ")" << std::endl;*/
				pieces.erase(pieces.begin() + indexToBeDeleted);
				toBeDeleted = false;
				indexToBeDeleted = 0;
				
				break;
			}
			/*else {
				std::cout << pieces[j]->getType() << " position is ("
					<< pieces[j]->getWorldPositionX() << ", "
					<< pieces[j]->getWorldPositionY() << ")" << std::endl;
			}*/
		}
		if (pieces.size() <= 1) {
			break;
		}
		++noMoves;
	}


	std::cout << std::endl << "********** GAME END **********" << std::endl;
	std::cout << "Number of moves till end: " << noMoves << std::endl;
	std::cout << "Rook score: " << rookScore << std::endl;
	std::cout << "Bishop score: " << bishopScore << std::endl;
	std::cout << "Queen score: " << queenScore << std::endl;

	delete q1;
	delete q2;
	delete r1;
	delete r2;
	delete b1;
	delete b2;

}