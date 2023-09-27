#include "model.hxx"
#include <iostream>




using namespace ge211;


Model::Model()
    ://player_(p1_),
    turn_(true)


{
}
/*
Model::Model(int width, int height)
        : Model({width, height})
{

    return;
}
*/

//testing
//testing
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
        winner_ = true;
    }
    if(p2_.empty())
    {
        winner_ = false;
    }
}



std::vector<Ship>
Model::other_player(bool turn)
{
    if (turn){
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
    if (turn_){
        if (p2_.empty()){
            return false;
        }
        for (Position p : hits_1_)
        {
            if (p == pos)
            {
                return false;
            }
        }
        for (Position p : miss_1_)
        {
            if (p == pos)
            {
                return false;
            }
        }
        return true;

    }
    else{
        if (p1_.empty()){
            return false;
        }
        for (Position p : hits_2_)
        {
            if (p == pos)
            {
                return false;
            }
        }
        for (Position p : miss_2_)
        {
            if (p == pos)
            {
                return false;
            }
        }
        //return true;

    }
    return true;
}


bool
Model::is_opening_phase() const
{
    if ((p1_.size() <5 || p2_.size() <5) && hits_1_.empty() && hits_2_.empty
    () &&
    miss_1_.empty() &&
        miss_2_.empty())
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
    if (turn_) {
        for (Ship& s: p2_) {
            if (s.hit_ship(p)) {
                s.pset_[p] = false;
                //add position p to player's hit array
                hits_1_.push_back(p);
                std::cout << hits_1_.size() << "\n";
                if(s.is_ship_sunk())
                {
                    s.alive_ = false;
                }
                return;
            }
        }
        miss_1_.push_back(p);
        std::cout << miss_1_.size() << "\n";
        return;

        /*
        if (advance_turn_()) {
            return;
        }
        if (advance_turn_()) {
            return;
        }*/
        if (is_game_over()) {
            set_game_over();
        }
    }

    if(!turn_)
    {
        for (Ship & s: p1_)
        {
            if (s.hit_ship(p)) {
                s.pset_[p] = false;
                //add position p to player's hit array
                hits_2_.push_back(p);
                if (s.is_ship_sunk())
                {
                    s.alive_ = false;
                }
                return;
            }
        }

        miss_2_.push_back(p);
        if (is_game_over()){
            set_game_over();
        }


    }
}








void
Model::get_pset(std::vector<Position> vec)
{
    //v.push_back(p1);
    //v.push_back(p2);
    Position_set ship_pos_set(vec.begin(), vec.end());
    std::cout << ship_pos_set << "\n";
    return ship_pos_set;
    //v_vec.clear();

    //std::cout << pset_test << "\n";
    //return ship_pos_set;

}
/*
void
Model::start_game()
{
    player_ = p1_;
    turn_hits_ = hits_1_;
    turn_miss_ = miss_1_;
}
*/


















