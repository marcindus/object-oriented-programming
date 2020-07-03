#pragma once

#include <iostream>
#include <list>
#include <string>
#include "IObserver.hpp"
#include "ISubject.hpp"
#include "Subject.hpp"

class Observer : public IObserver
{
public:
    Observer(Subject& subject) : subject_(subject)
    {
        this->subject_.Attach(this);
    }
    virtual ~Observer() { }

    void RemoveMeFromTheList()
    {
        subject_.Detach(this);
    }

private:
    Subject& subject_;
};




