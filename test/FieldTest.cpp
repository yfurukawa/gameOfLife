/*
 * FieldTest.cpp
 *
 *  Created on: 2013/02/24
 *      Author: furukawayoshihiro
 */

#include <gtest/gtest.h>
#include <ios>
#include "Field.h"

TEST(FieldTest, MaxSize) {
	Field* field;
	field = new Field(10,20);
	EXPECT_EQ(9, field->getWidth());
	EXPECT_EQ(19, field->getHight());
}

TEST(FieldTest, fillInCellsToField){
	Field* field;
	field = new Field(10,10);
	field->prepairField();
	EXPECT_EQ(false, field->getCell(0,0)->isAlive());
}

//TEST(Field, IsAliveWhenCellSetAliveInInitialize) {
//	Field* field;
//	field = new Field(10,10);
//	field->prepairField();
//	field->initializeField();
//	EXPECT_EQ(true, field->getCell(0,0)->isAlive());
//	field->printField();
//}


