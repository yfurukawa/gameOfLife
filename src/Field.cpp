/*
 * Field.cpp
 *
 *  Created on: 2013/02/24
 *      Author: furukawayoshihiro
 */

#include "Field.h"

Field::Field() : Width_(0), Hight_(0) {
	// TODO Auto-generated constructor stub

}

Field::Field(int Width, int Hight)  : Width_(Width), Hight_(Hight) {
	Cell* cells[Width][Hight];
}

Field::~Field() {
	// TODO Auto-generated destructor stub
}

