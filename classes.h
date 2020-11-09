#include <cstdlib>
#include <iostream>
#include <string>

class item{
    public:
        std::string name;
        int price, amount;
};

class weapon{
    public:
        std::string name;
        int bonus, price, amount;
        bool equiped = false, owned = false;
};

class armour{
    public:
        std::string name;
        int bonus, price, amount;
        bool equiped, owned;
};

class personagem{
    public:
        int def, atk, dex, luck, vit, lvl, upgrades, xp, hp, money;
        weapon weapons[10];
        armour armors[5];
        item items[50];
        char name[20];
};

class creature{
    public:
        int hp, atk, xp, dex, def, luck;
};
