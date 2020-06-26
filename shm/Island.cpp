#include "Island.hpp"
#include "Coordinates.hpp"

std::ostream& operator<<(std::ostream& os, Island& island)
{
    os << "Island: position " << island.getPosition();
    return os;
}

bool operator==(Island& lhs, Island& rhs)
{
    return lhs.getPosition() == rhs.getPosition();
}



