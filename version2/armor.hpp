#ifndef ARMOR_HPP
#define ARMOR_HPP
#include "item.hpp"

class Armor: public Item{
    protected:
        int a_bonus;
        bool a_equiped, a_owned;
    public:
        Armor();
        Armor(string name);

        void setBonus(int bonus){a_bonus = bonus;};
        void setEquiped(bool equiped){a_equiped = equiped;};
        void setOwned(bool owned){a_owned = owned;};

        bool getEquiped(){return a_equiped;};
        bool getOwned(){return a_owned;};
        int getBonus(){return a_bonus;};
        
        ~Armor(){};
};


#endif //ARMOR_HPP