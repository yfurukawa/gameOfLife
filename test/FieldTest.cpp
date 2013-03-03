/*
 * FieldTest.cpp
 *
 *  Created on: 2013/02/24
 *      Author: furukawayoshihiro
 */

#include "FieldTest.h"

void FieldTest::SetUp() {
	sut = new FieldMock(10,20);
}

void FieldTest::TearDown() {
//	if(sut != NULL){
//		delete sut;
//		sut = NULL;
//	}
}

TEST_F(FieldTest, MaxSize) {
	EXPECT_EQ(9, sut->getWidth());
	EXPECT_EQ(19, sut->getHight());
}

TEST_F(FieldTest, fillInCellsToField){
	sut->prepairField();
	EXPECT_EQ(false, sut->getCell(0,0)->isAlive());
}

TEST_F(FieldTest, AccessToSecondCell) {
	sut->prepairField();
	sut->getCell(9,19)->setAlive();
	EXPECT_EQ(true, sut->getCell(9,19)->isAlive());
}

TEST_F(FieldTest, checkNmberOfInstanceOfCellInConteiner) {
	sut->prepairField();
	EXPECT_EQ(200, sut->getConteinerSize());
}

TEST_F(FieldTest, ConteinerPositionIsOne) {
	EXPECT_EQ(0, sut->calculateContainerPositionFromXY(0,0));
}

TEST_F(FieldTest, ConteinerPositionIsSameAsFieldWidth) {
	EXPECT_EQ(9, sut->calculateContainerPositionFromXY(9,0));
}

TEST_F(FieldTest, ConteinerPosition) {
	EXPECT_EQ(199, sut->calculateContainerPositionFromXY(9,19));
}
//TEST(Field, IsAliveWhenCellSetAliveInInitialize) {
//	Field* field;
//	field = new Field(10,10);
//	field->prepairField();
//	field->initializeField();
//	EXPECT_EQ(true, field->getCell(0,0)->isAlive());
//	field->printField();
//}


