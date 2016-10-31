/*
 * Random.cpp
 *
 *  Created on: Oct 23, 2016
 *      Author: cris
 */

#include "random.h"
#include "mqtt.h"

#include <unistd.h>

#define LENGTH		10
#define TOPIC		"RandomStringsAppCpp"
#define TOPICSUB	"CountsAppPy"

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

	for (int i = 0; i < 10; i++) {
		random.generateRandomString(randomString);
		char *s = randomString;
		mqtt.publish(s, pt);
		usleep(1000000);
	}

}
