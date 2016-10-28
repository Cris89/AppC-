/*
 * Random.cpp
 *
 *  Created on: Oct 23, 2016
 *      Author: cris
 */

#include "Random.h"

#include <cstdlib>
#include <iostream>

#include "stdio.h"
#include "stdlib.h"

#include "MQTT.h"

#define LENGTH 10
#define TOPIC "RandomStringsAppC"
#define TOPICSUB "RandomStringsAppPy"

Random::Random() {
	// TODO Auto-generated constructor stub

}

char Random::generateRandomChar() {

	return "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[rand() % 52];

}

void Random::generateRandomString(string string) {

	srand((unsigned) time( NULL));

	for (int i = 0; i < LENGTH; i++)
		string[i] = generateRandomChar();

}

Random::~Random() {
	// TODO Auto-generated destructor stub
}

int main() {

	Random random;
	MQTT mqtt;

	char randomString[LENGTH];
	random.generateRandomString(randomString);

	mqtt.connect();

	char *s = randomString;
	const char *pt = TOPIC;
	const char *pts = TOPICSUB;

	mqtt.subscribe(pts);
	mqtt.publish(s, pt);

}
