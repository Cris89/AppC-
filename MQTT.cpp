/*
 * MQTT.cpp
 *
 *  Created on: Oct 24, 2016
 *      Author: cris
 */
#include "MQTT.h"

#include "MQTTClient.h"

#include <cstring>

#define ADDRESS "tcp://localhost:1883"
#define CLIENTID "AppC++"

MQTT::MQTT() {

	rc = MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);

}

void MQTT::connect() {

	MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
	conn_opts.keepAliveInterval = 10;
	conn_opts.cleansession = 1;
	rc = MQTTClient_connect(client, &conn_opts);

}

void MQTT::publish(char *payload, const char *topicName){

	int payloadlen = strlen(payload);
	int qos = 1;
	int retained = 0;
	MQTTClient_deliveryToken dt;
	rc = MQTTClient_publish(client, topicName, payloadlen, payload, qos, retained, &dt);

}

void MQTT::subscribe(const char *topic){

	int qos = 2;
	rc = MQTTClient_subscribe(client, topic, qos);

}

void MQTT::unsubscrube(const char *topic){

	rc = MQTTClient_unsubscribe(client, topic);

}

void MQTT::disconnect(){

	int timeout = 100;
	MQTTClient_disconnect(client, timeout);

}

int MQTT::messageArrived(void *context, const char *topicName, int topicLen, MQTTClient_message *message){

	printf("Message arrived\n");
	    printf("topic: %s\n", topicName);
	    printf("message: .*s\n", message->payloadlen, message->payload);

	    MQTTClient_freeMessage(&message);
	    MQTTClient_free((void *)topicName);
	    return 1;

}

MQTT::~MQTT() {
	// TODO Auto-generated destructor stub
}
