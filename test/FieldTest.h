/*
 * FieldTest.h
 *
 *  Created on: 2013/03/03
 *      Author: furukawayoshihiro
 */

#ifndef FIELDTEST_H_
#define FIELDTEST_H_

#include <gtest/gtest.h>
#include <iostream>
#include "FieldMock.h"

class FieldTest : public ::testing::Test {
protected:
	FieldMock* sut;

public:
	FieldTest() : sut(NULL) {};
	virtual ~FieldTest() {};
	virtual void SetUp();
	virtual void TearDown();
};


#endif /* FIELDTEST_H_ */
