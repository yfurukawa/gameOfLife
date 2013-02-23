/*
 * CellTest.cpp
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */

#include "CellTest.h"

void CellTest::SetUp() {
	cell = new Cell();
}

void CellTest::TearDown() {
	delete cell;
	cell = NULL;
}

TEST_F(CellTest, initialize){
	EXPECT_EQ(false, cell->isAlive());
}

TEST_F(CellTest, initialize_alive) {
	cell->setAlive();
	EXPECT_EQ(true, cell->isAlive());
}

