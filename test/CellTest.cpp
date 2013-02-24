/*
 * CellTest.cpp
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */

#include <gtest/gtest.h>
#include "CellTest.h"
#include "Cell.h"
#include "nullCell.h"


void CellTest::SetUp() {
	cell = new Cell();
	neiborhoodCell = new Cell();
	nullCell = new Cell();
}

void CellTest::TearDown() {
	delete cell;
	cell = NULL;

	delete neiborhoodCell;
	neiborhoodCell = NULL;

	delete nullCell;
	nullCell = NULL;
}

TEST_F(CellTest, initialize){
	EXPECT_EQ(false, cell->isAlive());
}

TEST_F(CellTest, initialize_alive) {
	cell->setAlive();
	EXPECT_EQ(true, cell->isAlive());
}

TEST_F(CellTest, checkAliveNeiborhoodIsZero) {
	cell->setUpperLeftCell(neiborhoodCell);
	cell->setUpperCell(neiborhoodCell);
	cell->setUpperRightCell(neiborhoodCell);
	cell->setLeftCell(neiborhoodCell);
	cell->setRightCell(neiborhoodCell);
	cell->setLowerLeftCell(neiborhoodCell);
	cell->setLowerCell(neiborhoodCell);
	cell->setLowerRightCell(neiborhoodCell);
	EXPECT_EQ(0, cell->checkNumberOfNeiborhoodIsAlive());
}

TEST_F(CellTest, checkAliveNeiborhoodIsOne) {
	cell->setUpperLeftCell(nullCell);
	cell->setUpperCell(nullCell);
	cell->setUpperRightCell(nullCell);
	cell->setLeftCell(nullCell);
	cell->setRightCell(nullCell);
	cell->setLowerLeftCell(nullCell);
	cell->setLowerCell(nullCell);

	neiborhoodCell->setAlive();
	cell->setLowerRightCell(neiborhoodCell);
	EXPECT_EQ(1, cell->checkNumberOfNeiborhoodIsAlive());
}

TEST_F(CellTest, checkAliveNeiborhoodIsTwo) {
	cell->setUpperLeftCell(nullCell);
	cell->setUpperCell(nullCell);
	cell->setUpperRightCell(nullCell);
	cell->setLeftCell(nullCell);
	cell->setRightCell(nullCell);
	cell->setLowerLeftCell(nullCell);

	neiborhoodCell->setAlive();
	cell->setLowerCell(neiborhoodCell);
	cell->setLowerRightCell(neiborhoodCell);
	EXPECT_EQ(2, cell->checkNumberOfNeiborhoodIsAlive());
}

TEST_F(CellTest, nextGenerationIsBoned) {
	cell->decideNextGeneration(2);
	cell->updateGeneration();
	EXPECT_EQ(true, cell->isAlive());
}

TEST_F(CellTest, nextGenertionIsNotAlive) {
	cell->decideNextGeneration(3);
	cell->updateGeneration();
	EXPECT_EQ(false, cell->isAlive());
}

TEST_F(CellTest, nextGenertionIsAliveEther) {
	cell->setAlive();
	cell->decideNextGeneration(3);
	cell->updateGeneration();
	EXPECT_EQ(true, cell->isAlive());
}

TEST_F(CellTest, nextGenerationIsDieDueToDepopulation) {
	cell->setAlive();
	cell->decideNextGeneration(1);
	cell->updateGeneration();
	EXPECT_EQ(false, cell->isAlive());
}

TEST_F(CellTest, AliveToDie) {
	cell->decideNextGeneration(2);
	cell->updateGeneration();
	cell->decideNextGeneration(1);
	cell->updateGeneration();
	EXPECT_EQ(false, cell->isAlive());
}
