#pragma once

#include <iostream>
#include <vector>
using namespace std;
using string = std::string;

class Tank
{ private:
    bool animation_status = true;

public:
    int id;
    int defence_points;
    int attack_points;
    string color = "red";
    Tank() : animation_status(true), id(0), color("red"), defence_points(0), attack_points(0) {}
    Tank(bool a_status, const int& number, string colorname, const int& att, const int& def) : animation_status(a_status), id(number), color(colorname), defence_points(def), attack_points(att) {}

    void fight(Tank * enemy);
    void show();
    void animation();
    ~Tank() {
        //...
    }
};