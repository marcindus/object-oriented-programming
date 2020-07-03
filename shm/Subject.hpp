#pragma once

class Subject : public ISubject
{
public:
    virtual ~Subject() {}

    void Attach(IObserver* observer) override { list_observer_.push_back(observer); }
    void Detach(IObserver* observer) override { list_observer_.remove(observer); }
    void Notify() override
    {
        std::list<IObserver*>::iterator iterator = list_observer_.begin();
        while (iterator != list_observer_.end())
        {
            (*iterator)->Update(message_);
            ++iterator;
        }
    }

    void CreateMessage(std::string message = "Empty")
    {
        this->message_ = message;
        Notify();
    }

    void SomeBusinessLogic()
    {
        this->message_ = "change message message";
        Notify();
        std::cout << "I'm about to do some thing important\n";
    }

private:
    std::list<IObserver*> list_observer_;
    std::string message_;
};


