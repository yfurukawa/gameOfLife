/*
 * CellTest.cpp
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */

#include <gtest/gtest.h>
#include "CellTest.h"
#include "NullCell.h"


void CellTest::SetUp() {
	sut = new CellMock();
	neiborhoodCell = new CellMock();
	nullCell = new NullCell();
}

void CellTest::TearDown() {
	delete sut;
	sut = NULL;

	delete neiborhoodCell;
	neiborhoodCell = NULL;

	delete nullCell;
	nullCell = NULL;
}

TEST_F(CellTest, initialize){
	EXPECT_EQ(0, sut->isAlive());
}

TEST_F(CellTest, initialize_alive) {
	sut->setAlive();
	EXPECT_EQ(1, sut->isAlive());
}

TEST_F(CellTest, checkAliveNeiborhoodIsZero) {
	sut->setUpperLeftCell(neiborhoodCell);
	sut->setUpperCell(neiborhoodCell);
	sut->setUpperRightCell(neiborhoodCell);
	sut->setLeftCell(neiborhoodCell);
	sut->setRightCell(neiborhoodCell);
	sut->setLowerLeftCell(neiborhoodCell);
	sut->setLowerCell(neiborhoodCell);
	sut->setLowerRightCell(neiborhoodCell);
	EXPECT_EQ(0, sut->checkNumberOfNeiborhoodIsAlive());
}

TEST_F(CellTest, checkAliveNeiborhoodIsOne) {
	prepairOneAliveCell();
	EXPECT_EQ(1, sut->checkNumberOfNeiborhoodIsAlive());
}

TEST_F(CellTest, checkAliveNeiborhoodIsTwo) {
	prepairTwoAliveCells();
	EXPECT_EQ(2, sut->checkNumberOfNeiborhoodIsAlive());
}

TEST_F(CellTest, nextGenerationIsBoned) {
	prepairThreeAliveCells();
	sut->decideNextGeneration();
	sut->updateGeneration();
	EXPECT_EQ(1, sut->isAlive());
}

TEST_F(CellTest, nextGenertionIsAlive) {
	prepairTwoAliveCells();
	sut->setAlive();
	sut->decideNextGeneration();
	sut->updateGeneration();
	EXPECT_EQ(true, sut->isAlive());
}

TEST_F(CellTest, nextGenertionIsAliveEther) {
	prepairThreeAliveCells();
	sut->setAlive();
	sut->decideNextGeneration();
	sut->updateGeneration();
	EXPECT_EQ(1, sut->isAlive());
}

TEST_F(CellTest, nextGenerationIsDieDueToDepopulation) {
	prepairOneAliveCell();
	sut->setAlive();
	sut->decideNextGeneration();
	sut->updateGeneration();
	EXPECT_EQ(0, sut->isAlive());
}

TEST_F(CellTest, AliveToDieDueToDepopulation) {
	prepairTwoAliveCells();
	sut->decideNextGeneration();
	sut->updateGeneration();

	prepairOneAliveCell();
	sut->decideNextGeneration();
	sut->updateGeneration();
	EXPECT_EQ(0, sut->isAlive());
}

TEST_F(CellTest, AliveToDieDueToOverpopulation) {
	prepairTwoAliveCells();
	sut->decideNextGeneration();
	sut->updateGeneration();
	prepairFourAliveCells();
	sut->decideNextGeneration();
	sut->updateGeneration();
	EXPECT_EQ(0, sut->isAlive());
}

TEST_F(CellTest, printDashMarkWhenCellIsDead) {
	EXPECT_EQ("-", sut->printMarkCheck());
}

TEST_F(CellTest, printAstahriskMarkWhenCellIsAlive) {
	sut->setAlive();
	EXPECT_EQ("*", sut->printMarkCheck());
}

void CellTest::prepairOneAliveCell() {
	sut->setUpperLeftCell(nullCell);
	sut->setUpperCell(nullCell);
	sut->setUpperRightCell(nullCell);
	sut->setLeftCell(nullCell);
	sut->setRightCell(nullCell);
	sut->setLowerLeftCell(nullCell);
	sut->setLowerCell(nullCell);
	neiborhoodCell->setAlive();
	sut->setLowerRightCell(neiborhoodCell);
}

void CellTest::prepairTwoAliveCells() {
	sut->setUpperLeftCell(nullCell);
	sut->setUpperCell(nullCell);
	sut->setUpperRightCell(nullCell);
	sut->setLeftCell(nullCell);
	sut->setRightCell(nullCell);
	sut->setLowerLeftCell(nullCell);

	neiborhoodCell->setAlive();
	sut->setLowerCell(neiborhoodCell);
	sut->setLowerRightCell(neiborhoodCell);
}

void CellTest::prepairThreeAliveCells() {
	sut->setUpperLeftCell(nullCell);
	sut->setUpperCell(nullCell);
	sut->setUpperRightCell(nullCell);
	sut->setLeftCell(nullCell);
	sut->setRightCell(nullCell);

	neiborhoodCell->setAlive();
	sut->setLowerLeftCell(neiborhoodCell);
	sut->setLowerCell(neiborhoodCell);
	sut->setLowerRightCell(neiborhoodCell);
}

void CellTest::prepairFourAliveCells() {
	sut->setUpperLeftCell(nullCell);
	sut->setUpperCell(nullCell);
	sut->setUpperRightCell(nullCell);
	sut->setLeftCell(nullCell);

	neiborhoodCell->setAlive();
	sut->setRightCell(neiborhoodCell);
	sut->setLowerLeftCell(neiborhoodCell);
	sut->setLowerCell(neiborhoodCell);
	sut->setLowerRightCell(neiborhoodCell);
}
