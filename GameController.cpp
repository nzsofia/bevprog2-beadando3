#include "GameController.hpp"

GameController::GameController()
{

}
void GameController::eventloop()
{
    event ev;
    while(gin >> ev)
    {
        for (int i=0; i<widgetek.size(); i++)
        {
            widgetek[i]->eventHandler(ev);
            widgetek[i]->draw();
        }
        gout<<refresh;
    }

}
