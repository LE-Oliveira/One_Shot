#ifndef ITEM_HPP
#define ITEM_HPP
#include "beast.hpp"

class Item{
    protected:
        string i_name;
        int i_price, i_amount;
    public:
        Item(){i_name = ""; i_price = 0; i_amount = 0;};
        Item(string name, int price, int amount){i_name = name; i_price = price; i_amount = amount;};

        void setName(string name){i_name = name;};
        void setPrice(int price){i_price = price;};
        void setAmount(int amount){i_amount = amount;};

        int getAmount(){return i_amount;};
        int getPrice(){return i_price;};
        string getName(){return i_name;};
        
        void operator+(int amount){i_amount+=amount;};

        ~Item(){};
};

class Loot: public Item{
    private:
        Beast* l_origin;
    public:
        Loot(){i_name = ""; i_price = 0; i_amount = 0; l_origin = nullptr;};
        Loot(string name, int price, int amount, Beast* origin){i_name = name; i_price = price; i_amount = amount; l_origin = origin;};

        Beast* getBeast(){return l_origin;};
};

#endif //ITEM_HPP