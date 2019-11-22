#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include "protocol.h"

class event_queue
{
	public:		
	
		/* push an event into the events queue */
		static void add_event(event_type *event);
		
		/* check events queue, if not empty return the head event and pop the queue */
		static void wait_for_event(event_type *event);
		

	private:
	/*
		queue containing events
	*/
		static queue<event_type> events;
}

#endif