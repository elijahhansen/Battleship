#pragma once

#include <ge211.hxx>
#include "ship.hxx"
#include <vector>



class Model
{

public:

    using Dimensions = Ship::Dimensions;
    using Position = Ship::Position;

    Model();


    bool is_game_over() const;
    //int other_player();

    //std::vector<Ship> turn() const
    //{ return turn_; }


    std::vector<Ship> p1() const
    { return p1_; }

    std::vector<Ship> p2() const
    { return p2_; }

    std::vector<Position> hits_1() const
    { return hits_1_; }

    std::vector<Position> hits_2() const
    { return hits_2_; }

    std::vector<Position> miss_1() const
    { return miss_1_; }

    std::vector<Position> miss_2() const
    { return miss_2_; }

    std::vector<Position> v_vec;

    Position_set p_test() const
    { return pset_test;}

    bool get_turn()
    {return turn_;}

    //double seconds() const;

    bool play_at_pos(Position);

    // Takes in a Player and Position in which to attack and if
    // the posn is a hit it will remove the position from the ship's pset
    // and add that position to a hit_array
    //void play_attack (std::vector<Ship>, Position);
    void play_attack (Position);

    bool advance_turn_();

    std::vector<Ship> other_player(bool turn);

    std::vector<Position> other_hits(bool hit);

    std::vector<Position> other_misses(bool miss);

    void set_game_over();
    void get_pset(std::vector<Position> vec);

    bool is_opening_phase() const;

    std::vector<Ship> p1_;
    std::vector<Ship> p2_;
    bool winner_;

    //std::vector<Ship>& turn_ = p1_;

    /*
     * options for keeping track of turn
     * using turn as a boolean indicator of whose turn it is
     * using turn as a reference to p1 or p2
     * using a player class
      */
    bool turn_;
    //std::vector<Ship> & player_;
private:
    //std::vector<Ship> p1_;
    //std::vector<Ship> p2_;
    std::vector<Position> hits_1_;
    std::vector<Position> hits_2_;
    std::vector<Position> miss_1_;
    std::vector<Position> miss_2_;
    std::vector<Position> & turn_miss_ = miss_1_;
    std::vector<Position> & turn_hits_ = hits_1_;

    std::vector<Position> v;
    Position_set pset_test;
    //Player turn_player  = Player::p1;

};


