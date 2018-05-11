#include "window.hpp"

using namespace genv;
void Window::eventloop()
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
Window::~Window()
{
    for (int i=widgetek.size()-1; i>-1; i--)
    {
        delete widgetek[i];
        widgetek[i]=NULL;
        widgetek.erase(widgetek.begin()+i);
    }
}
