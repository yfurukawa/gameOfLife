/*
 * Field.h
 *
 *  Created on: 2013/02/24
 *      Author: furukawayoshihiro
 */

#ifndef FIELD_H_
#define FIELD_H_

#include "Cell.h"

class Field {
private:
	int Width_;
	int Hight_;
	Cell* cells[25][25];

public:
	Field();
	Field(int Width, int Hight);
	virtual ~Field();

	int getHight() const {
		return Hight_;
	}

	int getWidth() const {
		return Width_;
	}
	void prepairField();
	void initializeField();
	Cell* getCell(int xPosition, int yPosition);
	void printField();
};

#endif /* FIELD_H_ */
