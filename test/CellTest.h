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
#include "../src/Cell.h"

class CellTest : public ::testing::Test {
protected:
	Cell* cell;
	Cell* neiborhoodCell;
	Cell* nullCell;
protected:
	virtual void SetUp();
	virtual void TearDown();
	CellTest() : cell(NULL), neiborhoodCell(NULL), nullCell(NULL) {};
	virtual ~CellTest() {};
};


#endif /* CELLTEST_H_ */
