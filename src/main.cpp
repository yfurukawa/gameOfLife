/*
 * main.cpp
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */

#include <iostream>
#include "Field.h"

volatile sig_atomic_t eflag = 0;

void handler(int signum) {
  eflag = 1;
}

int main(int argc, char** argv) {
	if (signal(SIGINT, handler) == SIG_ERR) {
		/* ƒGƒ‰[ˆ— */
	}

	Field* field;
	field = new Field(20, 20);

	field->prepairField();
	field->initializeField();
	while(!eflag) {
		field->run();
		sleep(1);
	}
	delete field;
}

