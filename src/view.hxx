#pragma once

#include "model.hxx"

class View
{
public:

    using Dimensions = ge211::Dims<int>;

    using Position = ge211::Posn<int>;

    explicit View(Model const& model);

    //ge211::Dims<int> initial_window_dimensions() const;
    Dimensions initial_window_dimensions() const;

    std::string initial_window_title() const;

    void draw(ge211::Sprite_set& set);


    //Dimensions initial_window_dimensions() const;

    //std::string initial_window_title() const;

    View :: Position
    board_to_screen (
            Model :: Position logical )
    const ;

    Model :: Position
    screen_to_board (
            View :: Position physical )
    const ;


private:
    Model const& model_;

    //add sprite?


    //sprites
    //aircraft carrier (1x5) , battleship (1x4) cruiser (1x3), submarine (1x3), and destroyer (1x2)


    ge211::Rectangle_sprite const aircraft_carrier;
    /*  ge211::Rectangle_sprite const battleship;
      ge211::Rectangle_sprite const cruiser;
      ge211::Rectangle_sprite const submarine;
      ge211::Rectangle_sprite const destroyer; */
    ge211::Circle_sprite const hit_sprite;
    ge211::Circle_sprite const miss_sprite;
    ge211::Rectangle_sprite const grid_sprite;
    //ge211::Rectangle_sprite const back_drop;
    ge211::Rectangle_sprite const temporary;


    ge211::Font sans72{"sans.ttf", 20};

    ge211::Text_sprite turn_sprite{"Click space bar to proceed to next player",
                                   sans72};
    ge211::Text_sprite p1_winner{"Player 1 is the winner!",
                                 sans72};
    ge211::Text_sprite p2_winner{"Player 2 is the winner!",
                                 sans72};
    ge211::Text_sprite destroy_text;


    //ge211::Text_sprite destroyed_text{"Click space bar to proceed to next "
    //                               "player",
    //                            sans72};

};
