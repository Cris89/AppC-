/*
 * Random.h
 *
 *  Created on: Oct 23, 2016
 *      Author: cris
 */

#ifndef RANDOM_H_
#define RANDOM_H_

#include <string>

using namespace std;

class Random {
public:
	Random();

	char generateRandomChar();
	void generateRandomString(string string);

	virtual ~Random();

};

#endif /* RANDOM_H_ */
