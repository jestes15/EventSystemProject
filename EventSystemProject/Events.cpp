#include "Events.h"

void
Event::raise(std::any sender = nullptr, std::any args = nullptr) {

}

void
Event::raiseSync(std::any sender = nullptr, std::any args = nullptr) {
	for (int i = 0; i < subscribers.size(); i++) {
		subscribers[i](sender, args);
	}
}

void
Event::operator+=(const eveSub& subscriber) {
	subscribers.push_back(subscriber);
}

bool
Event::operator-=(const eveSub& subscriber) {
	int location = 0;
	for (int i = 0; i < subscribers.size(); i++) {
		if (subscribers[i] == subscriber)
			location = i;
	}
	subscribers.erase(subscribers.begin() + location);
}