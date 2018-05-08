#ifndef WINDOW_HPP
#define WINDOW_HPP
#include "widget.hpp"
#include "graphics.hpp"
#include <vector>
class Window{
protected:
    std::vector<Widget*> widgetek;
public:
    void eventloop();
    virtual ~Window();
};
#endif // WINDOW_HPP
