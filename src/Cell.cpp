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

Cell::Cell() : xPosition_(0), yPosition_(0), isAlive_("-"), candidateAlive_("-"), UpperLeftCell_(NULL), UpperCell_(NULL), UpperRightCell_(NULL),
		LeftCell_(NULL), RightCell_(NULL), LowerLeftCell_(NULL), LowerCell_(NULL), LowerRightCell_(NULL) {
	// TODO Auto-generated constructor stub
}

Cell::Cell(int xPosition, int yPosition) : xPosition_(xPosition < 0 ? 0 : xPosition), yPosition_(yPosition < 0 ? 0 : yPosition), isAlive_("-"), candidateAlive_("-"), UpperLeftCell_(NULL), UpperCell_(NULL), UpperRightCell_(NULL),
		LeftCell_(NULL), RightCell_(NULL), LowerLeftCell_(NULL), LowerCell_(NULL), LowerRightCell_(NULL) {
	// TODO Auto-generated constructor stub

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

int Cell::isAlive() {
	return (isAlive_ == "*") ? 1 : 0;
}

int Cell::checkNumberOfNeiborhoodIsAlive() {
	int count(0);

	count += UpperLeftCell_->isAlive();
	count += UpperCell_->isAlive();
	count += UpperRightCell_->isAlive();
	count += LeftCell_->isAlive();
	count += RightCell_->isAlive();
	count += LowerLeftCell_->isAlive();
	count += LowerCell_->isAlive();
	count += LowerRightCell_->isAlive();

	return count;
}

void Cell::updateGeneration() {
	isAlive_ = candidateAlive_;
}

bool Cell::isBone(int numberOfAliveCell) {
	return numberOfAliveCell == 2 && isAlive();
}

bool Cell::isKeepingAlive(int numberOfAliveCell) {
	return numberOfAliveCell == 3;
}

void Cell::decideNextGeneration() {
	int numberOfAliveCell = checkNumberOfNeiborhoodIsAlive();
	candidateAlive_ = (isBone(numberOfAliveCell) || isKeepingAlive(numberOfAliveCell)) ? "*" : "-";
}

void Cell::printMark() {
	std::cout << isAlive_;
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
