#pragma once

#include "player.hxx"
#include <ge211.hxx>
#include<iostream>
#include<vector>

/// Represents the state of the board
class Board
{
public:

    using Dimensions = ge211::Dims<int>;

    using Position = ge211::Posn<int>;

    using Rectangle = ge211::Rect<int>;

    class reference;

private:

    Dimensions dims_;


public:

    explicit Board(Dimensions dims);

    /// Returns the same 'Dimensions' value passed to the constructor
    Dimensions dimensions() const;

    /// returns whether a position is in bounds
    bool good_position(Position) const;


    ///returns player stored at pos
    Player operator[](Position pos) const;
    reference operator[](Position pos) const;



};
