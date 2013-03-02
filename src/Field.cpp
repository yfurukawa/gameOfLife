/*
 * Field.cpp
 *
 *  Created on: 2013/02/24
 *      Author: furukawayoshihiro
 */

#include "Field.h"

Field::Field() : Width_(0), Hight_(0) {
	// TODO Auto-generated constructor stub

}

Field::Field(int Width, int Hight)  : Width_(Width), Hight_(Hight) {
//	cells[Width][Hight];
}

Field::~Field() {
	// TODO Auto-generated destructor stub
}

void Field::initializeField() {
	for(int x = 0; x <= Width_; ++x){
		for(int y = 0; y <= Hight_; ++y){
			cells[x][y] = new Cell();
		}
	}
}

Cell* Field::getCell(int xPosition, int yPosition) {
	return cells[xPosition][yPosition];
}
