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

bool
Ship::is_ship_sunk(Ship s)
{
    if(s.pset_.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool
operator==(Ship a, Ship b)
{
    if (a.alive_ == b.alive_ && a.pset_ == b.pset_) {
        return true;
    }
    else
    {
        return false;
    }

}

