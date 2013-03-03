/*
 * FieldMock.cpp
 *
 *  Created on: 2013/03/03
 *      Author: furukawayoshihiro
 */

#include "FieldMock.h"

FieldMock::FieldMock() {
	// TODO Auto-generated constructor stub

}

FieldMock::FieldMock(int Width, int Hight) : Field(Width, Hight) {
}

FieldMock::~FieldMock() {
	// TODO Auto-generated destructor stub
}

int FieldMock::getConteinerSize() {
	return cellOfField_.size();
}

int FieldMock::calculateContainerPositionFromXY(int xPosition, int yPosition) {
	return Field::calculateContainerPositionFromXY(xPosition, yPosition);
}
