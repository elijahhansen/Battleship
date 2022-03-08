#pragma once

#include <ge211.hxx>
#include <vector>
#include "position_set.hxx"


class Ship
{
public:
    using Dimensions = ge211::Dims<int>;
    using Position = ge211::Posn<int>;



    bool hit_ship(Position) ;

    Position_set pset_;
    bool alive_ = true;





};


