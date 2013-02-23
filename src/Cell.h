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
	virtual ~Cell();
	bool isAlive();
	void setAlive() { isAlive_ = true; };
};

#endif /* CELL_H_ */
