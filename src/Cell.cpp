/*
 * Cell.cpp
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */

#include "Cell.h"

Cell::Cell() : isAlive_(false) {
	// TODO Auto-generated constructor stub

}

Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

Cell::Cell(bool isAlive) : isAlive_(isAlive) {
}

bool Cell::isAlive() {
	return isAlive_;
}
