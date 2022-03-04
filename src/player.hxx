#pragma once

#include "ship.hxx"

class Player
{

public:

    using Position = Ship::Position;

    // Takes in a Player and Position in which to attack and if
    // the posn is a hit it will remove the position from the ship's pset
    void hit_ship(Player, Position) const;


private:

    std::vector<Ship> ship_array_;



};


