#include "controller.hxx"
#include <iostream>


Controller::Controller(ge211::Posn<int> pos_1, ge211::Posn<int> pos_2)
        : view_(model_),
        pos1(pos_1),
        pos2(pos_2)
{ }


/*
Controller::Controller(int size)
        : Controller(size, size)
{ }

Controller::Controller(
        int width,
        int height)
        : model_(width, height),
          view_(model_)

{ }

*/

/*
void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
} */

void
Controller::draw(ge211::Sprite_set& sprites)
{
    view_.draw(sprites);
}


//ge211::Dims<int>
View::Dimensions
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

std::string
Controller::initial_window_title() const
{
    return view_.initial_window_title();
}


//check if ship is hit
//:play_attack(std::vector<Ship> player, Model::Position p)


//Position_set::Position_set(std::initializer_list<value_type> elems)
//         : Position_set(elems.begin(), elems.end())
// { }
void
Controller::on_mouse_up(ge211::Mouse_button, ge211::Posn<int> position)
{
    if (model_.is_opening_phase()) {
        Ship s;
        if (model_.player_.size() < 5) {

            if (model_.v_vec.empty()) {
                pos1 = view_.screen_to_board(position);
                //model_.v_vec().push_back(pos1);
                model_.v_vec.push_back(pos1);

                return;
            } else {
                pos2 = view_.screen_to_board(position);
                if (pos1.x == pos2.x) {
                    while (pos2.y != pos1.y) {
                        if (pos2.y > pos1.y) {
                            pos1.y++;
                            model_.v_vec.push_back({pos1.x, pos1.y});
                        }
                        if (pos2.y < pos1.y) {
                            pos2.y++;
                            model_.v_vec.push_back({pos1.x, pos2.y});
                        }

                    }
                    model_.get_pset(model_.v_vec);

                } else if (pos1.y == pos2.y) {
                    while (pos2.x != pos1.x) {
                        if (pos2.x > pos1.x) {
                            pos1.x++;
                            model_.v_vec.push_back({pos1.x, pos1.y});
                        }
                        if (pos2.x < pos1.x) {
                            pos2.x++;
                            model_.v_vec.push_back({pos2.x, pos1.y});
                        }
                        //model_.v_vec.push_back({pos1.x+i, pos1.y});

                    }
                    model_.get_pset(model_.v_vec);


                }
                //model_.v_vec.push_back(pos2);
            //model_.turn().push_back(s);

            }

            s.pset_ = model_.p_test();
            model_.player_.push_back(s);
            //std::cout << model_.p1_.size();
            //std::cout << model_.p2_.size();
            model_.v_vec.clear();



        }
        /*
        else{
            std::cout << model_.p1_.size();
            model_.advance_turn_();
            std::cout << model_.p2_.size();

        }
*/
        //std::cout << model_.turn_.size();
        //std::cout << model_.p1_.size();
        //std::cout << model_.p2_.size();
        //model_.advance_turn_();
        //model_.other_player(model_.turn_);
        //std::cout << model_.other_player(model_.turn_).size();


        //std::cout << model_.player_.size();

    }
    //pos 1 = __
    //if pos 1 != null
    //pos 2 = __
    //call function to make pset
    //clear

    if(model_.play_at_pos(view_.screen_to_board(position)) && !model_.is_opening_phase()){
        std::cout << "attack";
        model_.play_attack(view_.screen_to_board(position));
    }

}


void
Controller::on_mouse_move(ge211::Posn<int> position)
{
    //TODO

}

//advance to next player/screen using space bar
void
Controller::on_key(ge211::Key key)
{

    if (key == ge211::Key::code(' ')) {
        // switch to other player
        model_.advance_turn_();
    }



}



