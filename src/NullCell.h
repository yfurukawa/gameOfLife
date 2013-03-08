/*
 * NullCell.h
 *
 *  Created on: 2013/02/24
 *      Author: furukawayoshihiro
 */

#ifndef NULLCELL_H_
#define NULLCELL_H_

#include "ICell.h"

class NullCell: public ICell {
public:
	NullCell();
	virtual ~NullCell();
	virtual int isAlive() {return 0;};
	virtual void setAlive(){};
	virtual void updateGeneration(){};
	virtual void decideNextGeneration(){};
	virtual void printMark(){};
	virtual void establishRelation(Field* field){};;
};

#endif /* NULLCELL_H_ */
