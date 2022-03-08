#include "ship.hxx"


bool
Ship::hit_ship(Position p)
{
    for (Position itr: pset_)
    {
        if (pset_.size() == 0)
        {
            alive_ = false;
        }
        if (p == itr)
        {
            return true;
        }

    }
    return false;
}

