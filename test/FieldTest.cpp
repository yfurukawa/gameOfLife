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



