/*
 * Cell.cpp
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */
#include <iostream>
#include "Cell.h"
#include "NullCell.h"
#include "Field.h"

Cell::Cell() : xPosition_(0), yPosition_(0), isAlive_(false), candidateAlive_(false), UpperLeftCell_(NULL), UpperCell_(NULL), UpperRightCell_(NULL),
		LeftCell_(NULL), RightCell_(NULL), LowerLeftCell_(NULL), LowerCell_(NULL), LowerRightCell_(NULL) {
	// TODO Auto-generated constructor stub
}

Cell::Cell(int xPosition, int yPosition) : xPosition_(xPosition), yPosition_(yPosition), isAlive_(false), candidateAlive_(false), UpperLeftCell_(NULL), UpperCell_(NULL), UpperRightCell_(NULL),
		LeftCell_(NULL), RightCell_(NULL), LowerLeftCell_(NULL), LowerCell_(NULL), LowerRightCell_(NULL) {
	// TODO Auto-generated constructor stub
	if(xPosition < 0) {
		xPosition_ = 0;
	}
	if(yPosition < 0) {
		yPosition_ = 0;
	}
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
	else if(numberOfAliveCell == 2 && isAlive()) {
		candidateAlive_ = true;
	}
	else if (numberOfAliveCell == 3) {
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

void Cell::establshUpperRow(Field* field) {
	if(yPosition_ == 0) {
		setUpperLeftCell(new NullCell());
		setUpperCell(new NullCell());
		setUpperRightCell(new NullCell());
	}
	else if(xPosition_ == 0 ) {
		setUpperLeftCell(new NullCell());
		setUpperCell(field->getCell(xPosition_, yPosition_-1));
		setUpperRightCell(field->getCell(xPosition_+1, yPosition_-1));
	}
	else if(xPosition_ == field->getWidth()-1){
		setUpperLeftCell(field->getCell(xPosition_-1, yPosition_-1));
		setUpperCell(field->getCell(xPosition_, yPosition_-1));
		setUpperRightCell(new NullCell());
	}
	else {
		setUpperLeftCell(field->getCell(xPosition_-1, yPosition_-1));
		setUpperCell(field->getCell(xPosition_, yPosition_-1));
		setUpperRightCell(field->getCell(xPosition_+1, yPosition_-1));
	}
}

void Cell::establishMiddleRow(Field* field) {
	if(xPosition_ == 0 ) {
		setLeftCell(new NullCell());
		setRightCell(field->getCell(xPosition_+1, yPosition_));
	}
	else if(xPosition_ == field->getWidth()-1){
		setLeftCell(field->getCell(xPosition_-1, yPosition_));
		setRightCell(new NullCell());
	}
	else {
		setLeftCell(field->getCell(xPosition_-1, yPosition_));
		setRightCell(field->getCell(xPosition_+1, yPosition_));
	}
}

void Cell::establishLowerRow(Field* field) {
	if(yPosition_ == field->getHight()-1) {
		setLowerLeftCell(new NullCell());
		setLowerCell(new NullCell());
		setLowerRightCell(new NullCell());
	}
	else if(xPosition_ == 0 ) {
		setLowerLeftCell(new NullCell());
		setLowerCell(field->getCell(xPosition_, yPosition_+1));
		setLowerRightCell(field->getCell(xPosition_+1, yPosition_+1));
	}
	else if(xPosition_ == field->getWidth()-1){
		setLowerLeftCell(field->getCell(xPosition_-1, yPosition_+1));
		setLowerCell(field->getCell(xPosition_, yPosition_+1));
		setLowerRightCell(new NullCell());
	}
	else {
		setLowerLeftCell(field->getCell(xPosition_-1, yPosition_+1));
		setLowerCell(field->getCell(xPosition_, yPosition_+1));
		setLowerRightCell(field->getCell(xPosition_+1, yPosition_+1));
	}
}

void Cell::establishRelation(Field* field) {
	establshUpperRow(field);
	establishMiddleRow(field);
	establishLowerRow(field);
}
