#pragma once

#include <iostream>
#include <vector>
using namespace std;
using string = std::string;

class Tank
{ 
    friend class PR;
    friend class TO;
    friend class SW;
    friend class BWP;
    friend class CZ;
    friend class SZP;
    friend class DS;
    friend class SA;

protected:
    bool animation_status = true;
    int id;
    int tactic_level;
    string color;
    string tank_type;
    int tank_speed;
    int tank_weight;



public:
    int defence_points;
    int attack_points;
    
    Tank() : animation_status(true), id(0), color(""), defence_points(0), attack_points(0), tank_type(""), tactic_level(0), tank_speed(0), tank_weight(0) {}
    Tank(bool a_status, const int& number, string colorname, const int& att, const int& def) : animation_status(a_status), id(number), color(colorname), defence_points(def), attack_points(att) {}
    Tank(bool a_status, const int& number,  const int& att, const int& def) : animation_status(a_status), id(number),  defence_points(def), attack_points(att) {}

    void fight(Tank * enemy);
    void show();
    void animation();
    int zwroc() {
        return this->tactic_level;
    };
    int zwroc_id() {
        return this->id;
    };
    string zwroc_typ() {
        return this->tank_type;
    };
    void color_change(string color2) {
        this->color = color2;
    }
    ~Tank() {
        //...
    }
 
};
class PR : public Tank {
public:
    
    string Tank_type = "Pojazd Rozpoznawczy";
    PR(bool a_status, const int& number, const int& att, const int& def) :Tank(a_status, number, def, att) {
        this->tank_type = Tank_type;
        this->tactic_level = 1;
        this->tank_speed = rand() % 50 + 100;
        this->tank_weight = rand() % 30 + 15;

    }
    ~PR() {
        //...
    }
    friend void order(Tank* me, Tank* enemy);
};
class TO : public Tank {
public:
    string Tank_type = "Transporter Opancerzony";
    TO(bool a_status, const int& number,  const int& att, const int& def) :Tank(a_status, number,  def, att) {
        this->tank_type = Tank_type;
        this->tactic_level = 1;
        this->tank_speed = rand() % 50 + 10;
        this->tank_weight = rand() % 50 + 110;
    }
    ~TO() {
        //...
    }
    friend void order(Tank* me,Tank* enemy);
};
class SW : public Tank {
public:
    string Tank_type = "Samochod wojskowy";
    SW(bool a_status, const int& number, const int& att, const int& def) :Tank(a_status, number, def, att) {
        this->tank_type = Tank_type;
        this->tactic_level = 1;
        this->tank_speed = rand() % 50 + 90;
        this->tank_weight = rand() % 50 + 30;
    }
    ~SW() {
        //...
    }
    friend void order(Tank* me, Tank* enemy);
};
class BWP : public Tank {
public:
    string Tank_type = "Bojowe wozy piechoty";
    BWP(bool a_status, const int& number, const int& att, const int& def) :Tank(a_status, number, def, att) {
        this->tank_type = Tank_type;
        this->tactic_level = 0;
        this->tank_speed = rand() % 50 + 30;
        this->tank_weight = rand() % 50 + 40;
    }
    ~BWP() {
        //...
    }
};
class CZ : public Tank {
public:
    string Tank_type = "Czolgi";
    CZ(bool a_status, const int& number, const int& att, const int& def) :Tank(a_status, number, def, att) {
        this->tank_type = Tank_type;
        this->tactic_level = 0;
        this->tank_speed = rand() % 30 + 30;
        this->tank_weight = rand() % 20 + 140;
    }
    ~CZ() {
        //...
    }
};
class SZP : public Tank {
public:
    string Tank_type = "Samobiezne zestawy przeciwlotnicze";
    SZP(bool a_status, const int& number, const int& att, const int& def) :Tank(a_status, number, def, att) {
        this->tank_type = Tank_type;
        this->tactic_level = 0;
        this->tank_speed = rand() % 3 + 5;
        this->tank_weight = rand() % 200 + 250;
    }
    ~SZP() {
        //...
    }
};
class DS : public Tank {
public:
    string Tank_type = "Dziala samobiezne";
    DS(bool a_status, const int& number, const int& att, const int& def) :Tank(a_status, number, def, att) {
        this->tank_type = Tank_type;
        this->tactic_level = 0;
        this->tank_speed = rand() % 13 + 5;
        this->tank_weight = rand() % 10 + 250;
    }
    ~DS() {
        //...
    }
};
class SA : public Tank {
public:
    string Tank_type = "Samoloty";
    SA(bool a_status, const int& number, const int& att, const int& def) :Tank(a_status, number, def, att) {
        this->tank_type = Tank_type;
        this->tactic_level = 0;
        this->tank_speed = rand() % 5000 + 5000;
        this->tank_weight = rand() % 1000 + 2500;
    }
    ~SA() {
        //...
    }
};