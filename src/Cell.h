/*
 * Cell.h
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */

#ifndef CELL_H_
#define CELL_H_

class Cell {
private:
	bool isAlive_;
	Cell* UpperLeftCell_;
	Cell* UpperCell_;
	Cell* UpperRightCell_;
	Cell* LeftCell_;
	Cell* RightCell_;
	Cell* LowerLeftCell_;
	Cell* LowerCell_;
	Cell* LowerRightCell_;
public:
	Cell();
	virtual ~Cell();
	bool isAlive();
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

};

#endif /* CELL_H_ */
