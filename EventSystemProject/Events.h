#pragma once
#include <any>
#include <vector>
#include <thread>

#ifndef EVENTS
#define EVENTS

//Event Subscriber, a function pointer to a function with two arguments, sender and args
typedef void (*eveSub)(std::any, std::any);

//Actual Event
struct Event {

    //Call all subs simaltaneously(launches many threads)
    bool simultaneousLaunch = false;

    //Functions to call when the event occurs
    std::vector<eveSub> subscribers;

    //Calls subs,Sender and args may be of any type
    void raise(std::any sender = nullptr, std::any args = nullptr);

    //Calls subs synchronously on the thread that raised the event, ignoring simultaneousLaunch
    void raiseSync(std::any sender = nullptr, std::any args = nullptr);

    //Add a sub
    void operator+=(const eveSub& subscriber);

    //Remove a sub if possible
    bool operator-=(const eveSub& subscriber);
};
#endif // !EVENTS