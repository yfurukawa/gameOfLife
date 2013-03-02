/*
 * Cell.h
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */

#ifndef CELL_H_
#define CELL_H_

//#include "Field.h"
class Field;

class Cell {
private:
	int xPosition_;
	int yPosition_;
	bool isAlive_;
	bool candidateAlive_;
	Cell* UpperLeftCell_;
	Cell* UpperCell_;
	Cell* UpperRightCell_;
	Cell* LeftCell_;
	Cell* RightCell_;
	Cell* LowerLeftCell_;
	Cell* LowerCell_;
	Cell* LowerRightCell_;

	void establshUpperRow(Field* field);
	void establishMiddleRow(Field* field);
	void establishLowerRow(Field* field);
public:
	Cell();
	Cell(int xPosition, int yPosition);
	virtual ~Cell();
	virtual bool isAlive();
	void setAlive() {
		isAlive_ = true;
	}
	void setLeftCell(Cell* leftCell);
	void setLowerCell(Cell* lowerCell);
	void setLowerLeftCell(Cell* lowerLeftCell);
	void setLowerRightCell(Cell* lowerRightCell);
	void setRightCell(Cell* rightCell);
	void setUpperCell(Cell* upperCell);
	void setUpperLeftCell(Cell* upperLeftCell);
	void setUpperRightCell(Cell* upperRightCell);
	int checkNumberOfNeiborhoodIsAlive();
	void updateGeneration();
	void decideNextGeneration();
	void printMark();
	void establishRelation(Field* field);
};

#endif /* CELL_H_ */
