#pragma once

#include <ostream>

#include "Coordinates.hpp"

class Island
{
public:
    Island() : position_(Coordinates(0, 0)) {}
    Island(int x, int y) : position_(Coordinates(x, y)) {}

    Coordinates getPosition() { return position_; }

private:
    Coordinates position_;
};

std::ostream& operator<<(std::ostream& os, Island& island);
bool operator==(Island& lhs, Island& rhs);


