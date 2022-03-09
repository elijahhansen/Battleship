#include "view.hxx"

using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;


static int const grid_size = 36;


static ge211::Color const board_color {0,128,0};
static ge211::Color const white_color {255,255,255};
static ge211::Color const black_color {0,0,0};
static ge211::Color const red_color {128,0,0};
static ge211::Color const gray_color {128,128,128};

//aircraft carrier (1x5) , battleship (1x4) cruiser (1x3), submarine (1x3), and destroyer (1x2)

View::View(Model const& model)
        : model_(model),
          aircraft_carrier({grid_size-5, grid_size-5}, gray_color),
        //battleship(),
        //cruiser(),
        //submarine(),
        //destroyer(),
          hit_sprite((grid_size)/2 -3, red_color),
          miss_sprite((grid_size)/2 -3, white_color),
          grid_sprite({grid_size-5, grid_size-5}, board_color),
        //back_drop({grid_size*7, grid_size*7}, black_color),
          temporary({grid_size*15, grid_size*10}, black_color),
          destroy_text()

{ }

//how to add the constant ship sprites?
//should certain ships be designated as vertical/horizontal already?


void
View::draw(ge211::Sprite_set& set)
{
    // It will really iterate over the 2D array
    for (int i = 0; i< 7; i++) {
        for (int j = 0; j < 7; j++) {
            //set.add_sprite(back_drop,{0,0}, 0);
            //set.add_sprite(back_drop,{grid_size * 8,0}, 0);
            set.add_sprite(grid_sprite, board_to_screen({i, j}), 5);
            set.add_sprite(grid_sprite, board_to_screen({i + 8, j}), 5);

        }

    }
    //if player 1 turn
    //show their ships

    //if player 2 turn
    //show their ships

    //if(model_[{i,j}] == Player::dark){

    //}
    //add sprite hit
    for(Position p : model_.hits_1()){
        set.add_sprite(hit_sprite, board_to_screen(p), 10);
    }

    for(Position p : model_.hits_2()){
        set.add_sprite(hit_sprite, board_to_screen(p), 10);
    }

    for(Position p : model_.miss_1()){
        set.add_sprite(miss_sprite, board_to_screen(p), 10);
    }

    for(Position p : model_.miss_2()){
        set.add_sprite(miss_sprite, board_to_screen(p), 10);
    }


    //if full ship revealed
    //add sprite ship- where to add? and text sprite
    //change a and b so it corresponds to where each ship is
    //should we have already set ship sprites or iterate?
    //could also write a helper function for add ship
    for (int a = 0; a< 5; a++) {
        for (int b = 0; b <1 ; b++) {
            set.add_sprite(aircraft_carrier,board_to_screen({a, b}),
                           10);
        }
    }
    ge211::Text_sprite::Builder text_builder(sans72);
    //replace with current player and ships
    text_builder << "Player 1 has sunk player 2's aircraft";
    destroy_text.reconfigure(text_builder);
    set.add_sprite(destroy_text, {110,280}, 20);


    //if turn is neither?, show temporary screen
    //set.add_sprite(temporary,{0,0}, 15);
    //set.add_sprite(turn_sprite,{80,100}, 20);


    if(model_.is_game_over()){
        if(model_.winner() == model_.p1()){
            set.add_sprite(p1_winner,{160,280}, 20);
        }
        if(model_.winner() == model_.p2()){
            set.add_sprite(p2_winner,{160,280}, 20);
        }
    }


}

//ge211::Dims<int>
View::Dimensions
View::initial_window_dimensions() const
{
    return {grid_size * 15, grid_size * 10};

}

std::string
View::initial_window_title() const
{
    // You can change this if you want:
    return "Battleship";
}


View::Position
View::board_to_screen(Model::Position logical) const
{
    return View::Position(logical.x * grid_size, logical.y *grid_size);
}

Model::Position
View::screen_to_board(View::Position physical) const
{
    return Model::Position(physical.x / grid_size, physical.y / grid_size);
}
