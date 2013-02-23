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
public:
	Cell();
	Cell(bool isAlive);
	virtual ~Cell();
	bool isAlive();
};

#endif /* CELL_H_ */
