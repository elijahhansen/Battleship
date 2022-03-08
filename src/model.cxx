#include "model.hxx"
#include "player.hxx"
#include <vector>



using namespace ge211;


Model::Model(int size)
// :Model(size, size)

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
    return false;
}



std::vector<Ship>
Model::other_player(std::vector<Ship> player)
{
    if (player == p1){
        return p2;
    }
    if (player == p2){
        return p1;
    }
    else{
        return player;
    }


}

void
Model::play_attack(std::vector<Ship> player, Model::Position p)
{
    for (Ship s : player)
    {
        if (s.hit_ship(p))
        {
            s.pset_[p] = false;
            //add position p to player's hit array
        }
    }
}

void
Model::advance_turn_()
{
    turn = other_player(turn);
}







