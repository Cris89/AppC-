/*
 * MQTT.cpp
 *
 *  Created on: Oct 24, 2016
 *      Author: cris
 */

#include "Include/MQTT.h"

#include "MQTTClient.h"

#include <cstring>

#define ADDRESS		"127.0.0.1:8883"
#define CLIENTID	"AppCpp"
#define TIMEOUT		10000L

MQTT::MQTT() {

	rc = MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
	rc= MQTTClient_setCallbacks(client, NULL, NULL, messageArrived, NULL);

}

void MQTT::connect() {

	MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
	conn_opts.keepAliveInterval = 10;
	conn_opts.cleansession = 1;
	rc = MQTTClient_connect(client, &conn_opts);
	printf("Client ID %s connected at %s\n", CLIENTID, ADDRESS);

}

void MQTT::publish(char *payload, const char *topicName) {

	MQTTClient_message msg = MQTTClient_message_initializer;
	msg.payload = payload;
	msg.payloadlen = strlen(payload);
	msg.qos = 1;
	msg.retained = 0;
	MQTTClient_deliveryToken dt;
	rc = MQTTClient_publishMessage(client, topicName, &msg, &dt);
	printf("Publication of %s\n on topic %s\n\n", payload, topicName);

}

void MQTT::subscribe(const char *topic) {
	int qos = 1;
	rc = MQTTClient_subscribe(client, topic, qos);
	printf("Subscribed to %s\n\n", topic);

}

void MQTT::unsubscrube(const char *topic) {

	rc = MQTTClient_unsubscribe(client, topic);

}

void MQTT::disconnect() {

	int timeout = 100;
	MQTTClient_disconnect(client, timeout);

}


int MQTT::messageArrived(void *context, char *topicName, int topicLen, MQTTClient_message *message){

	printf("Message arrived\n");
	printf("Topic: %s\n", topicName);
	printf("Message: %.*s\n\n", message->payloadlen, (char *)message->payload);

	MQTTClient_freeMessage(&message);
	MQTTClient_free(topicName);
	return 1;

}

MQTT::~MQTT() {
	// TODO Auto-generated destructor stub

}
