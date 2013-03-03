/*
 * FieldMock.h
 *
 *  Created on: 2013/03/03
 *      Author: furukawayoshihiro
 */

#ifndef FIELDMOCK_H_
#define FIELDMOCK_H_

#include "Field.h"

class FieldMock : public Field {

public:
	FieldMock();
	FieldMock(int Width, int Hight);
	virtual ~FieldMock();
	int getConteinerSize();
	int calculateContainerPositionFromXY(int xPosition, int yPosition);
};

#endif /* FIELDMOCK_H_ */
