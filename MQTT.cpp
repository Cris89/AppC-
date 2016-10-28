/*
 * MQTT.cpp
 *
 *  Created on: Oct 24, 2016
 *      Author: cris
 */
#include "MQTT.h"

#include "MQTTClient.h"

#include <cstring>

#define ADDRESS "127.0.0.1:8883"
#define CLIENTID "AppC++"
#define TIMEOUT 10000L

MQTT::MQTT() {

	rc = MQTTClient_create(&client, ADDRESS, CLIENTID,
	MQTTCLIENT_PERSISTENCE_DEFAULT, NULL);

}

void MQTT::connect() {

	MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
	conn_opts.keepAliveInterval = 10;
	conn_opts.cleansession = 1;
	rc = MQTTClient_connect(client, &conn_opts);

}

void MQTT::publish(const char *payload, const char *topicName) {

	int payloadlen = strlen(payload);
	int qos = 0;
	int retained = 0;
	MQTTClient_deliveryToken dt;
	rc = MQTTClient_publish(client, topicName, payloadlen, (void*) payload, qos,
			retained, &dt);
	printf("Waiting for up to %d seconds for publication of %s\n"
			"on topic %s for client with ClientID: %s\n",
			(int) (TIMEOUT / 1000), payload, topicName, CLIENTID);
	rc = MQTTClient_waitForCompletion(client, dt, TIMEOUT);
	printf("Message with delivery token %d delivered\n", dt);

}

void MQTT::subscribe(const char *topic) {
	int qos = 0;
	rc = MQTTClient_subscribe(client, topic, qos);
	printf("Subscribed to %s\n", topic);

}

void MQTT::unsubscrube(const char *topic) {

	rc = MQTTClient_unsubscribe(client, topic);

}

void MQTT::disconnect() {

	int timeout = 100;
	MQTTClient_disconnect(client, timeout);

}

//int MQTT::messageArrived(void *context, const char *topicName, int topicLen,
//		MQTTClient_message *message) {
//
//	printf("Message arrived\n");
//	printf("topic: %s\n", topicName);
//	printf("message: .*s\n", message->payloadlen, message->payload);
//
//	MQTTClient_freeMessage(&message);
//	MQTTClient_free((void *) topicName);
//	return 1;
//
//}

MQTT::~MQTT() {
	// TODO Auto-generated destructor stub
}
