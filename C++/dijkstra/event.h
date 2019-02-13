#ifndef EVENT_H
#define EVENT_H

// documentation for type Event

struct Event
{
	int sender;
	int receiver;
	double time;

	Event(int _sender, int _receiver, double _time)
	{
		sender = _sender;
		receiver = _receiver;
		time = _time;
	}
};

#endif

