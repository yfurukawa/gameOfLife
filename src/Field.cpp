/*
 * Field.cpp
 *
 *  Created on: 2013/02/24
 *      Author: furukawayoshihiro
 */

#include <iostream>
#include "Field.h"

Field::Field() : Width_(0), Hight_(0) {
	// TODO Auto-generated constructor stub

}

Field::Field(int Width, int Hight)  : Width_(Width), Hight_(Hight) {
//	cells[Width][Hight];
}

Field::~Field() {
	// TODO Auto-generated destructor stub
	for(int y = 0; y < Hight_; ++y){
			for(int x = 0; x < Width_; ++x){
				delete getCell(x, y);
			}
		}
}

void Field::prepairField() {
	for(int y = 0; y < Hight_; ++y){
		for(int x = 0; x < Width_; ++x){
			cells[x][y] = new Cell(x,y);
		}
	}
	establishedRelationBwtweenCell();
}

Cell* Field::getCell(int xPosition, int yPosition) {
	return cells[xPosition][yPosition];
}

void Field::initializeField() {
	int numberOfAliveCell;
	int xPosition;
	int yPosition;

	std::cout << "������ԂŐ����Ă���Z���̐� : ";
	std::cin >> numberOfAliveCell;

	for(int i = 0; i < numberOfAliveCell; ++i){
		std::cout << "�����Ă���Z���̏ꏊ�ix�j : ";
		std::cin >> xPosition;
		std::cout << "�����Ă���Z���̏ꏊ�iy�j : ";
		std::cin >> yPosition;
		getCell(xPosition, yPosition)->setAlive();
	}
	printField();
}

void Field::establishedRelationBwtweenCell() {
	for(int y = 0; y < Hight_; ++y){
			for(int x = 0; x < Width_; ++x){
				getCell(x, y)->establishRelation(this);
			}
		}
}

void Field::printField() {
	for(int y = 0; y < Hight_; ++y){
		for(int x = 0; x < Width_; ++x){
			getCell(x, y)->printMark();
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void Field::decideNextGeneration() {
	for(int y = 0; y < Hight_; ++y){
			for(int x = 0; x < Width_; ++x){
				getCell(x, y)->decideNextGeneration();
			}
		}
}

void Field::updateGeneration() {
	for(int y = 0; y < Hight_; ++y){
			for(int x = 0; x < Width_; ++x){
				getCell(x, y)->updateGeneration();
			}
		}
}

void Field::run() {
	system("clear");
	decideNextGeneration();
	updateGeneration();
	printField();
}
