/*
 * Field.h
 *
 *  Created on: 2013/02/24
 *      Author: furukawayoshihiro
 */

#ifndef FIELD_H_
#define FIELD_H_

#include <vector>
#include "Cell.h"

class Field {

private:
	int Width_;
	int Hight_;
	std::vector<Cell*> cellOfField_;
	std::vector<Cell*>::iterator cellIterator_;

	void establishedRelationBwtweenCell();
	void decideNextGeneration();
	void updateGeneration();
	void printField();
	int calculateContainerPositionFromXY(int xPosition, int yPosition);

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
	void run();
};

#endif /* FIELD_H_ */
