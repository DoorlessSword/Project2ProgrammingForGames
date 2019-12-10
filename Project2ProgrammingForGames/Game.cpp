#include "Bishop.h"
#include "Piece.h"
#include "Queen.h"
#include "Rook.h"
#include <vector>
#include <iostream>
#include <random>

void collisionCheck(std::vector<Piece*> pieces, int j) {

}

int main() {

/*	std::random_device rd;
	std::mt19937 seed(rd());
	std::uniform_real_distribution<> distr(0.0, 1.0);	//rand between 0 and 1
	std::uniform_int_distribution<> moveDistr(0, 1);
	std::uniform_int_distribution<> dirDistr(0, 1);
	*/

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

	/*While there are more than one pieces still in play
		do 100 turns
			iterate through pieces
				move piece
				check for collision
	*/
	//while (pieces.size() > 1) {
		for (int i = 0; i < 100; ++i) {
			/*std::cout << "distance = " << distance << std::endl;
			std::cout << "movType = " << moveType << std::endl;
			std::cout << "direction = " << direction << std::endl;*/
			for (int j = 0; j < pieces.size(); ++j) {
				pieces[j]->move();
				collisionCheck(pieces, j);
				std::cout << "Piece " << j << " position is ("
					<< pieces[j]->getWorldPositionX() << ", "
					<< pieces[j]->getWorldPositionY() << ")" << std::endl;
			}
		}
	//}
}