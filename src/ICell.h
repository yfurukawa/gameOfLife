/*
 * ICell.h
 *
 *  Created on: 2013/03/02
 *      Author: furukawayoshihiro
 */

#ifndef ICELL_H_
#define ICELL_H_

class Field;

class ICell {
public:
	ICell();
	virtual ~ICell();
	virtual int isAlive() = 0;
	virtual void setAlive() = 0;
	virtual void updateGeneration() = 0;
	virtual void decideNextGeneration() = 0;
	virtual void printMark() = 0;
	virtual void establishRelation(Field* field) = 0;
};

#endif /* ICELL_H_ */
