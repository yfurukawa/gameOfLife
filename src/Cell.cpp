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

void Cell::setLeftCell(ICell* leftCell) {
	LeftCell_ = leftCell;
}

void Cell::setLowerCell(ICell* lowerCell) {
	LowerCell_ = lowerCell;
}

void Cell::setLowerLeftCell(ICell* lowerLeftCell) {
	LowerLeftCell_ = lowerLeftCell;
}

void Cell::setLowerRightCell(ICell* lowerRightCell) {
	LowerRightCell_ = lowerRightCell;
}

void Cell::setRightCell(ICell* rightCell) {
	RightCell_ = rightCell;
}

void Cell::setUpperCell(ICell* upperCell) {
	UpperCell_ = upperCell;
}

void Cell::setUpperLeftCell(ICell* upperLeftCell) {
	UpperLeftCell_ = upperLeftCell;
}

void Cell::setUpperRightCell(ICell* upperRightCell) {
	UpperRightCell_ = upperRightCell;
}

bool Cell::isAlive() {
	return isAlive_;
}

int Cell::checkNumberOfNeiborhoodIsAlive() {
	int count(0);
	if(UpperLeftCell_->isAlive()) {
		++count;
	}
	if(UpperCell_->isAlive()) {
		++count;
	}
	if(UpperRightCell_->isAlive()) {
		++count;
	}
	if(LeftCell_->isAlive()) {
		++count;
	}
	if(RightCell_->isAlive()) {
		++count;
	}
	if(LowerLeftCell_->isAlive()) {
		++count;
	}
	if(LowerCell_->isAlive()) {
		++count;
	}
	if(LowerRightCell_->isAlive()) {
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

bool Cell::isCellUpperLimit() {
	return yPosition_ == 0;
}

bool Cell::isCellLeftLimit() {
	return xPosition_ == 0;
}

void Cell::establshUpperRow(Field* field) {
	if (isCellUpperLimit()) {
		setUpperLeftCell(new NullCell());
		setUpperCell(new NullCell());
		setUpperRightCell(new NullCell());
	}
	else if (isCellLeftLimit()) {
		setUpperLeftCell(new NullCell());
		setUpperCell(field->getCell(xPosition_, yPosition_-1));
		setUpperRightCell(field->getCell(xPosition_+1, yPosition_-1));
	}
	else if(isCellRightLimit(field)){
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
	if(isCellLeftLimit()) {
		setLeftCell(new NullCell());
		setRightCell(field->getCell(xPosition_+1, yPosition_));
	}
	else if(isCellRightLimit(field)){
		setLeftCell(field->getCell(xPosition_-1, yPosition_));
		setRightCell(new NullCell());
	}
	else {
		setLeftCell(field->getCell(xPosition_-1, yPosition_));
		setRightCell(field->getCell(xPosition_+1, yPosition_));
	}
}

void Cell::establishLowerRow(Field* field) {
	if(isCellLowerLimit(field)) {
		setLowerLeftCell(new NullCell());
		setLowerCell(new NullCell());
		setLowerRightCell(new NullCell());
	}
	else if(isCellLeftLimit()) {
		setLowerLeftCell(new NullCell());
		setLowerCell(field->getCell(xPosition_, yPosition_+1));
		setLowerRightCell(field->getCell(xPosition_+1, yPosition_+1));
	}
	else if(isCellRightLimit(field)){
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

bool Cell::isCellRightLimit(Field* field) {
	return xPosition_ == field->getWidth();
}

bool Cell::isCellLowerLimit(Field* field) {
	return yPosition_ == field->getHight();
}

void Cell::establishRelation(Field* field) {
	establshUpperRow(field);
	establishMiddleRow(field);
	establishLowerRow(field);
}
