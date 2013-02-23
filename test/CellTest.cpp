/*
 * CellTest.cpp
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */

#include <gtest/gtest.h>
#include "../src/Cell.h"

TEST(CellTest, initialize){
	Cell* cell;
	cell = new Cell();
	EXPECT_EQ(false, cell->isAlive());
	delete cell;
}

TEST(CellTest, initialize_alive) {
	Cell* cell;
	cell = new Cell(true);
	EXPECT_EQ(true, cell->isAlive());
	delete cell;
}
