/*
 * NullCell.h
 *
 *  Created on: 2013/02/24
 *      Author: furukawayoshihiro
 */

#ifndef NULLCELL_H_
#define NULLCELL_H_

#include "Cell.h"

class NullCell: public Cell {
public:
	NullCell();
	virtual ~NullCell();
	virtual bool isAlive() {return false;};
};

#endif /* NULLCELL_H_ */
