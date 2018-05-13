#ifndef PUSHBUTTON_HPP
#define PUSHBUTTON_HPP
#include "widget.hpp"
#include <string>
#include <functional>

class MainButton: public Widget
{
protected:
    std::string felirat;
    bool aktiv; //kattintásra történhet-e valami vagy sem
    std::function <void()> fv;
public:
    MainButton(int _x, int _y, int _meretx, int _merety, std::string _felirat, std::function <void()> _fv,bool _aktiv);
    virtual void draw() const;
    virtual void eventHandler(const genv::event &ev);
    void action();
    void set_felirat(std::string mod_felirat);
    void set_aktiv(bool aktiv_val);
    std::string get_value() const;
};
#endif // PUSHBUTTON_HPP
