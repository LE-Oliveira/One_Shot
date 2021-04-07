#include "armor.hpp"

Armor::Armor(string name){
    if(name == "Padded Leather"){
        i_name = name;
        i_price = 100;
        a_bonus = 1;
        a_equiped = false;
        a_owned = false;
    }
    else if(name == "Ring Mail"){
        i_name = name;
        i_price = 600;
        a_bonus = 2;
        a_equiped = false;
        a_owned = false;
    }
    else if(name == "Half Plate"){
        i_name = name;
        i_price = 4000;
        a_bonus = 3;
        a_equiped = false;
        a_owned = false;
    }
    else if(name == "Chain Mail"){
        i_name = name;
        i_price = 6000;
        a_bonus = 4;
        a_equiped = false;
        a_owned = false;
    }
    else if(name == "Spiked Armor"){
        i_name = name;
        i_price = 3500;
        a_bonus = 2;
        a_equiped = false;
        a_owned = false;
    }
}