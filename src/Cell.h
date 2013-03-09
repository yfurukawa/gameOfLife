/*
 * Cell.h
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */

#ifndef CELL_H_
#define CELL_H_

#include <string>
#include "ICell.h"

class Field;

class Cell : public ICell{
private:
	int xPosition_;
	int yPosition_;
	std::string isAlive_;
	std::string candidateAlive_;
	ICell* UpperLeftCell_;
	ICell* UpperCell_;
	ICell* UpperRightCell_;
	ICell* LeftCell_;
	ICell* RightCell_;
	ICell* LowerLeftCell_;
	ICell* LowerCell_;
	ICell* LowerRightCell_;

	bool isCellRightLimit(Field* field);
	bool isCellLowerLimit(Field* field);
	bool isCellUpperLimit();
	bool isCellLeftLimit();

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
	bool isBone(int numberOfAliveCell);
	bool isKeepingAlive(int numberOfAliveCell);

public:
	Cell();
	Cell(int xPosition, int yPosition);
	virtual ~Cell();
	virtual int isAlive();
	void setAlive() {
		isAlive_ = "*";
	}

	void updateGeneration();
	void decideNextGeneration();
	void printMark();
	void establishRelation(Field* field);
};

#endif /* CELL_H_ */
