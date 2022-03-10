#include "model.hxx"
#include <iostream>




using namespace ge211;


Model::Model(int size)
    //:Model(size, size)


{ }
/*
Model::Model(int width, int height)
        : Model({width, height})
{

    return;
}
*/


bool
Model::is_game_over() const
{
    for (Ship s: p1_)
    {
        if (s.alive_)
        {
            return false;
        }
    }
    for (Ship s : p2_)
    {
        if (s.alive_)
        {
            return false;
        }
    }
    return true;
}


void
Model::set_game_over()
{
    if(p1_.empty())
    {
        winner_ = p2_;
    }
    if(p2_.empty())
    {
        winner_ = p1_;
    }
}


/*
std::vector<Ship>
Model::other_player(std::vector<Ship> player)
{
    if (player == p1_){
        return p2_;
    }
    if (player == p2_){
        return p1_;
    }
    else{
        return player;
    }

}
*/
std::vector<Ship>
Model::other_player(bool turn)
{
    if (turn_){
        return p2_;
    }
    else {
        return p1_;
    }

}


std::vector<Posn<int>>
Model::other_hits(bool hit)
{
    if (hit)
    {
        return hits_2_;
    }
    else
    {
        return hits_1_;
    }
}

std::vector<Posn<int>>
Model::other_misses(bool miss)
{
    if (miss)
    {
        return miss_2_;
    }
    else
    {
        return miss_1_;
    }
}


bool
Model::advance_turn_()
{
    std::cout << player_.size() << "\n";;
    std::cout << p1_.size() << "\n";
    player_ = other_player(turn_);
    std::cout << player_.size() << "\n";
    std::cout << other_player(turn_).size() << "\n";
    //std::cout << p2_.size() << "\n";
    turn_hits_ = other_hits(turn_);
    turn_miss_ = other_misses(turn_);

    if(turn_)
    {
        turn_ = false;
    }
    else
    {
        turn_ = true;
    }


    if (is_game_over())
    {
        return false;
    }
    else
    {
        return true;
    }

}

bool
Model::play_at_pos(Position pos)
{
    if (other_player(turn_).empty())
    {
        return false;
    }
    for (Position p : other_hits(turn_hits_))
    {
        if (p == pos)
        {
            return false;
        }
    }
    for (Position p : other_misses(turn_))
    {
        if (p == pos)
        {
            return false;
        }
    }
    return true;
}


bool
Model::is_opening_phase()
{
    if (player_.size() <5 && other_player(turn_).size() <5 && turn_hits_
            .empty() && other_hits(turn_).empty() && turn_miss_.empty() &&
        other_misses(turn_).empty())
    {
        return true;
    }
    else
    {
        return false;
    }

}


void
//Model::play_attack(/*std::vector<Ship> player,*/ Model::Position p)
Model::play_attack(Position p)
{

    for (Ship s : other_player(turn_))
    {
        if (s.hit_ship(p))
        {
            s.pset_[p] = false;
            //add position p to player's hit array
            turn_hits_.push_back(p);
        }
        else
        {
            turn_miss_.push_back(p);
        }
    }
    if(advance_turn_())
    {
        return;
    }
    if(advance_turn_())
    {
        return;
    }
    set_game_over();
}















