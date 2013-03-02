/*
 * FieldTest.cpp
 *
 *  Created on: 2013/02/24
 *      Author: furukawayoshihiro
 */

#include <gtest/gtest.h>
#include "Field.h"

TEST(FieldTest, MaxSize) {
	Field* field;
	field = new Field(1,2);
	EXPECT_EQ(1, field->getWidth());
	EXPECT_EQ(2, field->getHight());
}

TEST(FieldTest, fillInCellsToField){
	Field* field;
	field = new Field(10,10);
	field->initializeField();
	EXPECT_EQ(true, field->getCell(0,0)->isAlive());
}

