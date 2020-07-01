#pragma once 

class IObserver
{

public:
    virtual ~IObserver(){};
    virtual void Update(const std::string& message_from_subject) = 0;
};
