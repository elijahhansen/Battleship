#pragma once

#include <ge211.hxx>
#include "ship.hxx"
#include"player.hxx"


class Model
{

public:

    using Dimensions = Ship::Dimensions;
    using Position = Ship::Position;

    explicit Model( int size = 8);

    Model(int width, int height);

    bool is_game_over() const;


};
