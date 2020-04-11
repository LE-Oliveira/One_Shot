#include <cstdlib>
#include <iostream>
#include <string>

class personagem{
    public:
        int def, atk, dex, luck, vit, lvl, upgrades, xp, hp;
        char name[20];
};

class creature{
    public:
        int hp, atk, xp, dex, def;
};