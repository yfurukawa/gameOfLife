/*
 * Cell.h
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */

#ifndef CELL_H_
#define CELL_H_

#include "ICell.h"

class Field;

class Cell : public ICell{
private:
	int xPosition_;
	int yPosition_;
	bool isAlive_;
	bool candidateAlive_;
	ICell* UpperLeftCell_;
	ICell* UpperCell_;
	ICell* UpperRightCell_;
	ICell* LeftCell_;
	ICell* RightCell_;
	ICell* LowerLeftCell_;
	ICell* LowerCell_;
	ICell* LowerRightCell_;

protected:
	void establshUpperRow(Field* field);
	void establishMiddleRow(Field* field);
	void establishLowerRow(Field* field);
	void setLeftCell(ICell* leftCell);
	void setLowerCell(ICell* lowerCell);
	void setLowerLeftCell(ICell* lowerLeftCell);
	void setLowerRightCell(ICell* lowerRightCell);
	void setRightCell(ICell* rightCell);
	void setUpperCell(ICell* upperCell);
	void setUpperLeftCell(ICell* upperLeftCell);
	void setUpperRightCell(ICell* upperRightCell);
	int checkNumberOfNeiborhoodIsAlive();

public:
	Cell();
	Cell(int xPosition, int yPosition);
	virtual ~Cell();
	virtual bool isAlive();
	void setAlive() {
		isAlive_ = true;
	}

	void updateGeneration();
	void decideNextGeneration();
	void printMark();
	void establishRelation(Field* field);
};

#endif /* CELL_H_ */
