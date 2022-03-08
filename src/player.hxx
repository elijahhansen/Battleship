#pragma once

#include "ship.hxx"

class Player
{

public:

    using Position = Ship::Position;

    bool hit_ship(Position, Player) const;




    std::vector<Ship> ship_array_;




};


