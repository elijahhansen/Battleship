#include "controller.hxx"


Controller::Controller()
        : view_(model_)
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
void
Controller::on_mouse_up(ge211::Mouse_button, ge211::Posn<int> position)
{
    //TODO

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
    }


}