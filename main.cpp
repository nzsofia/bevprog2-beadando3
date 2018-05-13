#include "graphics.hpp"
#include <time.h>
#include "GameController.hpp"

using namespace genv;
using namespace std;

int main()
{
    gout.open(max_x,max_y);
    srand(time(0));

    GameController * jatek_mester= new GameController();
    jatek_mester->eventloop();
    return 0;
}
