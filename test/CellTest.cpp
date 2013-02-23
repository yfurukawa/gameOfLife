/*
 * CellTest.cpp
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */

#include "CellTest.h"
#include "NullCell.h"

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

TEST_F(CellTest, checkAliveNeiborhoodIsZero) {
	Cell* cell;
	cell = new Cell();
	cell->setUpperLeftCell(cell);
	cell->setUpperCell(cell);
	cell->setUpperRightCell(cell);
	cell->setLeftCell(cell);
	cell->setRightCell(cell);
	cell->setLowerLeftCell(cell);
	cell->setLowerCell(cell);
	cell->setLowerRightCell(cell);
	EXPECT_EQ(0, cell->checkNumberOfNeiborhoodIsAlive());
}

TEST_F(CellTest, checkAliveNeiborhoodIsOne) {
	Cell* neiborhoodCell;
	neiborhoodCell = new Cell();
	cell->setUpperLeftCell(neiborhoodCell);
	neiborhoodCell = new NullCell();
	cell->setUpperCell(neiborhoodCell);
	cell->setUpperRightCell(neiborhoodCell);
	cell->setLeftCell(neiborhoodCell);
	cell->setRightCell(neiborhoodCell);
	cell->setLowerLeftCell(neiborhoodCell);
	cell->setLowerCell(neiborhoodCell);
	delete neiborhoodCell;
	Cell* neiborCell;
	neiborCell = new Cell();
	neiborCell->setAlive();
	cell->setLowerRightCell(neiborCell);
	EXPECT_EQ(1, cell->checkNumberOfNeiborhoodIsAlive());
	delete neiborCell;
}

