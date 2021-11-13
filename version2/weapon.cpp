#include "weapon.hpp"

Weapon::Weapon(string name){
    if(name == "Short Bow"){
        i_name = name;
        i_amount = 1;
        i_price = 2500;
        w_melee = false;
        w_equiped = w_owned = w_ranged = true;
        w_bonus = 1;
        w_sentence = "Shoot an arrow at it with your Short Bow";
    }
    else if(name == "Iron Dagger"){
        i_amount = 1;
        i_name = name;
        i_price = 200;
        w_equiped = w_owned = w_melee = true;
        w_ranged = false;
        w_bonus = 0;
        w_sentence = "Stab it with your Iron Dagger";
    }
    else if(name == "Long Bow"){
        i_name = name;
        i_amount = 1;
        i_price = 5000;
        w_equiped = w_owned = w_melee = false;
        w_ranged = true;
        w_bonus = 2;
        w_sentence = "Shoot an arrow at it with your Long Bow";
    }
    else if(name == "Short Sword"){
        i_name = name;
        i_amount = 1;
        i_price = 1000;
        w_equiped = w_ranged = false;
        w_owned = w_melee = true;
        w_bonus = 2;
        w_sentence = "Cut it with your Short Sword";
    }
    else if(name == "Spear"){
        i_name = name;
        i_amount = 1;
        i_price = 1000;
        w_ranged = w_equiped = w_owned = false;
        w_melee = true;
        w_bonus = 2;
        w_sentence = "Pierce it with your Spear";
    }
    else if(name == "Battle Hammer"){
        i_name = name;
        i_amount = 1;
        i_price = 3000;
        w_ranged = w_equiped = w_owned = false;
        w_melee = true;
        w_bonus = 3;
        w_sentence = "Smash it with your Battle Hammer";
    }
    else if(name == "Scythe"){
        i_name = name;
        i_amount = 1;
        i_price = 5000;   
        w_ranged = w_equiped = w_owned = false;
        w_melee = true;
        w_bonus = 5;     
        w_sentence = "Slice it with your Scythe";
    }
    else if(name == "null"){
        i_name = "";
        i_amount = 0;
        i_price = 0;
        w_bonus = 0;
        w_equiped = w_ranged = w_melee = false;
        w_owned = false;
        w_sentence = "";
    }
}