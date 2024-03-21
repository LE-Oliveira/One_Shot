#ifndef BEAST_HPP
#define BEAST_HPP
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

class Beast{
    protected:
        int b_hp, b_atk, b_def, b_dex, b_luck, b_xp;
        string b_name;
    public:
        Beast(){};
        Beast(int hp, int atk, int def, int dex, int luck, int xp){b_hp = hp; b_atk = atk; b_def = def; b_dex = dex ;b_luck = luck; b_xp = xp;};
        Beast(string name);

        void setHp(int hp){b_hp = hp;};
        void setAtk(int atk){b_atk = atk;};
        void setDef(int def){b_def = def;};
        void setDex(int dex){b_dex = dex;};
        void setLuck(int luck){b_luck = luck;};
        void setXp(int xp){b_xp = xp;};

        int getHp(){return b_hp;};
        int getAtk(){return b_atk;};
        int getDef(){return b_def;};
        int getDex(){return b_dex;};
        int getLuck(){return b_luck;};
        int getXp(){return b_xp;};
        string getName(){return b_name;};

        void operator - (int damage){b_hp-=damage;};

        ~Beast(){};
};

#endif//BEAST_HPP