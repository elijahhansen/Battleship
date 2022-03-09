#include "model.hxx"




using namespace ge211;


Model::Model(int size)
//    :Model(size, size)

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
    if(p1_.size() > p2_.size())
    {
        winner_ = p1_;
    }
    if(p1_.size() < p2_.size())
    {
        winner_ = p2_;
    }
}



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


std::vector<Posn<int>>
Model::other_hits(std::vector<Position> hit)
{
    if (hit == hits_1_)
    {
        return hits_2_;
    }
    if(hit == hits_2_)
    {
        return hits_1_;
    }
    else
    {
        return hit;
    }
}

std::vector<Posn<int>>
Model::other_misses(std::vector<Position> miss)
{
    if (miss == miss_1_)
    {
        return miss_2_;
    }
    if(miss == miss_2_)
    {
        return miss_1_;
    }
    else
    {
        return miss;
    }
}


bool
Model::advance_turn_()
{
    turn_ = other_player(turn_);
    turn_hits_ = other_hits(turn_hits_);
    turn_miss_ = other_misses(turn_miss_);

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
    for (Position p : other_misses(turn_miss_))
    {
        if (p == pos)
        {
            return false;
        }
    }
    return true;
}


void
//Model::play_attack(/*std::vector<Ship> player,*/ Model::Position p)
Model::play_attack(Model::Position p)
{

    for (Ship s : turn_)
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















