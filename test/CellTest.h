/*
 * CellTest.h
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */

#ifndef CELLTEST_H_
#define CELLTEST_H_

#include <iostream>
#include <gtest/gtest.h>
#include "CellMock.h"

class CellTest : public ::testing::Test {
protected:
	CellMock* sut;
	CellMock* neiborhoodCell;
	ICell* nullCell;
protected:
	virtual void SetUp();
	virtual void TearDown();
	CellTest() : sut(NULL), neiborhoodCell(NULL), nullCell(NULL) {};
	virtual ~CellTest() {};
	void prepairOneAliveCell();
	void prepairTwoAliveCells();
	void prepairThreeAliveCells();
	void prepairFourAliveCells();
};


#endif /* CELLTEST_H_ */
