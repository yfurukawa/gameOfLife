/*
 * main.cpp
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */

#include <iostream>
#include "Cell.h"

int main(int argc, char** argv) {
	Cell* cell1;
	Cell* cell2;

	cell1 = new Cell();
	cell2 = new Cell();

	std::cout << cell1 << std::endl;
	std::cout << cell2 << std::endl;

	delete cell1;
	delete cell2;
}

