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

    //Model(int width, int height);

    bool is_game_over() const;
    //int other_player();

    // Takes in a Player and Position in which to attack and if
    // the posn is a hit it will remove the position from the ship's pset
    // and add that position to a hit_array
    void play_attack (std::vector<Ship>, Position);

    bool advance_turn_();

    std::vector<Ship> other_player(std::vector<Ship> player);

    std::vector<Position> other_hits(std::vector<Position> hit);

    void set_game_over();

private:
    std::vector<Ship> p1_;
    std::vector<Ship> p2_;
    std::vector<Ship> turn_ = p1_;
    std::vector<Position> hits_1_;
    std::vector<Position> hits_2_;
    std::vector<Position> turn_hits_ = hits_1_;
    std::vector<Ship> winner_;

};


