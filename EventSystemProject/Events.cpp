#include "Events.h"

void
Event::raise(std::any sender = nullptr, std::any args = nullptr) {
	std::thread th([](std::vector<eveSub>& subscribers, std::any sender, std::any args){
		for (int i = 0; i < subscribers.size(); i++) {
			subscribers[i](sender, args);
		}});
}

void
Event::raiseSync(std::any sender = nullptr, std::any args = nullptr) {
	for (int i = 0; i < subscribers.size(); i++) {
		subscribers[i](sender, args);
	}
}

void
Event::operator+=(const eveSub& subscriber) {
	if (std::find(subscribers.begin(), subscribers.end(), subscriber) != subscribers.end()) return;
	subscribers.push_back(subscriber);
}

bool
Event::operator-=(const eveSub& subscriber) {
	auto it = std::find(subscribers.begin(), subscribers.end(), subscriber);
	if (it != subscribers.end()) {
		int index = it - subscribers.begin();
		subscribers.erase(subscribers.begin() + index);
		return true;
	}
	return false;
}