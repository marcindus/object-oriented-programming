/**
 * Observer Design Pattern
 *
 * Intent: Lets you define a subscription mechanism to notify multiple objects
 * about any events that happen to the object they're observing.
 *
 * Note that there's a lot of different terms with similar meaning associated
 * with this pattern. Just remember that the Subject is also called the
 * Publisher and the Observer is often called the Subscriber and vice versa.
 * Also the verbs "observe", "listen" or "track" usually mean the same thing.
 */
#pragma once

#include <iostream>
#include <list>
#include <string>
#include "IObserver.hpp"
#include "ISubject.hpp"
#include "Subject.hpp"

/**
 * The Subject owns some important state and notifies observers when the state
 * changes.
 */

class Observer : public IObserver
{
public:
    Observer(Subject& subject) : subject_(subject)
    {
        this->subject_.Attach(this);
        std::cout << "Hi, I'm the Observer \""; // << ++Observer::static_number_ << "\".\n";
       // this->number_ = Observer::static_number_;
    }
    virtual ~Observer() { std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n"; }

    void Update(const std::string& message_from_subject) override
    {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }
    void RemoveMeFromTheList()
    {
        subject_.Detach(this);
        std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
    }
    void PrintInfo()
    {
        std::cout << "Observer \"" << this->number_ << "\": a new message is available --> "
                  << this->message_from_subject_ << "\n";
    }

private:
    std::string message_from_subject_;
    Subject& subject_;
 //   static int static_number_;
    int number_;
};

//int Observer::static_number_ = 0;



