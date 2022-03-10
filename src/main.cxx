#include "controller.hxx"

int
main()
{
    Controller(ge211::Posn<int>(0,0), ge211::Posn<int>(0,0)).run();

    return 0;
}
