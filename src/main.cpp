/*
 * main.cpp
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */

#include <iostream>
#include "Field.h"

int main(int argc, char** argv) {
	Field* field;
	field = new Field(20, 20);

	field->prepairField();
	field->initializeField();
	field->run();
}

