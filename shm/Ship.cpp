#include "Ship.hpp"

Ship::Ship(Subject& subject) : id_(-1), Observer(subject)  {}
Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id, Subject& subject)
        : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id), Observer(subject) 
    {
    }
Ship::Ship(int maxCrew, int speed, size_t id, Subject& subject) : Ship(0, maxCrew, speed, "", id, subject)   {}

void Ship::setName(const std::string& name)
{
    name_ = name;
}

Ship& Ship::operator-=(size_t num)
{
    if (crew_ >= num)
        crew_ -= num;
    return *this;
}

Ship& Ship::operator+=(size_t num)
{
    crew_ += num;
    return *this;
}
