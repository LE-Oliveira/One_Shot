#include "weapon.hpp"

Weapon::Weapon(string name){
    if(name == "Short Bow"){
        i_name = name;
        i_amount = 1;
        i_price = 2500;
        w_melee = false;
        w_equiped = w_owned = w_ranged = true;
        w_bonus = 1;
    }
    else if(name == "Iron Dagger"){
        i_amount = 1;
        i_name = name;
        i_price = 200;
        w_equiped = w_owned = w_melee = true;
        w_ranged = false;
        w_bonus = 0;
    }
    else if(name == "Long Bow"){
        i_name = name;
        i_amount = 1;
        i_price = 5000;
        w_equiped = w_owned = w_melee = false;
        w_ranged = true;
        w_bonus = 2;
    }
    else if(name == "Short Sword"){
        i_name = name;
        i_amount = 1;
        i_price = 1000;
        w_equiped = w_ranged = false;
        w_owned = w_melee = true;
        w_bonus = 2;
    }
    else if(name == "Spear"){
        i_name = name;
        i_amount = 1;
        i_price = 1000;
        w_ranged = w_equiped = w_owned = false;
        w_melee = true;
        w_bonus = 2;
    }
    else if(name == "Battle Axe"){
        i_name = name;
        i_amount = 1;
        i_price = 3000;
        w_ranged = w_equiped = w_owned = false;
        w_melee = true;
        w_bonus = 3;
    }
    else if(name == "Scythe"){
        i_name = name;
        i_amount = 1;
        i_price = 5000;   
        w_ranged = w_equiped = w_owned = false;
        w_melee = true;
        w_bonus = 5;     
    }
}