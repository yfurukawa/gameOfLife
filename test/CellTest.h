/*
 * CellTest.h
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */

#ifndef CELLTEST_H_
#define CELLTEST_H_

#include <gtest/gtest.h>
#include "../src/Cell.h"

class CellTest : public ::testing::Test {
protected:
	Cell* cell;
protected:
	virtual void SetUp();
	virtual void TearDown();
	CellTest() : cell(NULL) {};
	virtual ~CellTest() {};
};


#endif /* CELLTEST_H_ */
