#ifndef PHYSICAL_LAYER_H
#define PHYSICAL_LAYER_H

#include "protocol.h"

#include "event_queue.h"

#include <queue>

using namespace std;

class Physical_Layer
{
public:
	/*
			sends data to the other side
		*/
	static void to_physical_layer(frame *f, int delay);

	/*
			returns the head of the received frames queue and pops the queue
		*/
	static void from_physical_layer(frame *r);

	/*
			either creates or connects to a local tcp socket given its port 
			and contains a while loop in which it listens to data from the other side
			it pushes the data received in the recevied frames queue
		*/
	static void create_physical(bool isServer, int port);

private:
	/*
		queue containing received frames
	*/
	static queue<frame> received_frames;
};

#endif