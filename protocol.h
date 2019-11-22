#ifndef PROTOCOL_H
#define PROTOCOL_H

#define MAX_PKT 2 /* determines packet size in bytes */
typedef unsigned int seq_nr; /* sequence or ack numbers */
typedef struct {unsigned char data[MAX_PKT];} packet; /* packet definition */
typedef struct {packet p; int delay; bool successfuly_sent;} simulated_packet; /* packet definition */
typedef enum {data, ack, nak} frame_kind; /* frame kind definition */
typedef enum {frame_arrival, cksum_err, timeout, network_layer_ready, ack_timeout} event_type;
typedef struct {
frame_kind kind; /* what kind of frame is it? */
seq_nr seq; /* sequence number */
seq_nr ack; /* acknowledgement number */
packet info; /* the network layer packet */
} frame;


/* Go get an inbound frame from the physical layer and copy it to r. */
void from_physical layer(frame *r);
/* Pass the frame to the physical layer for transmission. */
void to physical layer(frame *s);
/* Start the clock running and enable the timeout event. */
void start timer(seq nr k);
/* Stop the clock and disable the timeout event. */
void stop timer(seq nr k);
/* Start an auxiliary timer and enable the ack timeout event. */
void start ack timer(void);
/* Stop the auxiliary timer and disable the ack timeout event. */
void stop ack timer(void);

/* Macro inc is expanded in-line: increment k circularly. */
#define inc(k) if (k < MAX SEQ) k = k + 1; else k = 0

#endif