/*
 * Field.h
 *
 *  Created on: 2013/02/24
 *      Author: furukawayoshihiro
 */

#ifndef FIELD_H_
#define FIELD_H_

class Field {
private:
	int Width_;
	int Hight_;

public:
	Field();
	Field(int Width, int Hight);
	virtual ~Field();

	int getHight() const {
		return Hight_;
	}

	int getWidth() const {
		return Width_;
	}
};

#endif /* FIELD_H_ */
