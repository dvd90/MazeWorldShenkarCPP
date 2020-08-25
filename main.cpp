#include <iostream>
#include "Controller.h"

int main()
{
    std::shared_ptr<Controller> game(new Controller());
    game->Play();

    return 0;
}
