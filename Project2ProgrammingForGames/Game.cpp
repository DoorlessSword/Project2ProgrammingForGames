#include "Bishop.h"
#include "Piece.h"
#include "Queen.h"
#include "Rook.h"
#include <vector>
#include <iostream>
#include <random>

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
					std::cout << "Collision detected between " << pieces[k]->getType()
						<< " (" << pieces[k]->getWorldPositionX() << ", " << pieces[k]->getWorldPositionY() << ")"
						<< " and " << pieces[i]->getType() << " (" << pieces[i]->getWorldPositionX() << ", "
						<< pieces[i]->getWorldPositionY() << ")" << std::endl;

					toBeDeleted = true;
					indexToBeDeleted = i;
					rookScore++;
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
					std::cout << "Collision detected between " << pieces[k]->getType()
						<< " (" << pieces[k]->getWorldPositionX() << ", " << pieces[k]->getWorldPositionY() << ")"
						<< " and " << pieces[i]->getType() << " (" << pieces[i]->getWorldPositionX() << ", "
						<< pieces[i]->getWorldPositionY() << ")" << std::endl;

					toBeDeleted = true;
					indexToBeDeleted = i;
					if (pieces[k]->getType() == "Queen") {
						queenScore++;
					}
					else {
						bishopScore++;
					}
				}
			}
			//circle square
			else if (pieces[k]->getShape() == CIRCLE && pieces[i]->getShape() == SQUARE) {

			}
			//square circle
			else if (pieces[k]->getShape() == SQUARE && pieces[i]->getShape() == CIRCLE) {

			}
		}
	}
}

int main() {
	//change starting position to have one of each in a row at opposite sides
	Queen* q1 = new Queen(0, 0);
	Queen* q2 = new Queen(5, 5);

	Rook* r1 = new Rook(2, 2);
	Rook* r2 = new Rook(3, 4);

	Bishop* b1 = new Bishop(5, 2);
	Bishop* b2 = new Bishop(3, 1);

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


	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < pieces.size(); ++j) {
			pieces[j]->move();
			collisionCheck(pieces, j, toBeDeleted, indexToBeDeleted);
			if (toBeDeleted) {
				std::cout << pieces[indexToBeDeleted]->getType() << " is destroyed" << std::endl;;
				pieces.erase(pieces.begin() + indexToBeDeleted);
				toBeDeleted = false;
				indexToBeDeleted = 0;
				break;
			}
			//remove piece
			std::cout << "Piece " << j << " position is ("
				<< pieces[j]->getWorldPositionX() << ", "
				<< pieces[j]->getWorldPositionY() << ")" << std::endl;
		}
		if (pieces.size() <= 1) {
			break;
		}
	}


	std::cout << "Rook score: " << rookScore << std::endl;
	std::cout << "Bishop score: " << bishopScore << std::endl;
	std::cout << "Queen score: " << queenScore << std::endl;

}