/*
 * main.cpp
 *
 *  Created on: 2013/02/23
 *      Author: furukawayoshihiro
 */

#include <iostream>
#include <stdlib.h>
#include "Field.h"

volatile sig_atomic_t eflag = 0;

void handler(int signum) {
  eflag = 1;
}

int main(int argc, char** argv) {
	if (signal(SIGINT, handler) == SIG_ERR) {
		/* ƒGƒ‰[ˆ— */
	}

	if(argc != 3) {
		std::cout << "Usage:" << std::endl;
		std::cout << "  gameOfLife width high" << std::endl;
		exit(1);
	}

	Field* field;
	field = new Field(atoi(argv[1]), atoi(argv[2]));

	field->prepairField();
	field->initializeField();
	while(!eflag) {
		field->run();
		sleep(1);
	}
	delete field;
}

