/*
 * Field.cpp
 *
 *  Created on: 2013/02/24
 *      Author: furukawayoshihiro
 */

#include <iostream>
#include <stdlib.h>
#include "Field.h"

Field::Field() : Width_(0), Hight_(0) {
	// TODO Auto-generated constructor stub

}

Field::Field(int Width, int Hight)  : Width_(Width-1), Hight_(Hight-1) {
//	cells[Width][Hight];
}

Field::~Field() {
	// TODO Auto-generated destructor stub
	for(cellIterator_ = cellOfField_.begin(); cellIterator_ != cellOfField_.end(); ++cellIterator_) {
		delete *cellIterator_;
	}
}

void Field::prepairField() {
	for(int y = 0; y <= Hight_; ++y){
		for(int x = 0; x <= Width_; ++x){
			cellOfField_.push_back(new Cell(x, y));
		}
	}
	establishedRelationBwtweenCell();
}

Cell* Field::getCell(int xPosition, int yPosition) {
	return cellOfField_.at(calculateContainerPositionFromXY(xPosition, yPosition));
}

void Field::initializeField() {
	int numberOfAliveCell;
	int xPosition;
	int yPosition;

	std::cout << "Number of Alive Cell when Initialization : ";
	std::cin >> numberOfAliveCell;

	for(int i = 0; i < numberOfAliveCell; ++i){
		std::cout << "Alive Cell(x) : ";
		std::cin >> xPosition;
		std::cout << "Alive Cell(y) : ";
		std::cin >> yPosition;
		getCell(xPosition, yPosition)->setAlive();
	}
	printField();
}

void Field::establishedRelationBwtweenCell() {
	for(cellIterator_ = cellOfField_.begin(); cellIterator_ != cellOfField_.end(); ++cellIterator_) {
		(*cellIterator_)->establishRelation(this);
	}
}

void Field::printField() {
	int width(0);
	for(cellIterator_ = cellOfField_.begin(); cellIterator_ != cellOfField_.end(); ++cellIterator_) {
		(*cellIterator_)->printMark();
		std::cout << " ";
		if(width++ == Width_ ) {
			std::cout << std::endl;
			width = 0;
		}
	}
}

void Field::decideNextGeneration() {
	for(cellIterator_ = cellOfField_.begin(); cellIterator_ != cellOfField_.end(); ++cellIterator_) {
		(*cellIterator_)->decideNextGeneration();
	}
}

void Field::updateGeneration() {
	for(cellIterator_ = cellOfField_.begin(); cellIterator_ != cellOfField_.end(); ++cellIterator_) {
		(*cellIterator_)->updateGeneration();
	}
}

int Field::calculateContainerPositionFromXY(int xPosition, int yPosition) {
	return (xPosition)+(yPosition*(Width_+1));
}

void Field::run() {
	system("clear");
	decideNextGeneration();
	updateGeneration();
	printField();
}
