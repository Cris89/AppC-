/*
 * Random.cpp
 *
 *  Created on: Oct 23, 2016
 *      Author: cris
 */

#include "../include/Random.h"

#include <unistd.h>

#include <iostream>

#include "../include/MQTT.h"

#define LENGTH		10
#define TOPIC		"RandomStringsAppCpp"
#define TOPICSUB	"CountsAppPy"

using namespace std;

Random::Random() {
	// TODO Auto-generated constructor stub

}

char Random::generateRandomChar() {

	return "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[rand() % 52];

}

void Random::generateRandomString(char string[]) {

	srand((unsigned) time( NULL));

	for (int i = 0; i < LENGTH; i++)
		string[i] = generateRandomChar();

}

Random::~Random() {
	// TODO Auto-generated destructor stub

}

int main() {

	const char *pt = TOPIC;
	const char *pts = TOPICSUB;

	Random random;
	MQTT mqtt;

	mqtt.connect();
	mqtt.subscribe(pts);

	char randomString[LENGTH];

	for (int i = 0; i < 50; i++) {
		random.generateRandomString(randomString);
		char *s = randomString;
		mqtt.publish(s, pt);
		usleep(1000000);
	}

	cout << "Press Enter to End";
	char ch = getchar();
	return 0;

}
