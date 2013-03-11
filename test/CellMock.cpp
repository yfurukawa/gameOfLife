/*
 * CellMock.cpp
 *
 *  Created on: 2013/03/02
 *      Author: furukawayoshihiro
 */

#include <iostream>
#include <sstream>
#include "CellMock.h"

CellMock::CellMock() {
	// TODO Auto-generated constructor stub

}

CellMock::~CellMock() {
	// TODO Auto-generated destructor stub
}

void CellMock::setLeftCell(ICell* leftCell) {
	Cell::setLeftCell(leftCell);
}

void CellMock::setLowerCell(ICell* lowerCell) {
	Cell::setLowerCell(lowerCell);
}

void CellMock::setLowerLeftCell(ICell* lowerLeftCell) {
	Cell::setLowerLeftCell(lowerLeftCell);
}

void CellMock::setLowerRightCell(ICell* lowerRightCell) {
	Cell::setLowerRightCell(lowerRightCell);
}

void CellMock::setRightCell(ICell* rightCell) {
	Cell::setRightCell(rightCell);
}

void CellMock::setUpperCell(ICell* upperCell) {
	Cell::setUpperCell(upperCell);
}

void CellMock::setUpperLeftCell(ICell* upperLeftCell) {
	Cell::setUpperLeftCell(upperLeftCell);
}

void CellMock::setUpperRightCell(ICell* upperRightCell) {
	Cell::setUpperRightCell(upperRightCell);
}

int CellMock::checkNumberOfNeiborhoodIsAlive() {
	return Cell::checkNumberOfNeiborhoodIsAlive();
}

std::string CellMock::printMarkCheck() {
    std::stringstream ss;
    std::streambuf* oldrdbuf = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    Cell::printMark();

    std::cout.rdbuf(oldrdbuf);
	return ss.str();
}
