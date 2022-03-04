#include "model.hxx"

Model::Model(int size)
    :Model(size, size)

{ }

bool
Model::is_game_over() const
{
    return false;
}

bool
Model::advance_turn_() const
{
    return false;
}






