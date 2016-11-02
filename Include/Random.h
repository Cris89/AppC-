/*
 * Random.h
 *
 *  Created on: Oct 23, 2016
 *      Author: cris
 */

#ifndef INCLUDE_RANDOM_H_
#define INCLUDE_RANDOM_H_

#include <string>

class Random {
public:
	Random();

	char generateRandomChar();
	void generateRandomString(char string[]);

	virtual ~Random();

};

#endif /* INCLUDE_RANDOM_H_ */
