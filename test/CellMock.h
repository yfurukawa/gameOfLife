/*
 * CellMock.h
 *
 *  Created on: 2013/03/02
 *      Author: furukawayoshihiro
 */

#ifndef CELLMOCK_H_
#define CELLMOCK_H_

#include "Cell.h"

class CellMock: public Cell {
public:
	CellMock();
	virtual ~CellMock();
	void setLeftCell(ICell* leftCell);
	void setLowerCell(ICell* lowerCell);
	void setLowerLeftCell(ICell* lowerLeftCell);
	void setLowerRightCell(ICell* lowerRightCell);
	void setRightCell(ICell* rightCell);
	void setUpperCell(ICell* upperCell);
	void setUpperLeftCell(ICell* upperLeftCell);
	void setUpperRightCell(ICell* upperRightCell);
	int checkNumberOfNeiborhoodIsAlive();
};

#endif /* CELLMOCK_H_ */
