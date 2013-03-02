/*
 * Cell.cpp
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */
#include <iostream>
#include "Cell.h"

Cell::Cell() : isAlive_(false), candidateAlive_(false), UpperLeftCell_(NULL), UpperCell_(NULL), UpperRightCell_(NULL),
		LeftCell_(NULL), RightCell_(NULL), LowerLeftCell_(NULL), LowerCell_(NULL), LowerRightCell_(NULL) {
	// TODO Auto-generated constructor stub

}

Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

void Cell::setLeftCell(Cell* leftCell) {
	LeftCell_ = leftCell;
}

void Cell::setLowerCell(Cell* lowerCell) {
	LowerCell_ = lowerCell;
}

void Cell::setLowerLeftCell(Cell* lowerLeftCell) {
	LowerLeftCell_ = lowerLeftCell;
}

void Cell::setLowerRightCell(Cell* lowerRightCell) {
	LowerRightCell_ = lowerRightCell;
}

void Cell::setRightCell(Cell* rightCell) {
	RightCell_ = rightCell;
}

void Cell::setUpperCell(Cell* upperCell) {
	UpperCell_ = upperCell;
}

void Cell::setUpperLeftCell(Cell* upperLeftCell) {
	UpperLeftCell_ = upperLeftCell;
}

void Cell::setUpperRightCell(Cell* upperRightCell) {
	UpperRightCell_ = upperRightCell;
}

bool Cell::isAlive() {
	return isAlive_;
}

int Cell::checkNumberOfNeiborhoodIsAlive() {
	int count(0);
	if(UpperLeftCell_->isAlive_) {
		std::cout << UpperLeftCell_->isAlive_ << std::endl;
		++count;
	}
	if(UpperCell_->isAlive_) {
		++count;
	}
	if(UpperRightCell_->isAlive_) {
		++count;
	}
	if(LeftCell_->isAlive_) {
		++count;
	}
	if(RightCell_->isAlive_) {
		++count;
	}
	if(LowerLeftCell_->isAlive_) {
		++count;
	}
	if(LowerCell_->isAlive_) {
		++count;
	}
	if(LowerRightCell_->isAlive_) {
		++count;
	}

	return count;
}

void Cell::updateGeneration() {
	isAlive_ = candidateAlive_;
}

void Cell::decideNextGeneration() {
	int numberOfAliveCell = checkNumberOfNeiborhoodIsAlive();
	if(numberOfAliveCell == 1) {
		candidateAlive_ = false;
	}
	else if(numberOfAliveCell == 2) {
		candidateAlive_ = true;
	}
	else if (numberOfAliveCell == 3 && isAlive()) {
		candidateAlive_ = true;
	}
	else {
		candidateAlive_ = false;
	}
}

void Cell::printMark() {
	if(isAlive()) {
		std::cout << "*";
	}
	else {
		std::cout << "-";
	}
}
