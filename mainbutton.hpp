#ifndef PUSHBUTTON_HPP
#define PUSHBUTTON_HPP
#include "widget.hpp"
#include <string>

class MainButton: public Widget{
protected:
    std::string felirat;
    std::function <void()> fv;
public:
    MainButton(int _x, int _y, int _meretx, int _merety, std::string _felirat, std::function <void()> _fv);
    virtual void draw() const;
    virtual void eventHandler(const genv::event &ev);
    void action();
    std::string get_value() const;
};
#endif // PUSHBUTTON_HPP
