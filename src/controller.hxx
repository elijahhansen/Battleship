#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller();


    /*
        explicit Controller(int size = 8);

        Controller(
                int width,
                int height); */


protected:
    void on_key(ge211::Key) override;

    void on_mouse_up (
            ge211 :: Mouse_button ,
            ge211 :: Posn <int >) override;

    void  on_mouse_move (
            ge211 :: Posn <int >) override;

    //ge211::Dims<int> initial_window_dimensions() const override;
    View::Dimensions initial_window_dimensions() const override;
    std::string initial_window_title() const override;


    //void draw(ge211::Sprite_set& set) override;
    void draw(ge211::Sprite_set&) override;


private:
    Model model_;
    View view_;
};
