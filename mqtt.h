/*
 * MQTT.h
 *
 *  Created on: Oct 24, 2016
 *      Author: cris
 */

#ifndef MQTT_H_
#define MQTT_H_

#include "MQTTClient.h"

class MQTT {
public:

	MQTT();

	void connect();
	void publish(char *payload, const char *topicName);
	void subscribe(const char *topic);
	void unsubscrube(const char *topic);
	void disconnect();

	static MQTTClient_messageArrived messageArrived;

	virtual ~MQTT();

	MQTTClient client;
	int rc;

};

#endif /* MQTT_H_ */
