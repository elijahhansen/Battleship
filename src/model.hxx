#pragma once

#include <ge211.hxx>
#include "ship.hxx"
#include "player.hxx"


class Model
{

public:

    using Dimensions = Ship::Dimensions;
    using Position = Ship::Position;

    explicit Model( int size = 8);

    Model(int width, int height);



    // Takes in a Player and Position in which to attack and if
    // the posn is a hit it will remove the position from the ship's pset
    // and add that position to a hit_array
    void remove_pos() const;

    std::vector<Ship> other_player(std::vector<Ship>);

    void play_attack (std::vector<Ship>, Position);

private:
    Position position_;
    Player player_;
    Ship s_;

};



